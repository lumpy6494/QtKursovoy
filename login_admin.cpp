#include "login_admin.h"
#include "ui_login_admin.h"
#include <QDebug>
#include <QString>

Login_Admin::Login_Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login_Admin)
{
    ui->setupUi(this);
}

Login_Admin::~Login_Admin()
{
    delete ui;
}



void Login_Admin::set_admin_list(Group_Admin *admin_list)
{
    this->admin_list = admin_list;

//    for(auto res : this->admin_list->get_all_admin())
//    {
//        qDebug() << res->getLogin() ;
//    }

}


void Login_Admin::set_admin_panel(AdminPanel *admin_pa)
{
    this->admin_panel = admin_pa;
}




void Login_Admin::on_pushButton_ok_clicked()
{
        QString admin = ui->auth_lineEdit_login->text();
        QString pass = ui->auth_lineEdit_pass->text();

            if (admin_list->get_admin_is_group(admin))
            {
              Admin *a = admin_list->get_admin_is_group(admin);
              if (a->getPassword() == pass)
              {
                  qDebug() << "Работает";
                  admin_panel->set_admin_list(this->admin_list);
                  admin_panel->show();
                  this->close();

              }
              else {
                  qDebug() << "Пароль не Работает";
                  ui->login_label_status->setText("Пароль не подходит");
              }

            }
            else {
                ui->login_label_status->setText("Пользователя нет в системе");
                 qDebug() << "Такого админа нет";

            }

}

void Login_Admin::on_pushButton_cancel_clicked()
{
    this->close();
}
