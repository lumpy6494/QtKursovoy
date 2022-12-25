#include "group.h"
#include "dish.h"

Group::Group()
{
}

Group::Group(QString title)
{
    this->title = title;
}

QString Group::get_title()
{
    return this->title;
}


QMap< int, Dish *> Group::get_dish()
{
    return this->listdish;
}

void Group::set_title(QString title)
{
    this->title = title;
}


void Group::set_dish(Dish *dish)
{
    this->listdish.insert(listdish.size() + 1, dish);
}





