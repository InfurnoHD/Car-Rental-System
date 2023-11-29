#ifndef RENTALWINDOW_H
#define RENTALWINDOW_H

#include <QDialog>

namespace Ui {
class rentalwindow;
}

class rentalwindow : public QDialog
{
    Q_OBJECT

public:


    explicit rentalwindow(QWidget *parent = nullptr);
    ~rentalwindow();


private slots:
    void on_exitbutton_clicked();

    void on_loadrentalsbutton_clicked();

    void on_addrentalbutton_clicked();

    void on_removerentalbutton_clicked();


    void on_freshmenubutton_clicked();

    void on_carregbox_textActivated(const QString &arg1);

    void on_customerssbox_textActivated(const QString &arg1);

    void on_carsearchbutton_clicked();

    void on_customersearchbutton_clicked();

private:
    Ui::rentalwindow *ui;
};

#endif // RENTALWINDOW_H
