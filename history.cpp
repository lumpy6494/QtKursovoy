#include "history.h"
#include "ui_history.h"
#include <QDebug>
History::History(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::History)
{
    ui->setupUi(this);
}

History::~History()
{
    delete ui;
}

void History::show_history(QSqlTableModel *model)
{
    qDebug() << model;
    ui->tableView->setModel(model);
}
