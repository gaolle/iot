/********************************************************************************
** Form generated from reading UI file 'led.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LED_H
#define UI_LED_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LED
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *push1;
    QPushButton *push2;
    QPushButton *push3;
    QPushButton *push4;

    void setupUi(QDialog *LED)
    {
        if (LED->objectName().isEmpty())
            LED->setObjectName(QString::fromUtf8("LED"));
        LED->resize(800, 480);
        pushButton = new QPushButton(LED);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 80, 100, 100));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/close_led.jpg"), QSize(), QIcon::Normal, QIcon::On);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(100, 100));
        pushButton_2 = new QPushButton(LED);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 80, 100, 100));
        pushButton_2->setIcon(icon);
        pushButton_2->setIconSize(QSize(100, 100));
        pushButton_3 = new QPushButton(LED);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(410, 80, 100, 100));
        pushButton_3->setIcon(icon);
        pushButton_3->setIconSize(QSize(100, 100));
        pushButton_4 = new QPushButton(LED);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(610, 80, 100, 100));
        pushButton_4->setIcon(icon);
        pushButton_4->setIconSize(QSize(100, 100));
        push1 = new QPushButton(LED);
        push1->setObjectName(QString::fromUtf8("push1"));
        push1->setGeometry(QRect(80, 250, 50, 50));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/push.png"), QSize(), QIcon::Normal, QIcon::On);
        push1->setIcon(icon1);
        push1->setIconSize(QSize(50, 50));
        push2 = new QPushButton(LED);
        push2->setObjectName(QString::fromUtf8("push2"));
        push2->setGeometry(QRect(250, 250, 50, 50));
        push2->setIcon(icon1);
        push2->setIconSize(QSize(50, 50));
        push3 = new QPushButton(LED);
        push3->setObjectName(QString::fromUtf8("push3"));
        push3->setGeometry(QRect(440, 250, 50, 50));
        push3->setIcon(icon1);
        push3->setIconSize(QSize(50, 50));
        push4 = new QPushButton(LED);
        push4->setObjectName(QString::fromUtf8("push4"));
        push4->setGeometry(QRect(630, 250, 50, 50));
        push4->setIcon(icon1);
        push4->setIconSize(QSize(50, 50));

        retranslateUi(LED);

        QMetaObject::connectSlotsByName(LED);
    } // setupUi

    void retranslateUi(QDialog *LED)
    {
        LED->setWindowTitle(QApplication::translate("LED", "LED-GAOLLE", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        push1->setText(QString());
        push2->setText(QString());
        push3->setText(QString());
        push4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LED: public Ui_LED {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LED_H
