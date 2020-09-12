#include "music.h"
#include "ui_music.h"

MUSIC::MUSIC(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MUSIC)
{
    ui->setupUi(this);
}

MUSIC::~MUSIC()
{
    delete ui;
}

void MUSIC::on_pushButton_clicked()
{
    ::system("madplay ./test.mp3& -r");
}
