#ifndef ORDERS_H
#define ORDERS_H
#include "items_order.h"
#include "table.h"
#include <QObject>

class Orders:public QObject
{
    Q_OBJECT
private:
    QString title;
    Table *table_num;
    QMap<QString, OrderItems *> list_orderitems;

public:
    Orders();
    Orders(QString title);
    QString get_title();
    Table * get_table();
    OrderItems *get_orderitems(QString values);
    QMap<QString, OrderItems *> get_all_orderitems();
    void set_title(QString title);
    void set_orderitems(OrderItems *orderitems);
    void set_table(Table* table );
    void del_items(QString value);

public slots:
    void slot_set_orderitems(OrderItems * orderitem);



};

#endif // ORDERS_H
