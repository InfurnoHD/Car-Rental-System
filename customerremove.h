#ifndef CUSTOMERREMOVE_H
#define CUSTOMERREMOVE_H

#include <QDialog>

namespace Ui {
class customerremove;
}

class customerremove : public QDialog
{
    Q_OBJECT

public:
    explicit customerremove(QWidget *parent = nullptr);
    ~customerremove();

private slots:
    void on_exitbutton_clicked();

    void on_loadbutton_clicked();

    void on_applybutton_clicked();

private:
    Ui::customerremove *ui;
};

#endif // CUSTOMERREMOVE_H
