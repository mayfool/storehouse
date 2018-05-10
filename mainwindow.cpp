#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlTableModel>
#include <QTableView>
#include <connection.h>
#include <tableeditor.h>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    index_x = 0;
    index_y = 0;
    index = 0;
    table_name = "person";
    /*
    QPushButton *radio1 = new QPushButton(tr("111"));
    ui->gridLayout_3->addWidget(radio1,index_x,index_y);
    index_x=0;
    index_y=1;
    */


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::show_table()
{
    qDebug()<<QObject::sender()->objectName();
    TableEditor *editor = new TableEditor(table_name);
    editor->show();
}

void MainWindow::on_pushButton_4_clicked()//无效
{

    QPushButton *radio1 = new QPushButton(tr("仓库"));
        QGridLayout *pLayout = new QGridLayout();
        pLayout->addWidget(radio1);
        QWidget *centerWindow = centralWidget();
        this->setCentralWidget(centerWindow);
        centerWindow->setLayout(pLayout);

    //QPushButton * addhouse = new QPushButton(this->centralWidget());
    //addhouse->setText(tr("四号库"));
    qDebug("1111");
    //ui->centralWidget->addWidget();


}

void MainWindow::on_pushButton_2_clicked()
{

    QString s = QString::number(index, 10);
    s += " 号仓库";
    const char * p = s.toLocal8Bit().data();
    QPushButton *radio1 = new QPushButton(tr(p));
    radio1->setObjectName(s);
    ui->gridLayout_3->addWidget(radio1,index_x,index_y);
    index++;
    index_y++;
    if(index_y==3){
        index_x++;
        index_y = 0;
    }


    connect(radio1,SIGNAL(clicked(bool)),this,SLOT(show_table()));
    table_name = "person";

}

void MainWindow::on_pushButton_del_clicked()
{/*
    int remove_x = index_x;
    int remove_y = index_y;
    if(index_y==0){
        remove_x--;
        index_y = 2;
    }
    else{
        remove_y--;
    }

    QWidget *removewidget = ui->gridLayout_3->
    ui->gridLayout_3->removeWidget(remove_x,remove_y);*/

    int num = ui->gridLayout_3->count();
    if(!num) return;
    QWidget *p = ui->gridLayout_3->itemAt(num-1)->widget();
    ui->gridLayout_3->removeWidget(p);
    delete p;
    if(index_y==0){
        index_x--;
        index_y = 2;
    }
    else{
        index_y--;
    }

    index--;
}
