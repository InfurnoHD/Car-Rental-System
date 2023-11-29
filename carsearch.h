#ifndef CARSEARCH_H
#define CARSEARCH_H

#include <QDialog>

namespace Ui {
class carsearch;
}

class carsearch : public QDialog
{
    Q_OBJECT

public:
    explicit carsearch(QWidget *parent = nullptr);
    ~carsearch();

private slots:
    void on_exitbutton_clicked();

    void on_searchbutton_clicked();

private:
    Ui::carsearch *ui;
};

#endif // CARSEARCH_H
