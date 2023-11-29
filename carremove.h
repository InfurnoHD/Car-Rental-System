#ifndef CARREMOVE_H
#define CARREMOVE_H

#include <QDialog>

namespace Ui {
class carremove;
}

class carremove : public QDialog
{
    Q_OBJECT

public:
    explicit carremove(QWidget *parent = nullptr);
    ~carremove();

private slots:
    void on_loadbutton_clicked();

    void on_exitbutton_clicked();

    void on_applybutton_clicked();

private:
    Ui::carremove *ui;
};

#endif // CARREMOVE_H
