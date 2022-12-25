#include "dish.h"

Dish::Dish()
{

}

Dish::Dish(QString title, int price, int weight, int time)
{
    this->title =  title;
    this->price = price;
    this->weight = weight;
    this->time = time;
}

QString Dish::get_title(){
    return this->title;
}


int Dish::get_price(){
    return  this->price;
}

int Dish::get_weigth(){
    return this->weight;
}

int Dish::get_time(){
    return this->time;
}

void Dish::set_title(QString title){
    this->title = title;
}

void Dish::set_price(int price){
    this->price = price;
}

void Dish::set_weigth(int weight){
    this->weight = weight;
}

void Dish::set_time(int time){
    this->time = time;
}





