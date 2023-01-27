#ifndef GROUP_ADMIN_H
#define GROUP_ADMIN_H
#include <QMap>
#include "admin.h"

class Group_Admin
{
private:
    QMap<QString, Admin *> listadmin;

public:
    Group_Admin();
    QMap<QString, Admin *> get_all_admin();
    Admin* get_admin_is_group(QString values);
    void set_group_admin(Admin *admin);
    void del_items(QString value);

};

#endif // GROUP_ADMIN_H
