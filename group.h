#ifndef GROUP_H
#define GROUP_H
#include <QString>
#include "dish.h"


class Group
{
private:
    QString title;
    QMap<int, Dish *> listdish;

public:
    Group();
    Group(QString title);
    QString get_title();
    QMap<int, Dish *> get_dish();

    void set_title(QString title);
    void set_dish(Dish *dish);

};

#endif // GROUP_H
