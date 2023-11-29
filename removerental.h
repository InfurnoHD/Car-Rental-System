#ifndef REMOVERENTAL_H
#define REMOVERENTAL_H

#include <QDialog>

namespace Ui {
class removerental;
}

class removerental : public QDialog
{
    Q_OBJECT

public:
    explicit removerental(QWidget *parent = nullptr);
    ~removerental();

private slots:
    void on_exitbutton_clicked();

    void on_loadrentalsbutton_clicked();

    void on_applybutton_clicked();

    void on_pushButton_clicked();

    void on_carregbox_textActivated(const QString &arg1);

private:
    Ui::removerental *ui;
};

#endif // REMOVERENTAL_H
