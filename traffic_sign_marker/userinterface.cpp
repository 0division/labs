#include "userinterface.h"
#include "ui_userinterface.h"

UserInterface::UserInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserInterface)
{
    ui->setupUi(this);
    this->setFixedSize(258,350);
    ui->graphicsView->setFixedSize(258,258);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,128,128);
    ui->graphicsView->setScene(scene);
    redPen.setColor(Qt::red);
    redPen.setWidth(2);
    scene->addRect(scene->sceneRect());
}

UserInterface::~UserInterface()
{
    delete ui;
}

void UserInterface::LoadFromJson(){
    QFile jFile(pathToDir + "/json/" + fileList.at(listIndex)+".json");
    if(jFile.exists()){
        jFile.open(QIODevice::ReadOnly | QIODevice::Text);
        QByteArray rawData = jFile.readAll();
        QJsonDocument jDoc(QJsonDocument::fromJson(rawData));
        linkedJsObj = jDoc.object();
        jFile.close();

        scene->addPixmap(img);
        item = new FigureItem();
        item->SetPen(redPen);
        item->SetShape(linkedJsObj["shape"].toInt());
        item->SetPos(linkedJsObj["x"].toDouble(), linkedJsObj["y"].toDouble());
        QList<double> pointList;
        for(int i = 0; i< 8; i++){
            pointList.append(linkedJsObj["p"+QString::number(i)].toDouble());
        }
        item->SetPolygon(pointList);
        scene->addItem(item);
    }else{
        scene->addPixmap(img);
    }
}


void UserInterface::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_1 && scene->items().size()!=0)
    {
        scene->clear();
        scene->addPixmap(img);
        item = new FigureItem();
        item->SetPen(redPen);
        item->SetShape(1);
        scene->addItem(item);
        linkedJsObj["shape"]=1;
    }

    if(event->key() == Qt::Key_2 && scene->items().size()!=0)
    {
        scene->clear();
        scene->addPixmap(img);
        item = new FigureItem();
        item->SetPen(redPen);
        item->SetShape(2);
        scene->addItem(item);
        linkedJsObj["shape"]=2;
    }

    if(event->key() == Qt::Key_3 && scene->items().size()!=0)
    {
        scene->clear();
        scene->addPixmap(img);
        item = new FigureItem();
        item->SetPen(redPen);
        item->SetShape(3);
        scene->addItem(item);
        linkedJsObj["shape"]=3;
    }

    if(event->key() == Qt::Key_C && fileList.size()>listIndex+1)
    {
        scene->clear();
        ui->label->setStyleSheet("");

        listIndex++;

        if(!img.load(pathToDir+fileList.at(listIndex))) {
            ui->label->setStyleSheet("QLabel { background-color : red; color : blue; }");
        }else{
            LoadFromJson();
        }

        ui->label->setText(QString::number(listIndex) + ": " +fileList.at(listIndex));

        last_opened[pathToDir] = fileList.at(listIndex);
        QJsonDocument jDoc(last_opened);
        QFile jFile(qApp->applicationDirPath()+ "/last_opened.json");
        jFile.open(QIODevice::WriteOnly | QIODevice::Text);
        jFile.write(jDoc.toJson(QJsonDocument::Indented));
        jFile.close();

    }

    if(event->key() == Qt::Key_Z && listIndex>0)
    {
        scene->clear();
        ui->label->setStyleSheet("");

        listIndex--;
        if(!img.load(pathToDir+fileList.at(listIndex))) {
            ui->label->setStyleSheet("QLabel { background-color : red; color : blue; }");
        }else{
            LoadFromJson();
        }
        ui->label->setText(fileList.at(listIndex));
        ui->label->setText(QString::number(listIndex));

        ui->label->setText(QString::number(listIndex) + ": " +fileList.at(listIndex));

        QJsonDocument jDoc(last_opened);
        QFile jFile(qApp->applicationDirPath()+ "/last_opened.json");
        jFile.open(QIODevice::WriteOnly | QIODevice::Text);
        jFile.write(jDoc.toJson(QJsonDocument::Indented));
        jFile.close();
    }

    if(event->key() == Qt::Key_S && scene->items().size()>1)
    {
        QDir jDir(pathToDir+"json");
        if (!jDir.exists()) {
            jDir.mkpath(".");
        }

        QList<double> pointList = item->GetPolygon();
        for(int i = 0; i<8; i++){
            linkedJsObj["p"+QString::number(i)] = pointList.at(i);
        }
        linkedJsObj["x"]=item->GetPos().x();
        linkedJsObj["y"]=item->GetPos().y();

        QJsonDocument jDoc(linkedJsObj);
        QFile jFile(jDir.path() + "/" + fileList.at(listIndex)+".json");
        jFile.open(QIODevice::WriteOnly | QIODevice::Text);
        jFile.write(jDoc.toJson(QJsonDocument::Indented));
        jFile.close();

    }
}

void UserInterface::wheelEvent(QWheelEvent *event)
{
    if(event->modifiers().testFlag(Qt::ControlModifier))
    {
        if(event->delta()>0)
        {
            ui->graphicsView->scale(1.2,1.2);
        }else
        {
            ui->graphicsView->scale(0.8,0.8);
        }
    }
}

void UserInterface::on_lineEdit_returnPressed()
{
    listIndex = 0;
    pathToDir = ui->lineEdit->text();
    QFileInfo startFile(pathToDir);

    if(startFile.isFile()){
        ui->graphicsView->setFocus();
        fileList = QDir(pathToDir.left(pathToDir.lastIndexOf('/'))).entryList(QDir::Files);
        listIndex = fileList.indexOf(pathToDir.right(pathToDir.size() - pathToDir.lastIndexOf('/') - 1));

        if(!img.load(pathToDir)){
            ui->label->setStyleSheet("QLabel { background-color : red; color : blue; }");
        }else{
            LoadFromJson();
        }
        pathToDir.remove(pathToDir.lastIndexOf('/')+1,pathToDir.size());

        ui->label->setText(QString::number(listIndex) + ": " +fileList.at(listIndex));
    }else{
        if(!pathToDir.endsWith('/')){
            pathToDir.append('/');
        }
        if(QDir(pathToDir).exists())
        {
            fileList = QDir(pathToDir).entryList(QDir::Files);
            ui->graphicsView->setFocus();

            QFile jFile(qApp->applicationDirPath()+ "/last_opened.json");
            if(jFile.exists())
            {
                jFile.open(QIODevice::ReadOnly | QIODevice::Text);
                QByteArray rawData = jFile.readAll();
                QJsonDocument jDoc(QJsonDocument::fromJson(rawData));
                last_opened = jDoc.object();
                jFile.close();
                if(!last_opened[pathToDir].isNull() && fileList.contains(last_opened[pathToDir].toString()))
                {
                    listIndex = fileList.indexOf(last_opened[pathToDir].toString());
                }
            }

            if(!img.load(pathToDir+fileList.at(listIndex))) {
                ui->label->setStyleSheet("QLabel { background-color : red; color : blue; }");
            }else{
                LoadFromJson();
            }
            ui->label->setText(QString::number(listIndex) + ": " +fileList.at(listIndex));
        }else{
            ui->label->setStyleSheet("QLabel { background-color : red; color : blue; }");
            ui->label->setText("ERROR: Directory doesn't exist.");
        }
    }
}
