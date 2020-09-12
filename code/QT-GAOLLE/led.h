#ifndef LED_H
#define LED_H

#include <QDialog>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

#define GEC210_LED_ON	_IOW('L',1,unsigned int)
#define GEC210_LED_OFF	_IOW('L',2,unsigned int)

namespace Ui {
    class LED;
}

class LED : public QDialog
{
    Q_OBJECT

public:
    explicit LED(QWidget *parent = 0);
    ~LED();


private:
    Ui::LED *ui;
    int LED_1_TRUE_FLASE;
    int LED_2_TRUE_FLASE;
    int LED_3_TRUE_FLASE;
    int LED_4_TRUE_FLASE;


private slots:
    void on_push4_clicked();
    void on_push3_clicked();
    void on_push2_clicked();
    void on_push1_clicked();
};

#endif // LED_H
