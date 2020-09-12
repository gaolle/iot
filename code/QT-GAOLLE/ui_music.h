/********************************************************************************
** Form generated from reading UI file 'music.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSIC_H
#define UI_MUSIC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MUSIC
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *MUSIC)
    {
        if (MUSIC->objectName().isEmpty())
            MUSIC->setObjectName(QString::fromUtf8("MUSIC"));
        MUSIC->resize(800, 480);
        pushButton = new QPushButton(MUSIC);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 50, 201, 201));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/music.jpg"), QSize(), QIcon::Normal, QIcon::On);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(200, 200));

        retranslateUi(MUSIC);

        QMetaObject::connectSlotsByName(MUSIC);
    } // setupUi

    void retranslateUi(QDialog *MUSIC)
    {
        MUSIC->setWindowTitle(QApplication::translate("MUSIC", "MUSIC-GAOLLE", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MUSIC: public Ui_MUSIC {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSIC_H
