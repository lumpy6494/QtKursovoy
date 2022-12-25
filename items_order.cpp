#include "items_order.h"
#include <QDebug>

OrderItems::OrderItems()
{

}

OrderItems::OrderItems(Dish * dish)
{
    this->dishes = *dish;
}

void OrderItems:: set_dishes(Dish *dish)
{
    this->dishes = *dish;
}


Dish OrderItems::get_dishes()
{
    return this->dishes;
}

int OrderItems::get_price()
{
   int price = this->dishes.get_price() * amount;
   return price;
}

void OrderItems::set_amount(int amount)
{
   this->amount = amount;
}


int OrderItems::get_amount()
{
    return this->amount;
}



void OrderItems::set_amount_slot(int value)
{
    this->amount = value;
//    qDebug() << amount;
}

QString OrderItems::get_dish_title()
{
    return this->get_dishes().get_title();
}


