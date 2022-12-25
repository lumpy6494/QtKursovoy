#ifndef WAITER_H
#define WAITER_H
#include "staff.h"
#include <QString>



class Waiter
{
private:
    QString name;
public:
    Waiter();
    Waiter (QString name);
    QString get_name();
    void set_name(QString name);

};



#endif // WAITER_H
