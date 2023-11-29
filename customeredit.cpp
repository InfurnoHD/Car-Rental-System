#include "customeredit.h"
#include "ui_customeredit.h"
#include "sql.h"

QString customerSSNrUpdate = NULL;
QString customerNameUpdate = NULL;
int customerPhoneNumberUpdate =  0;
QString customerEmailUpdate = NULL;

customeredit::customeredit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customeredit)
{
    ui->setupUi(this);

    QString windowTitle("Edit customers");
    this->setWindowTitle(windowTitle);
    QIcon windowIcon(":/pictures/Pictures/icon.png");
    this->setWindowIcon(windowIcon);
}

customeredit::~customeredit()
{
    delete ui;
}

void customeredit::on_exitbutton_clicked()
{
    this->close();
}


void customeredit::on_applybutton_clicked()
{
    customerSSNrUpdate = nullptr;
    customerNameUpdate = nullptr;
    customerPhoneNumberUpdate = 0;
    customerEmailUpdate = nullptr;

    customerSSNrUpdate = ui->ssnrtxt->text();
    customerNameUpdate = ui->nametxt->text();
    customerPhoneNumberUpdate = ui->phonetxt->text().toInt();
    customerEmailUpdate = ui->emailtxt->text();

    if (customerSSNrUpdate == nullptr || customerNameUpdate == nullptr || customerPhoneNumberUpdate == 0 || customerEmailUpdate == nullptr){

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
    else if (!checkssnr(customerSSNrUpdate)){
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

        if(editCustomer(customerSSNrUpdate, customerNameUpdate, customerPhoneNumberUpdate, customerEmailUpdate)){
            ui->message->setStyleSheet("QLabel {background-color : green;"
                                                    "border-style: outset;"
                                                    "border-width: 2px;"
                                                    "border-radius: 10px;"
                                                    "border-color: black;"
                                                    "font: bold 14px;"
                                                    "min-width: 10em;"
                                                    "padding: 6px;}");

            ui->message->setText("Edited name and phone number!");
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

            ui->message->setText("Could not edit customer!");
        }

    }
}


void customeredit::on_loadbutton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;

    QSqlQuery *query = new QSqlQuery;

    query->prepare("SELECT * FROM customers");
    query->exec();
    model->setQuery(*query);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

