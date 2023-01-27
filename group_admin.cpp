#include "group_admin.h"

Group_Admin::Group_Admin()
{

}

void Group_Admin::set_group_admin(Admin *admin)
{
    this->listadmin.insert(admin->getLogin(),admin);
}


QMap<QString, Admin*> Group_Admin::get_all_admin()
{
    return this->listadmin;
}


Admin* Group_Admin::get_admin_is_group(QString values)
{
    return this->listadmin.value(values);
}

void Group_Admin::del_items(QString value)
{
    listadmin.remove(value);
}

