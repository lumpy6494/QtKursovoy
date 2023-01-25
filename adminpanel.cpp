#include "adminpanel.h"
#include "ui_adminpanel.h"
#include <QDebug>
#include <typeinfo>

AdminPanel::AdminPanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminPanel)
{
    ui->setupUi(this);

}

AdminPanel::~AdminPanel()
{
    delete ui;
}

void AdminPanel::set_waiter_panel_admin(Waiter * waiter)
{
    this->waiter_panel_admin = waiter;
}
void AdminPanel::set_unitadmin_panel_admin(Admin * admin)
{
    this->unitadmin_panel_admin = admin;
}

void AdminPanel::set_admin_list(Group_Admin *admin_list)
{
    this->listadmin_admin_panel = admin_list;

}

void AdminPanel::set_waiter_list(Group_Waiter *admin_waiter)
{
    this->listadmin_waiter_panel = admin_waiter;
}


void AdminPanel::set_menu(Menu *menu)
{
    this->menu = menu;
}


void AdminPanel::set_combobox()
{
    for(auto res : menu->get_all_group())
    {
    //          ui->comboBox_menu->addItem(res->get_title());
        qDebug() << res->get_title();
        ui->comboBox_menu->addItem(res->get_title());

    }
}

void AdminPanel::on_pushButton_add_waiter_clicked()
{
    if (ui->lineEdit_name_waiter->text()!= "")
    {
        Waiter* wait = waiter_panel_admin->clone();
        wait->setName(ui->lineEdit_name_waiter->text());
        this->listadmin_waiter_panel->set_waiter_in_group(wait);
        ui->lineEdit_name_waiter->clear();
        ui->label_status->setText("Официант " + wait->getName() + " успешно добавлен!");
        qDebug() << wait->getName();

    }
    else {
        ui->label_status->setText("Поле не должно быть пустым! ");
    }

}

void AdminPanel::on_pushButton_add_admin_clicked()
{
    if (ui->lineEdit_name_admin->text()!="" && ui->lineEdit_login_admin->text()!="" && ui->lineEdit_pass_admin->text() !="")
    {
        Admin * adm = unitadmin_panel_admin->clone();
        adm->setName(ui->lineEdit_name_admin->text());
        adm->setLogin(ui->lineEdit_login_admin->text());
        adm->setPassword(ui->lineEdit_pass_admin->text());
        this->listadmin_admin_panel->set_group_admin(adm);
        ui->lineEdit_name_admin->clear();
        ui->lineEdit_login_admin->clear();
        ui->lineEdit_pass_admin->clear();
        ui->label_status->setText("Администратор " + adm->getName() + " успешно добавлен!");
    }
    else {
        ui->label_status->setText("Все поля должны быть заполненными !");
    }
}



void AdminPanel::on_pushButton_add_dish_clicked()
{
    if (ui->lineEdit_name_dish->text() != "" )
    {
            Dish *di = new Dish();
            di->set_title(ui->lineEdit_name_dish->text());
            di->set_price(ui->lineEdit_price_dish->text().toInt());
            di->set_weigth(ui->lineEdit_weight_dish->text().toInt());
            di->set_time(ui->lineEdit_time_dish->text().toInt());
            menu->get_group(ui->comboBox_menu->currentText())->set_dish(di);
            qDebug() << "OK";

            ui->lineEdit_name_dish->clear();
            ui->lineEdit_price_dish->clear();
            ui->lineEdit_weight_dish->clear();
            ui->lineEdit_time_dish->clear();

            emit mySignal(ui->comboBox_menu->currentText(), this->listlayout.value(ui->comboBox_menu->currentText()));

    }
    else
    {
     ui->label_status->setText("Название блюда не должно быть пустым!");
    }


}


void AdminPanel::set_list_layout(QString key, QVBoxLayout* layout_box )
{
    this->listlayout.insert(key, layout_box);
}

void AdminPanel::on_buttonBox_accepted()
{

}





