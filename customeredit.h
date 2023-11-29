#ifndef CUSTOMEREDIT_H
#define CUSTOMEREDIT_H

#include <QDialog>

namespace Ui {
class customeredit;
}

class customeredit : public QDialog
{
    Q_OBJECT

public:
    explicit customeredit(QWidget *parent = nullptr);
    ~customeredit();

private slots:
    void on_exitbutton_clicked();

    void on_applybutton_clicked();

    void on_loadbutton_clicked();

private:
    Ui::customeredit *ui;
};

#endif // CUSTOMEREDIT_H
