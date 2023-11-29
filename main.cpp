#include "mainwindow.h"
#include "sql.h"

void setDarkTheme(){
    QFile f(":qdarkstyle/dark/style.qss");

    if (!f.exists())   {
        qDebug("Unable to set stylesheet, file not found\n");
    }
    else   {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        qApp->setStyleSheet(ts.readAll());
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    connectToDb();
    createTables();
    setDarkTheme();




    return a.exec();



}

