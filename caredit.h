#ifndef CAREDIT_H
#define CAREDIT_H

#include <QDialog>

namespace Ui {
class caredit;
}

class caredit : public QDialog
{
    Q_OBJECT

public:
    explicit caredit(QWidget *parent = nullptr);
    ~caredit();



private slots:
    void on_exitbutton_clicked();

    void on_applybutton_clicked();


    void on_loadbutton_clicked();

private:
    Ui::caredit *ui;
};

#endif // CAREDIT_H
