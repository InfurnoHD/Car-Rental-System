#include "carwindow.h"
#include "carremove.h"
#include "qicon.h"
#include "ui_carwindow.h"
#include "sql.h"
#include "caredit.h"
#include "carsearch.h"

QString carRegNumber = NULL;
QString carMake = NULL;
QString carModel =  NULL;
int carYear = 0;


carwindow::carwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::carwindow)
{
    ui->setupUi(this);
    QString windowTitle("Manage cars");
    this->setWindowTitle(windowTitle);
    QIcon windowIcon(":/pictures/Pictures/icon.png");
    this->setWindowIcon(windowIcon);
}

carwindow::~carwindow()
{
    delete ui;
}

void carwindow::on_addcarbutton_clicked()
{
    carRegNumber = nullptr;
    carMake = nullptr;
    carModel = nullptr;
    carYear = 0;

    carRegNumber = ui->regnrtxt->text();
    carMake = ui->carmaketxt->text();
    carModel = ui->carmodeltxt->text();
    carYear = ui->caryeartxt->text().toInt();

    if (carRegNumber == nullptr || carMake == nullptr || carModel == nullptr || carYear == 0){

        ui->cartransactionoutput->setStyleSheet("QLabel {background-color : red;"
                                                "border-style: outset;"
                                                "border-width: 2px;"
                                                "border-radius: 10px;"
                                                "border-color: black;"
                                                "font: bold 14px;"
                                                "min-width: 10em;"
                                                "padding: 6px;}");

        ui->cartransactionoutput->setText("Please fill out all fields!");

    }
    else if (checkregnr(carRegNumber)){
        ui->cartransactionoutput->setStyleSheet("QLabel {background-color : red;"
                                                "border-style: outset;"
                                                "border-width: 2px;"
                                                "border-radius: 10px;"
                                                "border-color: black;"
                                                "font: bold 14px;"
                                                "min-width: 10em;"
                                                "padding: 6px;}");

        ui->cartransactionoutput->setText("Car already exists!");
    }
    else{


        if(addCar(carRegNumber, carMake, carModel, carYear)){
            ui->cartransactionoutput->setStyleSheet("QLabel {background-color : green;"
                                                    "border-style: outset;"
                                                    "border-width: 2px;"
                                                    "border-radius: 10px;"
                                                    "border-color: black;"
                                                    "font: bold 14px;"
                                                    "min-width: 10em;"
                                                    "padding: 6px;}");

            ui->cartransactionoutput->setText("Added car!");
        }
        else{
            ui->cartransactionoutput->setStyleSheet("QLabel {background-color : red;"
                                                    "border-style: outset;"
                                                    "border-width: 2px;"
                                                    "border-radius: 10px;"
                                                    "border-color: black;"
                                                    "font: bold 14px;"
                                                    "min-width: 10em;"
                                                    "padding: 6px;}");

            ui->cartransactionoutput->setText("Could not add car!");
        }

    }
}



void carwindow::on_editcarbutton_clicked()
{
    caredit caredit;
    caredit.setModal(true);
    caredit.exec();

}


void carwindow::on_pushButton_clicked()
{
    this->close();
}


void carwindow::on_removecarbutton_clicked()
{
    carremove carremove;
    carremove.setModal(true);
    carremove.exec();
}


void carwindow::on_loadcars_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;

    QSqlQuery *query = new QSqlQuery;

    query->prepare("SELECT * FROM cars");
    query->exec();
    model->setQuery(*query);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}


void carwindow::on_searchcarbutton_clicked()
{
    carsearch carsearch;
    carsearch.setModal(true);
    carsearch.exec();
}

