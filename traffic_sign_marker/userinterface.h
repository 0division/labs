#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QStringList>
#include <QDir>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include "figureitem.h"

namespace Ui
{
    class UserInterface;
}

class UserInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserInterface(QWidget *parent = 0);
    ~UserInterface();

private slots:

    void keyPressEvent(QKeyEvent *event);
    void wheelEvent(QWheelEvent *event);
    void on_lineEdit_returnPressed();


private:
    Ui::UserInterface *ui;
    QGraphicsScene *scene;
    void LoadFromJson();
    QString pathToDir;
    QPixmap img;
    QStringList fileList;
    QJsonObject linkedJsObj;
    QJsonObject last_opened;
    int listIndex;
    QPen redPen;
    FigureItem *item;
};

#endif // USERINTERFACE_H
