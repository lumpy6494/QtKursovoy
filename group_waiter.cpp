#include "group_waiter.h"

Group_Waiter::Group_Waiter()
{

}


QMap<int, Waiter *>Group_Waiter::get_all_waiters()
{
    return this->listwaiters;
}

void Group_Waiter::set_waiter_in_group(Waiter *waiter)
 {
     this->listwaiters.insert(listwaiters.size() + 1, waiter);
 }

Waiter* Group_Waiter::get_waiters_is_group(int val)
{
   return this->listwaiters.value(val);
}

void Group_Waiter::del_items_waiter(int value)
{
    this->listwaiters.remove(value);
}
