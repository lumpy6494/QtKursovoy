#include "waiter.h"
#include <QString>

Waiter::Waiter()
{
}

Waiter::Waiter(QString name) {
    this->name = name ;
}


QString Waiter::get_name()  {
    return this->name;
}

void Waiter::set_name(QString name)
{
    this->name = name;
}


