#ifndef CUSTOMCHECKBOX_H
#define CUSTOMCHECKBOX_H

#include <QObject>
#include <QCheckBox>
#include "items_order.h"

class CustomCheckbox: public QCheckBox
{
    Q_OBJECT

public:
    CustomCheckbox();
    OrderItems *items;
    void add_orderitems(OrderItems *item);


};

#endif // CUSTOMCHECKBOX_H
