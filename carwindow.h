#ifndef CARWINDOW_H
#define CARWINDOW_H

#include <QDialog>

namespace Ui {
class carwindow;
}

class carwindow : public QDialog
{
    Q_OBJECT

public:

    explicit carwindow(QWidget *parent = nullptr);
    ~carwindow();



private slots:
    void on_addcarbutton_clicked();

    void on_editcarbutton_clicked();

    void on_pushButton_clicked();

    void on_removecarbutton_clicked();

    void on_loadcars_clicked();

    void on_searchcarbutton_clicked();

private:
    Ui::carwindow *ui;
};

#endif // CARWINDOW_H
