#ifndef ADMIN_H
#define ADMIN_H
#include "staffvirt.h"
#include <QString>

class Admin:public Staffvirt
{
private:
    QString name;
    QString login;
    QString password;
public:
    Admin();
    ~Admin();
    void setName(QString name) override;
    void setLogin(QString login);
    void setPassword(QString password);
    QString getName() override;
    QString getLogin();
    QString getPassword();
    Admin* clone() const;
};

#endif // ADMIN_H
