#ifndef GROUP_WAITER_H
#define GROUP_WAITER_H
#include <QMap>
#include <QString>
#include <waiter.h>

class Group_Waiter
{
private:
    QMap<int, Waiter *> listwaiters;


public:
    Group_Waiter();
    QMap<int, Waiter *> get_all_waiters();
    void set_waiter_in_group(Waiter *waiter);
    Waiter* get_waiters_is_group(int val);


};

#endif // GROUP_WAITER_H
