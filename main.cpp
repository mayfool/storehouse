#include "mainwindow.h"
#include <QApplication>
#include <connection.h>
#include <QApplication>
#include <QSqlTableModel>
#include <QTableView>
#include <tableeditor.h>

#include <stdlib.h>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    if (!createConnection())
        return 1;

    MainWindow w;
    w.show();


    return app.exec();
}
