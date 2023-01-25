#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QDialog>
#include <QVBoxLayout>
#include "waiter.h"
#include "admin.h"
#include "group_admin.h"
#include "group_waiter.h"
#include "menu.h"
#include "dish.h"
#include "group.h"


namespace Ui {
class AdminPanel;
}

class AdminPanel : public QDialog
{
    Q_OBJECT

public:
    explicit AdminPanel(QWidget *parent = nullptr);
    void set_waiter_panel_admin(Waiter * waiter);
    void set_unitadmin_panel_admin(Admin * admin);
    void set_admin_list(Group_Admin *admin_list);
    void set_waiter_list(Group_Waiter *admin_waiter);
    void set_menu(Menu *menu);
    void set_combobox();
    void set_list_layout(QString key, QVBoxLayout* layout_box );
    ~AdminPanel();

private slots:
    void on_pushButton_add_waiter_clicked();

    void on_pushButton_add_admin_clicked();

    void on_pushButton_add_dish_clicked();

    void on_buttonBox_accepted();



private:
    Ui::AdminPanel *ui;
    Waiter *waiter_panel_admin;
    Admin *unitadmin_panel_admin;
    Group_Admin *listadmin_admin_panel;
    Group_Waiter *listadmin_waiter_panel;
    Menu *menu;

    QMap<QString, QVBoxLayout *> listlayout;


signals:
void mySignal(QString, QVBoxLayout*);

};

#endif // ADMINPANEL_H
