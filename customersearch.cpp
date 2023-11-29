#include "customersearch.h"
#include "qsqlquery.h"
#include "qsqlquerymodel.h"
#include "ui_customersearch.h"

QString customerNameSearch;

customersearch::customersearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customersearch)
{
    ui->setupUi(this);

    QString windowTitle("Search for customers");
    this->setWindowTitle(windowTitle);
    QIcon windowIcon(":/pictures/Pictures/icon.png");
    this->setWindowIcon(windowIcon);
}

customersearch::~customersearch()
{
    delete ui;
}

void customersearch::on_pushButton_2_clicked()
{
    this->close();
}


void customersearch::on_searchbutton_clicked()
{
    customerNameSearch = nullptr;
    customerNameSearch = ui->ssnrtxt->text();

    QSqlQueryModel *model = new QSqlQueryModel;

    QSqlQuery *query = new QSqlQuery;

    if (customerNameSearch == nullptr){
        ui->message->setStyleSheet("QLabel {background-color : red;"
                                       "border-style: outset;"
                                       "border-width: 2px;"
                                       "border-radius: 10px;"
                                       "border-color: black;"
                                       "font: bold 14px;"
                                       "min-width: 10em;"
                                       "padding: 6px;}");

        ui->message->setText("Enter a name!");
    }
    else{

        ui->message->clear();
        ui->message->setStyleSheet("QLabel {background-color : #19232D;"
                                       "border-style: outset;"
                                       "border-width: 2px;"
                                       "border-radius: 10px;"
                                       "border-color: black;"
                                       "font: bold 14px;"
                                       "min-width: 10em;"
                                       "padding: 6px;}");

        query->prepare("SELECT * FROM customers WHERE customerName LIKE :customerNameSearch");
        query->bindValue(":customerNameSearch", QString("%%1%").arg(customerNameSearch));
        query->exec();

        model->setQuery(*query);
        ui->tableView->setModel(model);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
}


