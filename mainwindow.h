#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    int index_x;
    int index_y;
    int index;
    QString table_name;
    //QButtonGroup *buttonGroup;
    ~MainWindow();

private slots:

    void show_table();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_del_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
