#ifndef STAFFVIRT_H
#define STAFFVIRT_H
#include <QString>


class Staffvirt
{
private:

public:
    virtual ~Staffvirt() = default;
    virtual void setName(QString name);
    virtual QString getName() = 0;
    virtual Staffvirt* clone() const = 0;
};

#endif // STAFFVIRT_H
