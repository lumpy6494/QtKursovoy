#ifndef HISTORY_H
#define HISTORY_H

#include <QDialog>
#include <QSqlTableModel>


namespace Ui {
class History;
}

class History : public QDialog
{
    Q_OBJECT

public:
    explicit History(QWidget *parent = nullptr);
    void show_history(QSqlTableModel * model);

    ~History();

private:
    Ui::History *ui;
};

#endif // HISTORY_H
