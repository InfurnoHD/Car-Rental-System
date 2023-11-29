#include "removerental.h"
#include "qsqlquery.h"
#include "qsqlquerymodel.h"
#include "ui_removerental.h"
#include "sql.h"

QString carRegRemove;

removerental::removerental(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removerental)
{
    ui->setupUi(this);

    QString windowTitle("Remove rentals");
    this->setWindowTitle(windowTitle);
    QIcon windowIcon(":/pictures/Pictures/icon.png");
    this->setWindowIcon(windowIcon);
}

removerental::~removerental()
{
    delete ui;
}

void removerental::on_exitbutton_clicked()
{
    this->close();
}


void removerental::on_loadrentalsbutton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;

    QSqlQuery *query = new QSqlQuery;

    query->prepare("SELECT * FROM rentals");
    query->exec();
    model->setQuery(*query);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}


void removerental::on_applybutton_clicked()
{


    if (carRegRemove == nullptr){
        ui->message->setStyleSheet("QLabel {background-color : red;"
                                   "border-style: outset;"
                                   "border-width: 2px;"
                                   "border-radius: 10px;"
                                   "border-color: black;"
                                   "font: bold 14px;"
                                   "min-width: 10em;"
                                   "padding: 6px;}");

        ui->message->setText("Choose a registration number!");
    }
    else if (!checkregnrrental(carRegRemove)){
        ui->message->setStyleSheet("QLabel {background-color : red;"
                                   "border-style: outset;"
                                   "border-width: 2px;"
                                   "border-radius: 10px;"
                                   "border-color: black;"
                                   "font: bold 14px;"
                                   "min-width: 10em;"
                                   "padding: 6px;}");

        ui->message->setText("Rental does not exist!");

    }
    else{

        if (removeRental(carRegRemove) == true){
            ui->message->setStyleSheet("QLabel {background-color : green;"
                                       "border-style: outset;"
                                       "border-width: 2px;"
                                       "border-radius: 10px;"
                                       "border-color: black;"
                                       "font: bold 14px;"
                                       "min-width: 10em;"
                                       "padding: 6px;}");

            ui->message->setText("Rental removed!");

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

            ui->message->setText("Could not remove rental!");
        }
    }
}


void removerental::on_pushButton_clicked()
{

    carRegRemove = nullptr;

    QSqlQueryModel *model = new QSqlQueryModel;

    QSqlQuery *query = new QSqlQuery;

    query->prepare("SELECT carRegNumber FROM cars");
    query->exec();
    model->setQuery(*query);
    ui->carregbox->setModel(model);
}


void removerental::on_carregbox_textActivated(const QString &arg1)
{
    carRegRemove = arg1;
}

