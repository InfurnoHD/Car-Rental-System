#include "sql.h"

void connectToDb(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/SQLITE/carrental.sqlite");

    if (!db.open()){

        qDebug() << "Could not connect to the database:" << db.lastError();

    }

}

void createTables(){

    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS cars (carRegNumber TEXT NOT NULL PRIMARY KEY, carMake TEXT NOT NULL, carModel TEXT NOT NULL, carProdYear INTEGER NOT NULL)");

    if (!query.exec()){
        qDebug()<< "Unable to create the table 'cars':" << query.lastError();
    }

    query.prepare("CREATE TABLE IF NOT EXISTS customers(customerSSNr TEXT NOT NULL PRIMARY KEY, customerName TEXT NOT NULL, customerPhoneNumber INTEGER NOT NULL, customerEmail TXT NOT NULL)");
    if (!query.exec()){
        qDebug() << "Unable to create the table 'customers':" << query.lastError();
    }

    query.prepare("CREATE TABLE IF NOT EXISTS rentals(carRegNumber TEXT NOT NULL PRIMARY KEY, customerSSNr TEXT NOT NULL, FOREIGN KEY(carRegNumber) REFERENCES cars(carRegNumber), FOREIGN KEY(customerSSNr) REFERENCES customers(customerSSNr))");
    if (!query.exec()){
        qDebug() << "Unable to create the table 'rentals':" << query.lastError();
    }
}




bool addCar(QString carRegNumber, QString carMake, QString carModel, int carYear){


    QSqlQuery query;

    query.prepare("INSERT INTO cars (carRegNumber, carMake, carModel, carProdYear) VALUES (:carRegNumber, :carMake, :carModel, :carProdYear)");
    query.addBindValue(carRegNumber);
    query.addBindValue(carMake);
    query.addBindValue(carModel);
    query.addBindValue(carYear);

    if (!query.exec()){
        qDebug() << "Unable to add car:" << query.lastError();
        return false;
    }
    else{
        return true;
    }

}

bool checkregnr(QString carRegNumber){

    bool exists;

    QSqlQuery query;

    query.prepare("SELECT EXISTS(SELECT carregnumber FROM cars WHERE carregnumber = :carRegNumber)");
    query.addBindValue(carRegNumber);
    query.exec();

    while(query.next()){
        exists = query.value(0).toBool();
    }

    return exists;
}

bool editCar(QString carRegNumber, QString carMakeUpdate, QString carModelUpdate, int carProdYear){
    QSqlQuery query;



    query.prepare("UPDATE cars SET carMake = :carMakeUpdate, carModel = :carModelUpdate, carProdYear = :carProdYear WHERE carRegNumber = :carRegNumber");
    query.addBindValue(carMakeUpdate);
    query.addBindValue(carModelUpdate);
    query.addBindValue(carProdYear);
    query.addBindValue(carRegNumber);


    if (!query.exec()){
        qDebug() << query.lastError();
        return false;
    }
    else{
        return true;
    }
}

bool removeCar(QString carRegNumber){
    QSqlQuery query;


    query.prepare("DELETE FROM cars WHERE carRegNumber = :carRegNumber");
    query.addBindValue(carRegNumber);

    if (!query.exec()){
        return false;
    }
    else{
        return true;
    }
}

bool addCustomer(QString customerSSNr, QString customerName, int customerPhoneNumber, QString customerEmail){
    QSqlQuery query;




    query.prepare("INSERT INTO customers (customerSSNr, customerName, customerPhoneNumber, customerEmail) VALUES (:customerSSNr, :customerName, :customerPhoneNumber, :customerEmail)");
    query.addBindValue(customerSSNr);
    query.addBindValue(customerName);
    query.addBindValue(customerPhoneNumber);
    query.addBindValue(customerEmail);

    if (!query.exec()){
        return false;
    }
    else{
        return true;
    }

}

bool checkssnr(QString customerSSNr){

    bool exists;

    QSqlQuery query;

    query.prepare("SELECT EXISTS(SELECT customerSSNr FROM customers WHERE customerSSNr = :customerSSNr)");
    query.addBindValue(customerSSNr);
    query.exec();

    while(query.next()){
        exists = query.value(0).toBool();
    }

    return exists;
}

bool editCustomer(QString customerSSNr, QString customerNameUpdate, int customerPhoneNumberUpdate, QString customerEmail){


    QSqlQuery query;

    query.prepare("UPDATE customers SET customerName = :customerNameUpdate, customerPhoneNumber = :customerPhoneNumberUpdate, customerEmail = :customerEmail WHERE customerSSNr = :customerSSNr");
    query.addBindValue(customerNameUpdate);
    query.addBindValue(customerPhoneNumberUpdate);
    query.addBindValue(customerEmail);
    query.addBindValue(customerSSNr);

    if (!query.exec()){
        return false;
    }
    else{
        return true;
    }
}

bool removeCustomer(QString customerSSNr){
    QSqlQuery query;


    query.prepare("DELETE FROM customers WHERE customerSSNr = :customerSSNr");
    query.addBindValue(customerSSNr);

    if (!query.exec()){
        return false;
    }
    else{
        return true;
    }
}

bool addRental(QString carRegNumber, QString customerSSNr){
    QSqlQuery query;

    query.prepare("INSERT INTO rentals (carRegNumber, customerSSNr) VALUES (:carRegNumber, :customerSSNr)");
    query.addBindValue(carRegNumber);
    query.addBindValue(customerSSNr);

    if (!query.exec()){
        return false;
    }
    else{
        return true;
    }

}

bool checkregnrrental (QString carRegNumber){

    bool exists;

    QSqlQuery query;

    query.prepare("SELECT EXISTS(SELECT carRegNumber FROM rentals WHERE carRegNumber = :carRegNumber)");
    query.addBindValue(carRegNumber);
    query.exec();

    while(query.next()){
        exists = query.value(0).toBool();
    }

    return exists;
}



bool removeRental(QString carRegNumber){

    QSqlQuery query;

    query.prepare("DELETE FROM rentals WHERE carRegNumber = :carRegNumber ");
    query.addBindValue(carRegNumber);

    if (!query.exec()){
        return false;
    }
    else{
        return true;
    }

}
