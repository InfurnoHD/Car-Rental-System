#pragma once

#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QtSql>





void connectToDb();

void createTables();


bool addCar(QString carRegNumber, QString carMake, QString carModel, int carYear);

bool checkregnr(QString carRegNumber);

bool editCar(QString carRegNumber, QString carMakeUpdate, QString carModelUpdate, int carProdYear);

bool removeCar(QString carRegNumber);

bool addCustomer(QString customerSSNr, QString customerName, int customerPhoneNumber, QString customerEmail);

bool checkssnr(QString customerSSNr);

bool editCustomer(QString customerSSNr, QString customerNameUpdate, int customerPhoneNumberUpdate, QString customerEmail);

bool removeCustomer(QString customerSSNr);

bool addRental(QString carRegNumber, QString customerSSNr);

bool checkregnrrental(QString carRegNumber);

bool removeRental(QString carRegNumber);

bool checkrentalnr (int rentalId);
