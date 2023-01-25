#include "waiter.h"
#include <QString>

Waiter::Waiter()
{
}

Waiter::~Waiter()
{

}

QString Waiter::getName()  {
    return this->name;
}

void Waiter::setName(QString name)
{
    this->name = name;
}



Waiter* Waiter::clone() const
{
    return new Waiter(*this);
}
