#ifndef MENU_H
#define MENU_H
#include <QString>
#include "group.h"


class Menu
{
private:
    QString title;
    QMap<QString, Group *> listgroup;

public:
    Menu();
    Menu(QString title);
    QString get_title();
    Group * get_group(QString values);
    QMap<QString, Group *> get_all_group();
    void set_title(QString title);
    void set_group(Group *group);


};

#endif // MENU_H
