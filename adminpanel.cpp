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
    for(auto *res : menu->get_all_group())
    {
    //          ui->comboBox_menu->addItem(res->get_title());
        qDebug() << res->get_title();
        ui->comboBox_menu->addItem(res->get_title());
    }
}

void AdminPanel::set_combobox_admin()
{
    if (listadmin_admin_panel->get_all_admin().size() > 0)
    {
        for(auto *res : listadmin_admin_panel->get_all_admin())
        {
            ui->delete_admin->addItem(res->getName());
        }
    }

}

void AdminPanel::set_combobox_waiter()
{
    for(auto *res : listadmin_waiter_panel->get_all_waiters())
        {
            ui->comboBox_delete_waiter->addItem(res->getName());
        }
}


void AdminPanel::view_waiter()
{
    for(auto* res : listadmin_waiter_panel->get_all_waiters())
    {
        ui->textBrowser_waiter->append(res->getName());

    }

//    qDebug() << this->listadmin_waiter_panel->get_all_waiters().size();
}

void AdminPanel::view_admin()
{
    if (listadmin_admin_panel->get_all_admin().size()>0)
    {
        for(auto res : listadmin_admin_panel->get_all_admin())
        {
            ui->textBrowser_admin->append(res->getName());

        }

    }


//    qDebug() << this->listadmin_waiter_panel->get_all_waiters().size();
}


void AdminPanel::set_db_model(QSqlTableModel *model, QSqlDatabase &db)
{
    this->model= model;
    this->db = db;

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
        ui->comboBox_delete_waiter->addItem(wait->getName());
        ui->textBrowser_waiter->append(wait->getName());
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
        ui->textBrowser_admin->append(adm->getName());
        ui->delete_admin->addItem(adm->getName());
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
            ui->label_status->setText("Новое блюдо " + di->get_title() + " успешно добавлено!");


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


void AdminPanel::on_pushButton_delete_admin_clicked()
{
    qDebug() << this->listadmin_admin_panel->get_all_admin().size();
    for(auto* res : listadmin_admin_panel->get_all_admin())
    {

            if (ui->delete_admin->currentText() == res->getName())
            {
                   listadmin_admin_panel->del_items(res->getLogin());

                ui->label_status->setText("Администратор "+ res->getName()+" удален!");

            }

    }

    qDebug() << this->listadmin_admin_panel->get_all_admin().size();
}

void AdminPanel::on_pushButton_delete_waiter_clicked()
{

    for (int i =0; i < listadmin_waiter_panel->get_all_waiters().size(); i++)
    {
        if (listadmin_waiter_panel->get_all_waiters().size() > 1)
        {
            if (ui->comboBox_delete_waiter->currentText() == listadmin_waiter_panel->get_waiters_is_group(i+1)->getName())
            {
                qDebug() << listadmin_waiter_panel->get_waiters_is_group(i+1)->getName();
                listadmin_waiter_panel->del_items_waiter(i+1);

                ui->label_status->setText("Официант "+ listadmin_waiter_panel->get_waiters_is_group(i)->getName()+" удален!");
            }
        }
        else
        {
         ui->label_status->setText("В системе должен быть хотябы 1 официант");
        }

    }

}

void AdminPanel::on_pushButton_history_clicked()
{
    History *his = new History();
    this->model = new QSqlTableModel(this, db);
    this->model->setTable("historyorder");
    this->model->select();
    his->show_history(model);
    his->show();


}
