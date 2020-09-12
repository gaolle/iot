/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *Picture_Button;
    QPushButton *Led_Button;
    QPushButton *Music_Button;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 480);
        MainWindow->setStyleSheet(QString::fromUtf8(" #MainWindow{\n"
"	border-image: url(:/image/start.jpg);\n"
"\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Picture_Button = new QPushButton(centralWidget);
        Picture_Button->setObjectName(QString::fromUtf8("Picture_Button"));
        Picture_Button->setGeometry(QRect(20, 20, 100, 100));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/pop.png"), QSize(), QIcon::Normal, QIcon::On);
        Picture_Button->setIcon(icon);
        Picture_Button->setIconSize(QSize(100, 100));
        Led_Button = new QPushButton(centralWidget);
        Led_Button->setObjectName(QString::fromUtf8("Led_Button"));
        Led_Button->setGeometry(QRect(20, 160, 100, 100));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/open_led.jpg"), QSize(), QIcon::Normal, QIcon::On);
        Led_Button->setIcon(icon1);
        Led_Button->setIconSize(QSize(100, 100));
        Music_Button = new QPushButton(centralWidget);
        Music_Button->setObjectName(QString::fromUtf8("Music_Button"));
        Music_Button->setGeometry(QRect(20, 310, 100, 100));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/music.jpg"), QSize(), QIcon::Normal, QIcon::On);
        Music_Button->setIcon(icon2);
        Music_Button->setIconSize(QSize(100, 100));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QT-GAOLLE", 0, QApplication::UnicodeUTF8));
        Picture_Button->setText(QString());
        Led_Button->setText(QString());
        Music_Button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
