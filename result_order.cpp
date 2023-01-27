#include "result_order.h"
#include "ui_result_order.h"
#include <QDebug>

Result_order::Result_order(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Result_order)
{
    ui->setupUi(this);
}

Result_order::~Result_order()
{
    delete ui;
}


void Result_order::set_textbrowser(QString value)
{
    return ui->textBrowser->append(value);
}



void Result_order::set_table_result_check(QMap<int, QStringList>va, int rows)
{
    ui->tableWidget->setRowCount(rows);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels({"Наименование","Количество", "Цена"});


    for (int var = 0; var < rows; ++var)
    {
        QStringList value_strlist = va.value(var);
        for (int j = 0; j<3;j++)
        {
            ui->tableWidget->setItem(var,j, new QTableWidgetItem(value_strlist.value(j)));
            ui->tableWidget->item(var,j)->setTextAlignment(Qt::AlignCenter);
        }
    }

//    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->setColumnWidth(0, 213);
    ui->tableWidget->setColumnWidth(1, 213);
    ui->tableWidget->setColumnWidth(2, 213);
    ui->tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);
}

void Result_order::on_buttonBox_accepted()
{

    return QApplication::exit();
}
