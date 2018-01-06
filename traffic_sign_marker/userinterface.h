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

    void wheelEvent(QWheelEvent *event);
    void on_lineEdit_returnPressed();
    void on_toolButton_clicked();
    void on_actionRectangle_triggered();
    void on_actionTriangle_triggered();
    void on_actionCircle_triggered();
    void on_actionSave_next_triggered();
    void on_action_Next_triggered();
    void on_action_Back_triggered();
    void on_openDir();
    void on_openFile();

private:
    Ui::UserInterface *ui;
    QGraphicsScene *scene;
    void LoadFromJson();
    QString pathToDir;
    QPixmap img;
    QStringList fileList;
    QJsonObject linkedJsObj;
    QJsonObject last_opened;
    void SaveLastOpened();
    int listIndex{0};
    QPen greenPen;
    FigureItem *item;
};

#endif // USERINTERFACE_H
