#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include "waiter.h"
#include "dish.h"
#include "group.h"
#include "menu.h"
#include "items_order.h"
#include "orders.h"
#include "table.h"
#include "result_order.h"
#include <QVBoxLayout>




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void createUI();
    void set_layoutgroup(QLayout * lay);
    ~MainWindow();

private slots:

    void boxclick();
    void view_check();
    void view_order_summ();

    void on_Order_clicked();

private:
    Ui::MainWindow *ui;
    Result_order *result_window;

    QSqlDatabase db;
    Waiter Ivan;


    Dish tea, lemonad;
    Dish chicken_soup, shchi;
    Dish utka, mutton;
    Dish sushi, salmon ;
    Dish ikra, eggplant;

    Group two_dish, one_dish, three_dish, drinks;

    Menu menu;
    Orders order;
    Table table;

};
#endif // MAINWINDOW_H
