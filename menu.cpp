#include "menu.h"
#include "group.h"

Menu::Menu()
{

}

Menu::Menu(QString title)
{
    this->title = title;
}


QString Menu::get_title()
{
    return this->title;
}

void Menu::set_title(QString title)
{
    this->title = title;
}


Group* Menu::get_group(QString values)
{
    return this->listgroup.value(values);
}

QMap<QString, Group *> Menu::get_all_group()
{
    return this->listgroup;
}

void Menu::set_group(Group *group)
{
    this->listgroup.insert(group->get_title(),group);
}
