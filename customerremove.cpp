#include "customerremove.h"
#include "qsqlquery.h"
#include "qsqlquerymodel.h"
#include "ui_customerremove.h"
#include "sql.h"

QString customerSSNrRemove = NULL;

customerremove::customerremove(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customerremove)
{
    ui->setupUi(this);

    QString windowTitle("Remove customers");
    this->setWindowTitle(windowTitle);
    QIcon windowIcon(":/pictures/Pictures/icon.png");
    this->setWindowIcon(windowIcon);
}

customerremove::~customerremove()
{
    delete ui;
}

void customerremove::on_exitbutton_clicked()
{
    this->close();
}


void customerremove::on_loadbutton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;

    QSqlQuery *query = new QSqlQuery;

    query->prepare("SELECT * FROM customers");
    query->exec();
    model->setQuery(*query);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}


void customerremove::on_applybutton_clicked()
{
    customerSSNrRemove = nullptr;
    customerSSNrRemove = ui->ssnrtxt->text();

    if (customerSSNrRemove == nullptr){
        ui->message->setStyleSheet("QLabel {background-color : red;"
                                                "border-style: outset;"
                                                "border-width: 2px;"
                                                "border-radius: 10px;"
                                                "border-color: black;"
                                                "font: bold 14px;"
                                                "min-width: 10em;"
                                                "padding: 6px;}");

        ui->message->setText("Enter a social security number!");
    }
    else if (!checkssnr(customerSSNrRemove)){
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
        if (removeCustomer(customerSSNrRemove)){
            ui->message->setStyleSheet("QLabel {background-color : green;"
                                                    "border-style: outset;"
                                                    "border-width: 2px;"
                                                    "border-radius: 10px;"
                                                    "border-color: black;"
                                                    "font: bold 14px;"
                                                    "min-width: 10em;"
                                                    "padding: 6px;}");

            ui->message->setText("Customer removed!");

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

            ui->message->setText("Could not remove customer!");
        }
    }
}

