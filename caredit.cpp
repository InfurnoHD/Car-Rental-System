#include "caredit.h"
#include "ui_caredit.h"
#include "sql.h"

QString carRegNumberUpdate = NULL;
QString carMakeUpdate = NULL;
QString carModelUpdate =  NULL;
int carYearUpdate = 0;

caredit::caredit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::caredit)
{
    ui->setupUi(this);
    QString windowTitle("Edit cars");
    this->setWindowTitle(windowTitle);
    QIcon windowIcon(":/pictures/Pictures/icon.png");
    this->setWindowIcon(windowIcon);
}

caredit::~caredit()
{
    delete ui;
}

void caredit::on_exitbutton_clicked()
{
    this->close();
}


void caredit::on_applybutton_clicked()
{
    carRegNumberUpdate = nullptr;
    carMakeUpdate = nullptr;
    carModelUpdate = nullptr;
    carYearUpdate = 0;

    carRegNumberUpdate = ui->regnrtxt->text();
    carMakeUpdate = ui->maketxt->text();
    carModelUpdate = ui->modeltxt->text();
    carYearUpdate = ui->caryeartxt->text().toInt();

    if (carRegNumberUpdate == nullptr || carMakeUpdate == nullptr || carModelUpdate == nullptr || carYearUpdate == 0){

        ui->caredittransaction->setStyleSheet("QLabel {background-color : red;"
                                                "border-style: outset;"
                                                "border-width: 2px;"
                                                "border-radius: 10px;"
                                                "border-color: black;"
                                                "font: bold 14px;"
                                                "min-width: 10em;"
                                                "padding: 6px;}");

        ui->caredittransaction->setText("Please fill out all fields!");

    }
    else if (!checkregnr(carRegNumberUpdate)){
        ui->caredittransaction->setStyleSheet("QLabel {background-color : red;"
                                                "border-style: outset;"
                                                "border-width: 2px;"
                                                "border-radius: 10px;"
                                                "border-color: black;"
                                                "font: bold 14px;"
                                                "min-width: 10em;"
                                                "padding: 6px;}");

    ui->caredittransaction->setText("Car does not exist!");
    }
    else{

        if(editCar(carRegNumberUpdate, carMakeUpdate, carModelUpdate, carYearUpdate)){
            ui->caredittransaction->setStyleSheet("QLabel {background-color : green;"
                                                    "border-style: outset;"
                                                    "border-width: 2px;"
                                                    "border-radius: 10px;"
                                                    "border-color: black;"
                                                    "font: bold 14px;"
                                                    "min-width: 10em;"
                                                    "padding: 6px;}");

            ui->caredittransaction->setText("Edited make, model and year!");
        }
        else{
            ui->caredittransaction->setStyleSheet("QLabel {background-color : red;"
                                                    "border-style: outset;"
                                                    "border-width: 2px;"
                                                    "border-radius: 10px;"
                                                    "border-color: black;"
                                                    "font: bold 14px;"
                                                    "min-width: 10em;"
                                                    "padding: 6px;}");

            ui->caredittransaction->setText("Could not edit car!");
        }

    }
}


void caredit::on_loadbutton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;

    QSqlQuery *query = new QSqlQuery;

    query->prepare("SELECT * FROM cars");
    query->exec();
    model->setQuery(*query);
    ui->cartable->setModel(model);
    ui->cartable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

