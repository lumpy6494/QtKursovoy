#include "orders.h"
#include <QDebug>

Orders::Orders()
{

}

Orders::Orders(QString title)
{
    this->title = title;
}


QString Orders::get_title()
{
    return this->title;
}

void Orders::set_title(QString title)
{
    this->title = title;
}


OrderItems* Orders::get_orderitems(QString values)
{
    return this->list_orderitems.value(values);
}

QMap<QString, OrderItems *> Orders::get_all_orderitems()
{
    return this->list_orderitems;
}

void Orders::set_orderitems(OrderItems *orderitem)
{
    this->list_orderitems.insert(orderitem->get_dishes().get_title(),orderitem);
//    qDebug() << orderitem->get_dishes().get_title();

}

void Orders::slot_set_orderitems(OrderItems *orderitem)
{
    this->list_orderitems.insert(orderitem->get_dishes().get_title(),orderitem);
    qDebug() << orderitem->get_dishes().get_title();
}


void Orders::set_table(Table* table)
{
    this->table_num = table;
}


Table *Orders::get_table()
{
    return this->table_num;
}

void Orders::del_items(QString value)
{
    list_orderitems.remove(value);
}


