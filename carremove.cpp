#include "carremove.h"
#include "qsqlquery.h"
#include "qsqlquerymodel.h"
#include "sql.h"
#include "ui_carremove.h"


QString carRegNumberRemove = NULL;

carremove::carremove(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::carremove)
{
    ui->setupUi(this);

    QString windowTitle("Remove cars");
    this->setWindowTitle(windowTitle);
    QIcon windowIcon(":/pictures/Pictures/icon.png");
    this->setWindowIcon(windowIcon);
}

carremove::~carremove()
{
    delete ui;
}

void carremove::on_loadbutton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;

    QSqlQuery *query = new QSqlQuery;

    query->prepare("SELECT * FROM cars");
    query->exec();
    model->setQuery(*query);
    ui->cartable->setModel(model);
    ui->cartable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}


void carremove::on_exitbutton_clicked()
{
    this->close();
}


void carremove::on_applybutton_clicked()
{
    carRegNumberRemove = nullptr;
    carRegNumberRemove = ui->regnrtxt->text();

    if (carRegNumberRemove == nullptr){
        ui->transactionlabel->setStyleSheet("QLabel {background-color : red;"
                                                "border-style: outset;"
                                                "border-width: 2px;"
                                                "border-radius: 10px;"
                                                "border-color: black;"
                                                "font: bold 14px;"
                                                "min-width: 10em;"
                                                "padding: 6px;}");

        ui->transactionlabel->setText("Enter a registration number!");
    }
    else if (!checkregnr(carRegNumberRemove)){
        ui->transactionlabel->setStyleSheet("QLabel {background-color : red;"
                                                "border-style: outset;"
                                                "border-width: 2px;"
                                                "border-radius: 10px;"
                                                "border-color: black;"
                                                "font: bold 14px;"
                                                "min-width: 10em;"
                                                "padding: 6px;}");

        ui->transactionlabel->setText("Car does not exist!");
    }
    else{
        if (removeCar(carRegNumberRemove)){
            ui->transactionlabel->setStyleSheet("QLabel {background-color : green;"
                                                    "border-style: outset;"
                                                    "border-width: 2px;"
                                                    "border-radius: 10px;"
                                                    "border-color: black;"
                                                    "font: bold 14px;"
                                                    "min-width: 10em;"
                                                    "padding: 6px;}");

            ui->transactionlabel->setText("Car removed!");

        }
        else{
            ui->transactionlabel->setStyleSheet("QLabel {background-color : red;"
                                                    "border-style: outset;"
                                                    "border-width: 2px;"
                                                    "border-radius: 10px;"
                                                    "border-color: black;"
                                                    "font: bold 14px;"
                                                    "min-width: 10em;"
                                                    "padding: 6px;}");

            ui->transactionlabel->setText("Could not remove car!");
        }
    }
}

