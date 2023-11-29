#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customerwindow.h"
#include "carwindow.h"
#include "rentalwindow.h"
#include "qfile.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(880,350);
    QString windowTitle("Car rental");
    this->setWindowTitle(windowTitle);
    QIcon windowIcon(":/pictures/Pictures/icon.png");
    this->setWindowIcon(windowIcon);
}



MainWindow::~MainWindow()
{


    delete ui;
}


void MainWindow::on_customersButton_clicked()
{
    customerwindow customerwindow;
    customerwindow.setModal(true);
    customerwindow.exec();
}


void MainWindow::on_carsButton_clicked()
{
    carwindow carwindow;
    carwindow.setModal(true);
    carwindow.exec();

}


void MainWindow::on_rentalsButton_clicked()
{
    rentalwindow rentalwindow;
    rentalwindow.setModal(true);
    rentalwindow.exec();
}


void MainWindow::on_actionExit_triggered()
{
    this->close();
}



