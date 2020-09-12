#ifndef PICTURE_H
#define PICTURE_H

#include <QDialog>
#include <QTimer>
namespace Ui {
    class PICTURE;
}

class PICTURE : public QDialog
{
    Q_OBJECT

public:
    explicit PICTURE(QWidget *parent = 0);
    ~PICTURE();

private:
    Ui::PICTURE *ui;
    QTimer *time;
    int display_count;
    int stop_display;

private slots:
    void on_pushButton_start_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void autodisplay();
};

#endif // PICTURE_H
