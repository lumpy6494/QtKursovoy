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

private slots:
    void on_tableView_history_clicked(const QModelIndex &index);

    void on_pushButton_delete_history_clicked();

private:
    Ui::History *ui;
    QSqlTableModel *mod;
    int row;
};

#endif // HISTORY_H
