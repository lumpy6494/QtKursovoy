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
    this->mod = model;
    ui->tableView_history->setModel(model);
}

void History::on_tableView_history_clicked(const QModelIndex &index)
{
    row = index.row();
}

void History::on_pushButton_delete_history_clicked()
{
   mod->removeRow(row);
   ui->label_history_status->setText("Строка Удалена!");

}
