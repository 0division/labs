/********************************************************************************
** Form generated from reading UI file 'userinterface.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINTERFACE_H
#define UI_USERINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserInterface
{
public:
    QAction *actionRectangle;
    QAction *actionTriangle;
    QAction *actionCircle;
    QAction *actionSave_next;
    QAction *action_Next;
    QAction *action_Back;
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton;
    QLineEdit *lineEdit;
    QMenuBar *menuBar;
    QMenu *menuWatch_hotkeys;

    void setupUi(QMainWindow *UserInterface)
    {
        if (UserInterface->objectName().isEmpty())
            UserInterface->setObjectName(QStringLiteral("UserInterface"));
        UserInterface->resize(325, 386);
        actionRectangle = new QAction(UserInterface);
        actionRectangle->setObjectName(QStringLiteral("actionRectangle"));
        actionTriangle = new QAction(UserInterface);
        actionTriangle->setObjectName(QStringLiteral("actionTriangle"));
        actionCircle = new QAction(UserInterface);
        actionCircle->setObjectName(QStringLiteral("actionCircle"));
        actionSave_next = new QAction(UserInterface);
        actionSave_next->setObjectName(QStringLiteral("actionSave_next"));
        action_Next = new QAction(UserInterface);
        action_Next->setObjectName(QStringLiteral("action_Next"));
        action_Back = new QAction(UserInterface);
        action_Back->setObjectName(QStringLiteral("action_Back"));
        centralWidget = new QWidget(UserInterface);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 40, 256, 256));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setLayoutDirection(Qt::LeftToRight);
        graphicsView->setFrameShape(QFrame::NoFrame);
        graphicsView->setFrameShadow(QFrame::Plain);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        graphicsView->setResizeAnchor(QGraphicsView::AnchorViewCenter);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 310, 251, 17));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 10, 261, 31));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        toolButton = new QToolButton(widget);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        horizontalLayout->addWidget(toolButton);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMaximumSize(QSize(300, 16777215));
        lineEdit->setBaseSize(QSize(128, 15));

        horizontalLayout->addWidget(lineEdit);

        UserInterface->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(UserInterface);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 325, 23));
        menuWatch_hotkeys = new QMenu(menuBar);
        menuWatch_hotkeys->setObjectName(QStringLiteral("menuWatch_hotkeys"));
        UserInterface->setMenuBar(menuBar);

        menuBar->addAction(menuWatch_hotkeys->menuAction());
        menuWatch_hotkeys->addAction(actionRectangle);
        menuWatch_hotkeys->addAction(actionTriangle);
        menuWatch_hotkeys->addAction(actionCircle);
        menuWatch_hotkeys->addAction(actionSave_next);
        menuWatch_hotkeys->addAction(action_Next);
        menuWatch_hotkeys->addAction(action_Back);

        retranslateUi(UserInterface);

        QMetaObject::connectSlotsByName(UserInterface);
    } // setupUi

    void retranslateUi(QMainWindow *UserInterface)
    {
        UserInterface->setWindowTitle(QApplication::translate("UserInterface", "Traffic Sign Marker", 0));
        actionRectangle->setText(QApplication::translate("UserInterface", "Rectangle", 0));
        actionRectangle->setShortcut(QApplication::translate("UserInterface", "1", 0));
        actionTriangle->setText(QApplication::translate("UserInterface", "Triangle", 0));
#ifndef QT_NO_TOOLTIP
        actionTriangle->setToolTip(QApplication::translate("UserInterface", "Triangle", 0));
#endif // QT_NO_TOOLTIP
        actionTriangle->setShortcut(QApplication::translate("UserInterface", "2", 0));
        actionCircle->setText(QApplication::translate("UserInterface", "Circle", 0));
#ifndef QT_NO_TOOLTIP
        actionCircle->setToolTip(QApplication::translate("UserInterface", "Circle", 0));
#endif // QT_NO_TOOLTIP
        actionCircle->setShortcut(QApplication::translate("UserInterface", "3", 0));
        actionSave_next->setText(QApplication::translate("UserInterface", "Save+Next", 0));
#ifndef QT_NO_TOOLTIP
        actionSave_next->setToolTip(QApplication::translate("UserInterface", "Save+Next", 0));
#endif // QT_NO_TOOLTIP
        actionSave_next->setShortcut(QApplication::translate("UserInterface", "S", 0));
        action_Next->setText(QApplication::translate("UserInterface", "Next", 0));
#ifndef QT_NO_TOOLTIP
        action_Next->setToolTip(QApplication::translate("UserInterface", "Next", 0));
#endif // QT_NO_TOOLTIP
        action_Next->setShortcut(QApplication::translate("UserInterface", "C", 0));
        action_Back->setText(QApplication::translate("UserInterface", "Back", 0));
#ifndef QT_NO_TOOLTIP
        action_Back->setToolTip(QApplication::translate("UserInterface", "Back", 0));
#endif // QT_NO_TOOLTIP
        action_Back->setShortcut(QApplication::translate("UserInterface", "Z", 0));
        label->setText(QApplication::translate("UserInterface", "Welcome to TrafficSignMarker", 0));
        toolButton->setText(QApplication::translate("UserInterface", "...", 0));
        lineEdit->setText(QString());
        menuWatch_hotkeys->setTitle(QApplication::translate("UserInterface", "Watch hotkeys", 0));
    } // retranslateUi

};

namespace Ui {
    class UserInterface: public Ui_UserInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINTERFACE_H
