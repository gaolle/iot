#ifndef MUSIC_H
#define MUSIC_H

#include <QDialog>

namespace Ui {
    class MUSIC;
}

class MUSIC : public QDialog
{
    Q_OBJECT

public:
    explicit MUSIC(QWidget *parent = 0);
    ~MUSIC();

private:
    Ui::MUSIC *ui;

private slots:
    void on_pushButton_clicked();
};

#endif // MUSIC_H
