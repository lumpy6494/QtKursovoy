#include "table.h"

Table::Table()
{

}
Table::Table(int number)
{
    this->num_table = number;
}


int Table::get_table()
{
    return this->num_table;
}


void Table::set_table(int number)
{
    this->num_table =  number;
}
