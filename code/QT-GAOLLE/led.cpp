#include "led.h"
#include "ui_led.h"
#include "qicon.h"




LED::LED(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LED)
{
    ui->setupUi(this);
    LED_1_TRUE_FLASE = 0;
    LED_2_TRUE_FLASE = 0;
    LED_3_TRUE_FLASE = 0;
    LED_4_TRUE_FLASE = 0;
}

LED::~LED()
{
    delete ui;
}

void LED::on_push1_clicked()
{
    QIcon led_open_ico(":/image/open_led.jpg");
    QIcon led_close_ico(":/image/close_led.jpg");
    if(LED_1_TRUE_FLASE == 1){
        ui->pushButton->setIcon(led_open_ico);
        ui->pushButton->setIconSize(QSize(100,100));
        ui->pushButton->setFlat(true);
        LED_1_TRUE_FLASE = 0;
        int ret;
        int fd = ::open("/dev/led_drv", O_RDWR);
        if(fd == -1)
        {
                perror("open led_drv");
        }
        ret = ::ioctl(fd, GEC210_LED_ON, 1);
        if(ret == -1)
        {
                ::perror("IOCTL");
        }
        ::close(fd);
    }else{
        ui->pushButton->setIcon(led_close_ico);
        ui->pushButton->setIconSize(QSize(100,100));
        ui->pushButton->setFlat(true);
        LED_1_TRUE_FLASE = 1;
        int ret;
        int fd = ::open("/dev/led_drv", O_RDWR);
        if(fd == -1)
        {
                perror("open led_drv");
        }
        ret = ::ioctl(fd, GEC210_LED_OFF, 1);
        if(ret == -1)
        {
                ::perror("IOCTL");
        }
        ::close(fd);
    }
}

void LED::on_push2_clicked()
{
    QIcon led_open_ico(":/image/open_led.jpg");
    QIcon led_close_ico(":/image/close_led.jpg");
    if(LED_2_TRUE_FLASE == 1){
        ui->pushButton_2->setIcon(led_open_ico);
        ui->pushButton_2->setIconSize(QSize(100,100));
        ui->pushButton_2->setFlat(true);
        LED_2_TRUE_FLASE = 0;
        int ret;
        int fd = ::open("/dev/led_drv", O_RDWR);
        if(fd == -1)
        {
                perror("open led_drv");
        }
        ret = ::ioctl(fd, GEC210_LED_ON, 2);
        if(ret == -1)
        {
                ::perror("IOCTL");
        }
        ::close(fd);
    }else{
        ui->pushButton_2->setIcon(led_close_ico);
        ui->pushButton_2->setIconSize(QSize(100,100));
        ui->pushButton_2->setFlat(true);
        LED_2_TRUE_FLASE = 1;
        int ret;
        int fd = ::open("/dev/led_drv", O_RDWR);
        if(fd == -1)
        {
                perror("open led_drv");
        }
        ret = ::ioctl(fd, GEC210_LED_OFF, 2);
        if(ret == -1)
        {
                ::perror("IOCTL");
        }
        ::close(fd);
    }
}

void LED::on_push3_clicked()
{
    QIcon led_open_ico(":/image/open_led.jpg");
    QIcon led_close_ico(":/image/close_led.jpg");
    if(LED_3_TRUE_FLASE == 1){
        ui->pushButton_3->setIcon(led_open_ico);
        ui->pushButton_3->setIconSize(QSize(100,100));
        ui->pushButton_3->setFlat(true);
        LED_3_TRUE_FLASE = 0;
        int ret;
        int fd = ::open("/dev/led_drv", O_RDWR);
        if(fd == -1)
        {
                perror("open led_drv");
        }
        ret = ::ioctl(fd, GEC210_LED_ON, 3);
        if(ret == -1)
        {
                ::perror("IOCTL");
        }
        ::close(fd);
    }else{
        ui->pushButton_3->setIcon(led_close_ico);
        ui->pushButton_3->setIconSize(QSize(100,100));
        ui->pushButton_3->setFlat(true);
        LED_3_TRUE_FLASE = 1;
        int ret;
        int fd = ::open("/dev/led_drv", O_RDWR);
        if(fd == -1)
        {
                perror("open led_drv");
        }
        ret = ::ioctl(fd, GEC210_LED_OFF, 3);
        if(ret == -1)
        {
                ::perror("IOCTL");
        }
        ::close(fd);
    }
}

void LED::on_push4_clicked()
{
    QIcon led_open_ico(":/image/open_led.jpg");
    QIcon led_close_ico(":/image/close_led.jpg");
    if(LED_4_TRUE_FLASE == 1){
        ui->pushButton_4->setIcon(led_open_ico);
        ui->pushButton_4->setIconSize(QSize(100,100));
        ui->pushButton_4->setFlat(true);
        LED_4_TRUE_FLASE = 0;
        int ret;
        int fd = ::open("/dev/led_drv", O_RDWR);
        if(fd == -1)
        {
                perror("open led_drv");
        }
        ret = ::ioctl(fd, GEC210_LED_ON, 4);
        if(ret == -1)
        {
                ::perror("IOCTL");
        }
        ::close(fd);
    }else{
        ui->pushButton_4->setIcon(led_close_ico);
        ui->pushButton_4->setIconSize(QSize(100,100));
        ui->pushButton_4->setFlat(true);
        LED_4_TRUE_FLASE = 1;
        int ret;
        int fd = ::open("/dev/led_drv", O_RDWR);
        if(fd == -1)
        {
                perror("open led_drv");
        }
        ret = ::ioctl(fd, GEC210_LED_OFF, 4);
        if(ret == -1)
        {
                ::perror("IOCTL");
        }
        ::close(fd);
    }
}
