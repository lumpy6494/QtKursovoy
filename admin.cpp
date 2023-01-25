#include "admin.h"

Admin::Admin()
{

}

Admin::~Admin()
{

}

QString Admin::getName()  {
    return this->name;
}

QString Admin::getLogin()  {
    return this->login;
}

QString Admin::getPassword()  {
    return this->password;
}

void Admin::setName(QString name)
{
    this->name = name;
}

void Admin::setLogin(QString login)
{
    this->login = login;
}

void Admin::setPassword(QString password)
{
    this->password = password;
}


Admin* Admin::clone() const
{
    return new Admin(*this);
}
