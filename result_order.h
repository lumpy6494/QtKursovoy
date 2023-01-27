#ifndef RESULT_ORDER_H
#define RESULT_ORDER_H
#include "orders.h"
#include <QDialog>
#include <QTextBrowser>

namespace Ui {
class Result_order;
}

class Result_order : public QDialog
{
    Q_OBJECT

public:
    explicit Result_order(QWidget *parent = nullptr);
    void set_textbrowser(QString value);
    void set_table_result_check(QMap<int, QStringList> va, int rows);
    ~Result_order();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Result_order *ui;



};

#endif // RESULT_ORDER_H
