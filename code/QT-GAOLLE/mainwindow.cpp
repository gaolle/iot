#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    music = new MUSIC(this);
    picture = new PICTURE(this);
    led = new LED(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::beep()
{
    int fd;
    int ret;
    fd = open("/dev/beep_drv", O_RDWR);
    if(fd == -1)
    {
            perror("open beep_drv");
    }
    ret = ioctl(fd, GEC210_BEEP_ON, 1);
    if(ret == -1)
    {
            perror("IOCTL");
    }
    sleep(1);
    ret = ::ioctl(fd, GEC210_BEEP_OFF, 1);
    if(ret == -1)
    {
        ::perror("IOCTL");
    }
    ::close(fd);
}

void MainWindow::on_Picture_Button_clicked()
{
    this->beep();
    this->hide();
    //picture->setWindowState(Qt::WindowMaximized);
    picture->show();
    picture->exec();
    this->show();
}

void MainWindow::on_Led_Button_clicked()
{
    this->beep();
    this->hide();
   // led->setWindowState(Qt::WindowMaximized);
    led->show();
    led->exec();
    this->show();
}

void MainWindow::on_Music_Button_clicked()
{
    this->beep();
    this->hide();
    //music->setWindowState(Qt::WindowMaximized);
    music->show();
    music->exec();
    this->show();
}
