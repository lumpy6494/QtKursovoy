#ifndef ORDERITEMS_H
#define ORDERITEMS_H
#include "dish.h"
#include <QObject>

class OrderItems:public QObject
{
        Q_OBJECT

    public:
        OrderItems();
        OrderItems(Dish *dish);
        void set_dishes(Dish *dish);
        void set_amount(int amount);
        Dish get_dishes();
        int get_price();
        int get_amount();
        QString get_dish_title();


    public slots:
        void set_amount_slot(int value);

    private:
    Dish dishes;
    int amount = 1 ;

};

#endif // ORDERITEMS_H
