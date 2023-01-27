#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customcheckbox.h"
#include "result_order.h"
#include <QCheckBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QDebug>
#include <QStyle>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/mnt/0EC679B2C6799AA3/ГУАП/ООП_3_Курс/Курсовой проект/restaurant/qtdata.db");
    query = new QSqlQuery(db);


    Ivan->setName("Иван");
    groupwaiter.set_waiter_in_group(Ivan);

    admin->setName("Иванов Иван Иванович");
    admin->setLogin("admin");
    admin->setPassword("12345");

    groupadmin->set_group_admin(admin);

    table.set_table(12);

    menu.set_title("Меню");

    // Добаляем группы блюд
    one_dish.set_title("Первые блюда");
    two_dish.set_title("Вторые блюда");
    three_dish.set_title("Закуски");
    drinks.set_title("Напитки");

    // Добавляем блюда
    tea.set_title("Чай черный");
    tea.set_price(100);
    tea.set_weigth(200);
    tea.set_time(5);

    lemonad.set_title("Дюшес с мятой");
    lemonad.set_price(100);
    lemonad.set_weigth(200);
    lemonad.set_time(2);

    chicken_soup.set_title("Суп куринный");
    chicken_soup.set_price(300);
    chicken_soup.set_weigth(400);
    chicken_soup.set_time(20);

    shchi.set_title("Щи с капустой");
    shchi.set_price(200);
    shchi.set_weigth(400);
    shchi.set_time(20);

    ikra.set_title("Икра красная");
    ikra.set_price(900);
    ikra.set_weigth(600);
    ikra.set_time(20);

    utka.set_title("Утка по пекински");
    utka.set_price(400);
    utka.set_weigth(1200);
    utka.set_time(40);

    mutton.set_title("Оджахури с перцем");
    mutton.set_price(450);
    mutton.set_weigth(250);
    mutton.set_time(15);

    sushi.set_title("Филадельфия Макс");
    sushi.set_price(500);
    sushi.set_weigth(300);
    sushi.set_time(20);


    salmon.set_title("Лосось запеченый");
    salmon.set_price(450);
    salmon.set_weigth(250);
    salmon.set_time(15);

    eggplant.set_title("Цукини в масле");
    eggplant.set_price(450);
    eggplant.set_weigth(250);
    eggplant.set_time(15);

    // Добавляем группы в меню
    menu.set_group(&two_dish);
    menu.set_group(&one_dish);
    menu.set_group(&three_dish);
    menu.set_group(&drinks);

    // Добавляем блюда в группы
    one_dish.set_dish(&shchi);
    one_dish.set_dish(&chicken_soup);

    two_dish.set_dish(&salmon);
    two_dish.set_dish(&utka);
    two_dish.set_dish(&mutton);

    three_dish.set_dish(&eggplant);
    three_dish.set_dish(&ikra);
    three_dish.set_dish(&sushi);

    drinks.set_dish(&lemonad);
    drinks.set_dish(&tea);

    order.set_title("Чек");

    if (db.open())
    {
        ui->statusbar->showMessage("Подключились к Базе данных");

    }else {

        ui->statusbar->showMessage("Не удалось подключиться к базе данныx!");
    }
    query->exec("CREATE TABLE historyorder(id INTEGER PRIMARY KEY, number INTEGER, waiter TEXT, timeorder INTEGER, summ INTEGER, dishid INTEGER, FOREIGN KEY(dishid) REFERENCES orderdish(id));");







//    qDebug() << groupadmin->get_all_admin().remove("admin");
//    qDebug() <<groupadmin->get_all_admin().size();
//    qDebug() << groupadmin->get_all_admin().take("admin");
//     groupadmin->get_all_admin().take("admin");
//    qDebug() <<groupadmin->get_all_admin().size();
}



void MainWindow::createUI()
{
    this->ui->label_menu->setText(menu.get_title());
    this->ui->label_onedish->setText(menu.get_group("Первые блюда")->get_title());
    this->show_dish("Первые блюда", ui->Layout_onedish);

    this->ui->label_twodish->setText(menu.get_group("Вторые блюда")->get_title());
    this->show_dish("Вторые блюда", ui->Layout_twodish);

    this->ui->label_threedish->setText(menu.get_group("Закуски")->get_title());
    this->show_dish("Закуски", ui->Layout_threedish);

    this->ui->label_drinks->setText(menu.get_group("Напитки")->get_title());
    this->show_dish("Напитки", ui->Layout_drinks);

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::boxclick()
{
   CustomCheckbox *check = (CustomCheckbox *) sender();

   if (check->isChecked())
   {
       order.set_orderitems(check->items);

       ui->statusbar->showMessage(check->items->get_dish_title());
//       qDebug()<< check->items->get_price();

   }else
   {

     ui->statusbar->clearMessage();
//     qDebug() << check->items->get_dish_title();
     order.del_items(check->items->get_dish_title());

   }

}

void MainWindow::view_check()
{
    ui->textCheck->clear();
    for(auto ord : order.get_all_orderitems())
        if (ord->get_amount() > 0)
            ui->textCheck->append(ord->get_dishes().get_title() +"\t\t"+ QString::number(ord->get_amount()) + "\t\t" + QString::number(ord->get_price()) + "р");
}

void MainWindow::view_order_summ()
{
    int order_summ = 0;
    for (auto price: order.get_all_orderitems())
    {
        order_summ+=price->get_price();
    }
    ui->lcdNumber->display(order_summ);
}



void MainWindow::on_Order_clicked()
{
    order.set_table(&table);
    QMap<int, QStringList> liststr;
    int index =0;
    int size_order = order.get_all_orderitems().size();
    int max_time_dish = 0;
    if (size_order > 0)
    {
        result_window =new Result_order(this);
        result_window->show();


      for(auto res : order.get_all_orderitems())
      {

          if (res->get_amount() > 0)
          {
              QStringList value_in_table;
              value_in_table.append(res->get_dish_title());
              value_in_table.append(QString::number(res->get_amount()));
              value_in_table.append(QString::number(res->get_price()));

              if (max_time_dish < res->get_dishes().get_time())
                      max_time_dish = res->get_dishes().get_time();


              liststr.insert(index, value_in_table);
              index++;
          }

      }
      int randomValue = (qrand() % groupwaiter.get_all_waiters().size())+1;

      qDebug() << randomValue;
      result_window->set_table_result_check(liststr, size_order);
      result_window->set_textbrowser("\n\n<b>Номер вашего столика: <\b>" + QString::number(order.get_table()->get_table()));
      result_window->set_textbrowser("\n<b>Ваш Официант: <\b>" + groupwaiter.get_waiters_is_group(randomValue)->getName() + "\n");
      result_window->set_textbrowser("<b>Максимальное время подачи заказа: <\b>" + QString::number(max_time_dish)+" минут\n");
      result_window->set_textbrowser("\n\n<b>Итого: <\b>" + QString::number( ui->lcdNumber->intValue())+ " рублей");

    } else

    {
        ui->statusbar->showMessage("Ваш заказ пуст!");
    }


    this->query->exec("INSERT INTO historyorder (id,number, waiter,timeorder, summ, dishid)"
                      "VALUES (1, 1222, Ivan, 20, 1900,1)");

}



void MainWindow::on_action_4_triggered()
{
    login_admin=new Login_Admin(this);
    login_admin->set_admin_list(groupadmin);
    login_admin->show();

    admin_panel = new AdminPanel(this);
    login_admin->set_admin_panel(admin_panel);

    admin_panel->set_waiter_panel_admin(Ivan);
    admin_panel->set_waiter_list(&groupwaiter);
    admin_panel->set_admin_list(groupadmin);
    admin_panel->set_unitadmin_panel_admin(admin);
    admin_panel->set_menu(&menu);
    admin_panel->set_combobox();
    admin_panel->view_admin();
    admin_panel->view_waiter();
    admin_panel->set_combobox_admin();
    admin_panel->set_combobox_waiter();
    admin_panel->set_db_model(model, db);


    admin_panel->set_list_layout("Первые блюда", ui->Layout_onedish);
    admin_panel->set_list_layout("Вторые блюда", ui->Layout_twodish);
    admin_panel->set_list_layout("Закуски", ui->Layout_threedish);
    admin_panel->set_list_layout("Напитки", ui->Layout_drinks);

//    connect(admin_panel, SIGNAL(mySignal()), this, SLOT(delete_dish_one()));
    connect(admin_panel, SIGNAL(mySignal(QString, QVBoxLayout*)), this, SLOT(show_dish(QString, QVBoxLayout*)));
//    connect(admin_panel, SIGNAL(mySignal_delete(QString, QVBoxLayout*)), this, SLOT(show_dish(QString, QVBoxLayout*)));
}


void MainWindow::show_dish(QString title_dish, QVBoxLayout *la)
{
    qDebug() << "Отрисовка";
    delete_dish_one(la);

    for (int i = 1; i <= menu.get_group(title_dish)->get_dish().size(); i++)
    {
      Dish *dish = menu.get_group(title_dish)->get_dish().value(i);
      OrderItems *orderitems = new OrderItems(dish);

      QString price =  QString::number(dish->get_price());
      QString weight = QString::number(dish->get_weigth());
      QString time =  QString::number(dish->get_time());


      QHBoxLayout *lay = new QHBoxLayout();

      CustomCheckbox *check = new CustomCheckbox();
      check->setText(dish->get_title());
      check->add_orderitems(orderitems);

      QSpinBox *spin = new QSpinBox();
      spin->setMaximumSize(70,30);

      spin->setValue(orderitems->get_amount());
      lay->addWidget(check);
      lay->addWidget(spin);

      la->addLayout(lay);
      la->addWidget(new QLabel("Цена: " + price +"р"+ "\t" + "Вес: " + weight +"г" + "\t" + "Время приготовления: " + time +" м" ));

      connect(spin, SIGNAL(valueChanged(int)),orderitems,SLOT(set_amount_slot(int)));
      connect(spin, SIGNAL(valueChanged(int)),this,SLOT(view_check()));
      connect(spin, SIGNAL(valueChanged(int)),this,SLOT(view_order_summ()));
      connect(check,SIGNAL(stateChanged(int)), this,SLOT(boxclick()));
      connect(check, SIGNAL(stateChanged(int)), this, SLOT(view_check()));
      connect(check, SIGNAL(stateChanged(int)), this, SLOT(view_order_summ()));
    }
}



void MainWindow::delete_dish_one(QVBoxLayout *la)
    {
//        qDebug() <<ui->Layout_onedish->count();

        QLayoutItem *child;
        while ((child = la->takeAt(0)) != nullptr)
        {
//            qDebug() << child->layout();
            if (child->layout() != nullptr)
            {
                QLayoutItem *child1;
                while ((child1 = child->layout()->takeAt(0)) != nullptr)
                {
                    if (child1 != nullptr)
                    {
//                        qDebug() << child1->widget();
                        delete child1->widget(); // delete the widget
                        delete child1;   // delete the layout item
                    }

                }
            }
            delete child->widget(); // delete the widget
            delete child;   // delete the layout item

   }
  }



void MainWindow::on_action_3_triggered()
{
     return QApplication::exit();
}
