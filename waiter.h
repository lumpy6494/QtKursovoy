#ifndef WAITER_H
#define WAITER_H
#include "staffvirt.h"
#include <QString>



class Waiter: public Staffvirt
{
private:
    QString name;
public:
    Waiter();
    ~Waiter();
    void setName(QString name) override;
    QString getName() override;
    Waiter* clone() const;
};

#endif // WAITER_H
