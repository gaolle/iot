#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <music.h>
#include <led.h>
#include <picture.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

#define GEC210_BEEP_ON	_IO('B',1)
#define GEC210_BEEP_OFF	_IO('B',2)

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MUSIC *music;
    PICTURE *picture;
    LED*led;

private slots:
    void on_Music_Button_clicked();
    void on_Led_Button_clicked();
    void on_Picture_Button_clicked();
    void beep();
};

#endif // MAINWINDOW_H
