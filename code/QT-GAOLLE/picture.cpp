#include "picture.h"
#include "ui_picture.h"



PICTURE::PICTURE(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PICTURE)
{
    ui->setupUi(this);
    display_count = 1;
    stop_display = 0;
    time = new QTimer;
    connect(time, SIGNAL(timeout()), this, SLOT(autodisplay()));
    QIcon music_ico(":/image/music_1.jpg");
    ui->pushButton_start->clearFocus();
    ui->pushButton_start->setIcon(music_ico);
    ui->pushButton_start->setIconSize(QSize(100,100));
    ui->pushButton_start->setFlat(true);

    QIcon left_ico(":/image/left.png");
    ui->pushButton->setIcon(left_ico);
    ui->pushButton->setIconSize(QSize(100,100));
    ui->pushButton->setFlat(true);

    QIcon right_ico(":/image/right.jpg");
    ui->pushButton_2->setIcon(right_ico);
    ui->pushButton_2->setIconSize(QSize(100,100));
    ui->pushButton_2->setFlat(true);

}

PICTURE::~PICTURE()
{
    delete ui;
    delete time;
}

void PICTURE::on_pushButton_clicked()
{
    time->stop();
    QIcon music_ico(":/image/music_1.jpg");
    ui->pushButton_start->clearFocus();
    ui->pushButton_start->setIcon(music_ico);
    ui->pushButton_start->setIconSize(QSize(100,100));
    ui->pushButton_start->setFlat(true);

    if(display_count == 1){
        QPixmap image;
        image.load(":/image/1.jpg");
        ui->label->setScaledContents(true);
        ui->label->clear();
        ui->label->setPixmap(image);
        display_count = 4;
    }else if(display_count == 2){
        QPixmap image;
        image.load(":/image/2.jpg");
        ui->label->setScaledContents(true);
        ui->label->clear();
        ui->label->setPixmap(image);
        display_count = 1;
    }else if(display_count == 3){
            QPixmap image;
            image.load(":/image/3.jpg");
            ui->label->setScaledContents(true);
            ui->label->clear();
            ui->label->setPixmap(image);
            display_count = 2;

        }else if(display_count == 4){
            QPixmap image;
            image.load(":/image/1.gif");
            ui->label->setScaledContents(true);
            ui->label->clear();
            ui->label->setPixmap(image);
            display_count = 3;
        }
}

void PICTURE::on_pushButton_2_clicked()
{
    time->stop();
    QIcon music_ico(":/image/music_1.jpg");
    ui->pushButton_start->clearFocus();
    ui->pushButton_start->setIcon(music_ico);
    ui->pushButton_start->setIconSize(QSize(100,100));
    ui->pushButton_start->setFlat(true);

    if(display_count == 1){
        QPixmap image;
        image.load(":/image/1.jpg");
        ui->label->setScaledContents(true);
        ui->label->clear();
        ui->label->setPixmap(image);
        display_count = 2;
    }else if(display_count == 2){
        QPixmap image;
        image.load(":/image/2.jpg");
        ui->label->setScaledContents(true);
        ui->label->clear();
        ui->label->setPixmap(image);
        display_count = 3;
    }else if(display_count == 3){
            QPixmap image;
            image.load(":/image/3.jpg");
            ui->label->setScaledContents(true);
            ui->label->clear();
            ui->label->setPixmap(image);
            display_count = 4;

        }else if(display_count == 4){
            QPixmap image;
            image.load(":/image/1.gif");
            ui->label->setScaledContents(true);
            ui->label->clear();
            ui->label->setPixmap(image);
            display_count = 1;
        }
}

void PICTURE::autodisplay()
{
    QIcon music_ico(":/image/music.jpg");
    ui->pushButton_start->clearFocus();
    ui->pushButton_start->setIcon(music_ico);
    ui->pushButton_start->setIconSize(QSize(100,100));
    ui->pushButton_start->setFlat(true);
    if(display_count == 1){
        QPixmap image;
        image.load(":/image/1.jpg");
        ui->label->setScaledContents(true);
        ui->label->clear();
        ui->label->setPixmap(image);
        display_count = 2;
    }else if(display_count == 2){
        QPixmap image;
        image.load(":/image/2.jpg");
        ui->label->setScaledContents(true);
        ui->label->clear();
        ui->label->setPixmap(image);
        display_count = 3;
    }else if(display_count == 3){
            QPixmap image;
            image.load(":/image/3.jpg");
            ui->label->setScaledContents(true);
            ui->label->clear();
            ui->label->setPixmap(image);
            display_count = 4;

        }else if(display_count == 4){
            QPixmap image;
            image.load(":/image/1.gif");
            ui->label->setScaledContents(true);
            ui->label->clear();
            ui->label->setPixmap(image);
            display_count = 1;
        }

}

void PICTURE::on_pushButton_start_clicked()
{
     time->start(1000);
}
