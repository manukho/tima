#ifndef TODOTABLE_H
#define TODOTABLE_H

#include <QTableWidget>
#include "todolist/todo.h"
#include "settings.h"

class TodoTable : public QTableWidget {
//    Q_OBJECT
public:
    TodoTable(QWidget *parent, Settings *settings);
    void addTodo(Todo *todo);
    void removeTodo(Todo todo);
    void sort(QString how);
    void setVisibleColumns(bool *values);

private:
    void setupTable();
    void defaultSettings();
    QTimer *timer;
    QHeaderView *horizontalHeader;
    QHeaderView *verticalHeader;
    QString dateFormat;

private slots:
    void updateTimeLeft();
};

#endif // TODOTABLE_H
