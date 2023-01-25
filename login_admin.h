#ifndef LOGIN_ADMIN_H
#define LOGIN_ADMIN_H

#include <QDialog>
#include "group_admin.h"
#include "dish.h"
#include "waiter.h"
#include "admin.h"
#include "adminpanel.h"
#include "group_waiter.h"
#include "menu.h"

namespace Ui {
class Login_Admin;
}

class Login_Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Login_Admin(QWidget *parent = nullptr);
    void set_admin_list(Group_Admin *admin_list);

    void set_admin_panel(AdminPanel *admin_pa);



    ~Login_Admin();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Login_Admin *ui;
    Group_Admin *admin_list;
    AdminPanel *admin_panel;




};

#endif // LOGIN_ADMIN_H
