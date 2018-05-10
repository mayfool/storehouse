

#include <QtWidgets>
#include <QtSql>
#include <QDebug>

#include "tableeditor.h"
#include "connection.h"

//! [0]
TableEditor::TableEditor(const QString &tableName, QWidget *parent)
    : QWidget(parent)
{
    model = new QSqlTableModel(this);
    model->setTable(tableName);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    a = model->select();
    if(a == false){
        QString ss = "ss";
        qDebug("qwe");
    }

    //model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    //model->setHeaderData(1, Qt::Horizontal, tr("First name"));
    //model->setHeaderData(3, Qt::Horizontal, tr("Last name"));

//! [0] //! [1]
    QTableView *view = new QTableView;
    view->setSortingEnabled(true);//排序
    view->setModel(model);
    view->resizeColumnsToContents();
    view->show();
//! [1]

//! [2]
    submitButton = new QPushButton(tr("Submit"));
    submitButton->setDefault(true);
    revertButton = new QPushButton(tr("&Revert"));
    quitButton = new QPushButton(tr("Quit"));

    buttonBox = new QDialogButtonBox(Qt::Vertical);
    buttonBox->addButton(submitButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(revertButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);
//! [2]

//! [3]
    connect(submitButton, &QPushButton::clicked, this, &TableEditor::submit);
    connect(revertButton, &QPushButton::clicked,  model, &QSqlTableModel::revertAll);
    connect(quitButton, &QPushButton::clicked, this, &TableEditor::close);
//! [3]

//! [4]
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(view);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(tr("Cached Table"));
}
//! [4]

//! [5]
void TableEditor::submit()
{
    model->database().transaction();
    if (model->submitAll()) {
        model->database().commit();
    } else {
        model->database().rollback();
        QMessageBox::warning(this, tr("Cached Table"),
                             tr("The database reported an error: %1")
                             .arg(model->lastError().text()));
    }
}
//! [5]
