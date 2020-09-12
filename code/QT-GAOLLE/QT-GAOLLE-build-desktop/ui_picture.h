/********************************************************************************
** Form generated from reading UI file 'picture.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICTURE_H
#define UI_PICTURE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PICTURE
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_start;

    void setupUi(QDialog *PICTURE)
    {
        if (PICTURE->objectName().isEmpty())
            PICTURE->setObjectName(QString::fromUtf8("PICTURE"));
        PICTURE->setEnabled(true);
        PICTURE->resize(800, 480);
        label = new QLabel(PICTURE);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 20, 600, 281));
        pushButton = new QPushButton(PICTURE);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 340, 100, 100));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/left.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(100, 100));
        pushButton_2 = new QPushButton(PICTURE);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(true);
        pushButton_2->setGeometry(QRect(570, 340, 100, 100));
#ifndef QT_NO_ACCESSIBILITY
        pushButton_2->setAccessibleDescription(QString::fromUtf8(""));
#endif // QT_NO_ACCESSIBILITY
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/right.jpg"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(100, 100));
        pushButton_start = new QPushButton(PICTURE);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setGeometry(QRect(340, 340, 100, 100));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/music_1.jpg"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_start->setIcon(icon2);
        pushButton_start->setIconSize(QSize(100, 100));

        retranslateUi(PICTURE);

        QMetaObject::connectSlotsByName(PICTURE);
    } // setupUi

    void retranslateUi(QDialog *PICTURE)
    {
        PICTURE->setWindowTitle(QApplication::translate("PICTURE", "PICTURE-GAOLLE", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_start->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PICTURE: public Ui_PICTURE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICTURE_H
