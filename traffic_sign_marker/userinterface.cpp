#include "userinterface.h"
#include "ui_userinterface.h"
#include <QFileDialog>

UserInterface::UserInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserInterface)
{
    ui->setupUi(this);
    this->setFixedSize(280,350);
    ui->graphicsView->setFixedSize(256,256);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,128,128);
    ui->graphicsView->setScene(scene);

    greenPen.setColor(Qt::green);
    greenPen.setWidth(2);
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

        item->SetPen(greenPen);
        item->SetShape(linkedJsObj["shape"].toInt());
        item->SetPos(linkedJsObj["x"].toDouble(), linkedJsObj["y"].toDouble());
        QList<double> pointList;
        for(int i = 0; i< 8; i++){
            pointList.append(linkedJsObj["p"+QString::number(i)].toDouble());
        }
        item->SetPolygon(pointList);
        scene->addItem(item);
        item->rotation = linkedJsObj["rotation"].toDouble();
        ui->graphicsView->items().at(0)->setTransformOriginPoint(item->boundingRect().center());
        scene->items().at(0)->setRotation(item->rotation);
        connect(item,SIGNAL(itemResized()),scene,SLOT(update()));
        scene->update();
    }else{
        scene->addPixmap(img);
    }
}

void UserInterface::SaveLastOpened()
{
    QFile jFile(qApp->applicationDirPath()+ "/last_opened.json");
    if(jFile.exists())
    {
        jFile.open(QIODevice::ReadOnly | QIODevice::Text);
        QByteArray rawData = jFile.readAll();
        QJsonDocument jDoc(QJsonDocument::fromJson(rawData));
        last_opened = jDoc.object();
        jFile.close();

        last_opened[pathToDir] = fileList.at(listIndex);

        jFile.open(QIODevice::WriteOnly | QIODevice::Text);
        jDoc.setObject(last_opened);
        jFile.write(jDoc.toJson(QJsonDocument::Indented));
        jFile.close();
    }else{
        jFile.open(QIODevice::WriteOnly | QIODevice::Text);
        last_opened[pathToDir] = fileList.at(listIndex);
        QJsonDocument jDoc(last_opened);
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
    if(event->modifiers().testFlag(Qt::AltModifier) && ui->graphicsView->items().size()>1)
    {
        ui->graphicsView->items().at(0)->setTransformOriginPoint(item->boundingRect().center());
        if(event->delta()>0)
        {
             item->rotation+=0.5;
        }else
        {
             item->rotation-=0.5;
        }
        ui->graphicsView->items().at(0)->setRotation(item->rotation);
    }
}

void UserInterface::on_lineEdit_returnPressed()
{

    listIndex = 0;
    pathToDir = ui->lineEdit->text();
    QFileInfo startFile(pathToDir);
    scene->clear();
    if(startFile.isFile()){
        ui->graphicsView->setFocus();
        fileList = QDir(pathToDir.left(pathToDir.lastIndexOf('/'))).entryList(QDir::Files);
        listIndex = fileList.indexOf(pathToDir.right(pathToDir.size() - pathToDir.lastIndexOf('/') - 1));

        if(!img.load(pathToDir)){
            ui->label->setStyleSheet("QLabel { background-color : red; color : blue; }");
        }else{
            pathToDir.remove(pathToDir.lastIndexOf('/')+1,pathToDir.size());
            LoadFromJson();
        }


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
    SaveLastOpened();
}


void UserInterface::on_openDir()
{
    QFileDialog dialog(this);
    ui->lineEdit->setText(dialog.getExistingDirectory());
    ui->lineEdit->returnPressed();
}

void UserInterface::on_openFile()
{
    QFileDialog dialog(this);
    ui->lineEdit->setText(dialog.getOpenFileName());
    ui->lineEdit->returnPressed();
}

void UserInterface::on_toolButton_clicked()
{
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    QMenu contextMenu(this);
    QAction openDir("Open Directory",this);
    connect(&openDir, SIGNAL(triggered()), this, SLOT(on_openDir()));
    QAction openFile("Open File",this);
    connect(&openFile, SIGNAL(triggered()), this, SLOT(on_openFile()));
    contextMenu.addAction(&openDir);
    contextMenu.addAction(&openFile);
    contextMenu.exec(mapToGlobal(ui->toolButton->pos()));
}

void UserInterface::on_actionRectangle_triggered()
{
    if(scene->items().size()!=0)
    {
        scene->clear();
        scene->addPixmap(img);
        item = new FigureItem();
        item->SetPen(greenPen);
        item->SetShape(1);
        connect(item,SIGNAL(itemResized()),scene,SLOT(update()));
        scene->addItem(item);
        linkedJsObj["shape"]=1;
    }
}

void UserInterface::on_actionTriangle_triggered()
{
    if(scene->items().size()!=0)
    {
        scene->clear();
        scene->addPixmap(img);
        item = new FigureItem();
        item->SetPen(greenPen);
        item->SetShape(2);
        connect(item,SIGNAL(itemResized()),scene,SLOT(update()));
        scene->addItem(item);
        linkedJsObj["shape"]=2;
    }
}

void UserInterface::on_actionCircle_triggered()
{
    if(scene->items().size()!=0)
    {
        scene->clear();
        scene->addPixmap(img);
        item = new FigureItem();
        item->SetPen(greenPen);
        item->SetShape(3);
        connect(item,SIGNAL(itemResized()),scene,SLOT(update()));
        scene->addItem(item);
        linkedJsObj["shape"]=3;
    }
}

void UserInterface::on_actionSave_next_triggered()
{
    if(scene->items().size()>1){
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
        linkedJsObj["rotation"]=item->rotation;
        QJsonDocument jDoc(linkedJsObj);
        QFile jFile(jDir.path() + "/" + fileList.at(listIndex)+".json");
        jFile.open(QIODevice::WriteOnly | QIODevice::Text);
        jFile.write(jDoc.toJson(QJsonDocument::Indented));
        jFile.close();

        ui->action_Next->trigger();
    }
}

void UserInterface::on_action_Next_triggered()
{
    if(fileList.size()>listIndex+1)
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

        SaveLastOpened();
    }
}

void UserInterface::on_action_Back_triggered()
{
    if(listIndex>0)
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

        SaveLastOpened();
    }
}
