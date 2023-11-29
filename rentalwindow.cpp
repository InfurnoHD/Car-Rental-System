#include "rentalwindow.h"
#include "qicon.h"
#include "qsqlquery.h"
#include "qsqlquerymodel.h"
#include "ui_rentalwindow.h"
#include "sql.h"
#include "removerental.h"
#include "carsearch.h"
#include "customersearch.h"

QString carRegNumberRental;
QString customerSSNrNumberRental;

rentalwindow::rentalwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rentalwindow)
{
    ui->setupUi(this);
    QString windowTitle("Manage Rentals");
    this->setWindowTitle(windowTitle);
    QIcon windowIcon(":/pictures/Pictures/icon.png");
    this->setWindowIcon(windowIcon);
}

rentalwindow::~rentalwindow()
{
    delete ui;
}

void rentalwindow::on_exitbutton_clicked()
{
    this->close();
}


void rentalwindow::on_loadrentalsbutton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;

    QSqlQuery *query = new QSqlQuery;

    query->prepare("SELECT * FROM rentals");
    query->exec();
    model->setQuery(*query);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}


void rentalwindow::on_addrentalbutton_clicked()
{


    if (carRegNumberRental == nullptr || customerSSNrNumberRental == nullptr){

        ui->message->setStyleSheet("QLabel {background-color : red;"
                                                "border-style: outset;"
                                                "border-width: 2px;"
                                                "border-radius: 10px;"
                                                "border-color: black;"
                                                "font: bold 14px;"
                                                "min-width: 10em;"
                                                "padding: 6px;}");

        ui->message->setText("Please choose a customer and a car!");

    }
    else if (!checkregnr(carRegNumberRental)){
        ui->message->setStyleSheet("QLabel {background-color : red;"
                                                "border-style: outset;"
                                                "border-width: 2px;"
                                                "border-radius: 10px;"
                                                "border-color: black;"
                                                "font: bold 14px;"
                                                "min-width: 10em;"
                                                "padding: 6px;}");

        ui->message->setText("Car does not exist!");
    }
    else if (checkregnrrental(carRegNumberRental)){
        ui->message->setStyleSheet("QLabel {background-color : red;"
                                                "border-style: outset;"
                                                "border-width: 2px;"
                                                "border-radius: 10px;"
                                                "border-color: black;"
                                                "font: bold 14px;"
                                                "min-width: 10em;"
                                                "padding: 6px;}");

        ui->message->setText("Car is already rented!");
    }
    else if (!checkssnr(customerSSNrNumberRental)){
        ui->message->setStyleSheet("QLabel {background-color : red;"
                                                "border-style: outset;"
                                                "border-width: 2px;"
                                                "border-radius: 10px;"
                                                "border-color: black;"
                                                "font: bold 14px;"
                                                "min-width: 10em;"
                                                "padding: 6px;}");

        ui->message->setText("Customer does not exist!");
    }
    else{


        if(addRental(carRegNumberRental, customerSSNrNumberRental) == true){
            ui->message->setStyleSheet("QLabel {background-color : green;"
                                                    "border-style: outset;"
                                                    "border-width: 2px;"
                                                    "border-radius: 10px;"
                                                    "border-color: black;"
                                                    "font: bold 14px;"
                                                    "min-width: 10em;"
                                                    "padding: 6px;}");

            ui->message->setText("Added rental!");
        }
        else{
            ui->message->setStyleSheet("QLabel {background-color : red;"
                                                    "border-style: outset;"
                                                    "border-width: 2px;"
                                                    "border-radius: 10px;"
                                                    "border-color: black;"
                                                    "font: bold 14px;"
                                                    "min-width: 10em;"
                                                    "padding: 6px;}");

            ui->message->setText("Could not add rental!");
        }

    }
}


void rentalwindow::on_removerentalbutton_clicked()
{
    removerental removerental;
    removerental.setModal(true);
    removerental.exec();
}





void rentalwindow::on_freshmenubutton_clicked()
{

    carRegNumberRental = nullptr;
    customerSSNrNumberRental = nullptr;

    QSqlQueryModel *carmodel = new QSqlQueryModel;
    QSqlQueryModel *cusmodel = new QSqlQueryModel;

    QSqlQuery carquery;
    QSqlQuery cusquery;

    cusquery.prepare("SELECT customerSSNr FROM customers");
    cusquery.exec();
    cusmodel->setQuery(cusquery);
    ui->customerssbox->setModel(cusmodel);

    carquery.prepare("SELECT carRegNumber FROM cars");
    carquery.exec();
    carmodel->setQuery(carquery);
    ui->carregbox->setModel(carmodel);
}


void rentalwindow::on_carregbox_textActivated(const QString &arg1)
{
    carRegNumberRental = arg1;

}


void rentalwindow::on_customerssbox_textActivated(const QString &arg1)
{
    customerSSNrNumberRental = arg1;
}


void rentalwindow::on_carsearchbutton_clicked()
{
    carsearch carsearch;
    carsearch.setModal(true);
    carsearch.exec();
}




void rentalwindow::on_customersearchbutton_clicked()
{
    customersearch customersearch;
    customersearch.setModal(true);
    customersearch.exec();
}

