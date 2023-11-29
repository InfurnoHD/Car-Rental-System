#include "carsearch.h"
#include "qsqlerror.h"
#include "qsqlquery.h"
#include "qsqlquerymodel.h"
#include "ui_carsearch.h"

QString carRegNumberSearch;

carsearch::carsearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::carsearch)
{
    ui->setupUi(this);

    QString windowTitle("Search for cars");
    this->setWindowTitle(windowTitle);
    QIcon windowIcon(":/pictures/Pictures/icon.png");
    this->setWindowIcon(windowIcon);
}

carsearch::~carsearch()
{
    delete ui;
}

void carsearch::on_exitbutton_clicked()
{
    this->close();
}


void carsearch::on_searchbutton_clicked()
{
    carRegNumberSearch = nullptr;
    carRegNumberSearch = ui->regnrtxt->text();

    QSqlQueryModel *model = new QSqlQueryModel;

    QSqlQuery *query = new QSqlQuery;

    if (carRegNumberSearch == nullptr){
        ui->textmessage->setStyleSheet("QLabel {background-color : red;"
                                       "border-style: outset;"
                                       "border-width: 2px;"
                                       "border-radius: 10px;"
                                       "border-color: black;"
                                       "font: bold 14px;"
                                       "min-width: 10em;"
                                       "padding: 6px;}");

        ui->textmessage->setText("Enter a registration number!");
    }
    else{

        ui->textmessage->clear();
        ui->textmessage->setStyleSheet("QLabel {background-color : #19232D;"
                                       "border-style: outset;"
                                       "border-width: 2px;"
                                       "border-radius: 10px;"
                                       "border-color: black;"
                                       "font: bold 14px;"
                                       "min-width: 10em;"
                                       "padding: 6px;}");
        query->prepare("SELECT * FROM cars WHERE carRegNumber LIKE :carRegNumberSearch");
        query->bindValue(":carRegNumberSearch", QString("%%1%").arg(carRegNumberSearch));
        query->exec();

        model->setQuery(*query);
        ui->tableView->setModel(model);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
}

