#ifndef CUSTOMERWINDOW_H
#define CUSTOMERWINDOW_H

#include <QDialog>

namespace Ui {
class customerwindow;
}

class customerwindow : public QDialog
{
    Q_OBJECT

public:

    explicit customerwindow(QWidget *parent = nullptr);
    ~customerwindow();



private slots:
    void on_exitbutton_clicked();

    void on_loadcustomersbutton_clicked();

    void on_addcustomerbutton_clicked();

    void on_editcustomerbutton_clicked();

    void on_removecustomerbutton_clicked();

    void on_searchcustomerbutton_clicked();

private:
    Ui::customerwindow *ui;
};

#endif // CUSTOMERWINDOW_H
