#include "customerwindow.h"
#include "customeredit.h"
#include "qicon.h"
#include "qsqlquery.h"
#include "qsqlquerymodel.h"
#include "ui_customerwindow.h"
#include "sql.h"
#include "customerremove.h"
#include "customersearch.h"

QString customerSSNr = NULL;
QString customerName = NULL;
int customerPhoneNumber = 0;
QString customerEmail = NULL;


customerwindow::customerwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customerwindow)
{
    ui->setupUi(this);
    QString windowTitle("Manage customers");
    this->setWindowTitle(windowTitle);
    QIcon windowIcon(":/pictures/Pictures/icon.png");
    this->setWindowIcon(windowIcon);
}

customerwindow::~customerwindow()
{
    delete ui;
}

void customerwindow::on_exitbutton_clicked()
{
    this->close();
}


void customerwindow::on_loadcustomersbutton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;

    QSqlQuery *query = new QSqlQuery;

    query->prepare("SELECT * FROM customers");
    query->exec();
    model->setQuery(*query);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}


void customerwindow::on_addcustomerbutton_clicked()
{
    customerSSNr = nullptr;
    customerName = nullptr;
    customerPhoneNumber = 0;
    customerEmail = nullptr;

    customerSSNr = ui->ssnrtxt->text();
    customerName = ui->nametxt->text();
    customerPhoneNumber = ui->phonetxt->text().toInt();
    customerEmail = ui->emailtxt->text();

    if (customerSSNr == nullptr || customerName == nullptr || customerPhoneNumber == 0 || customerEmail == nullptr){

        ui->message->setStyleSheet("QLabel {background-color : red;"
                                                "border-style: outset;"
                                                "border-width: 2px;"
                                                "border-radius: 10px;"
                                                "border-color: black;"
                                                "font: bold 14px;"
                                                "min-width: 10em;"
                                                "padding: 6px;}");

        ui->message->setText("Please fill out all fields!");

    }
    else if (checkssnr(customerSSNr)){
        ui->message->setStyleSheet("QLabel {background-color : red;"
                                                "border-style: outset;"
                                                "border-width: 2px;"
                                                "border-radius: 10px;"
                                                "border-color: black;"
                                                "font: bold 14px;"
                                                "min-width: 10em;"
                                                "padding: 6px;}");

        ui->message->setText("Customer already exists!");
    }
    else{


        if(addCustomer(customerSSNr, customerName, customerPhoneNumber, customerEmail)){
            ui->message->setStyleSheet("QLabel {background-color : green;"
                                                    "border-style: outset;"
                                                    "border-width: 2px;"
                                                    "border-radius: 10px;"
                                                    "border-color: black;"
                                                    "font: bold 14px;"
                                                    "min-width: 10em;"
                                                    "padding: 6px;}");

            ui->message->setText("Added customer!");
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

            ui->message->setText("Could not add customer!");
        }

    }
}


void customerwindow::on_editcustomerbutton_clicked()
{
    customeredit customeredit;
    customeredit.setModal(true);
    customeredit.exec();
}


void customerwindow::on_removecustomerbutton_clicked()
{
    customerremove customerremove;
    customerremove.setModal(true);
    customerremove.exec();
}


void customerwindow::on_searchcustomerbutton_clicked()
{
    customersearch customersearch;
    customersearch.setModal(true);
    customersearch.exec();
}

