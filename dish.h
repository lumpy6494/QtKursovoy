#ifndef DISH_H
#define DISH_H
#include <QString>
#include <QMap>


class Dish
{
private:
    QString title;
//    QString dishgroup;
    int price;
    int weight;
    int time;

public:
    Dish();
    Dish(QString title, int price, int weight, int time);
    QString get_title();
    int get_price();
    int get_weigth();
    int get_time();
//    QString get_dishgroup();

    void set_title(QString titlle);
    void set_price(int price);
    void set_weigth(int weight);
    void set_time(int time);
//    void set_dishgroup(Group *group);



};

#endif // DISH_H
