#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QRect>
#include <QDesktopWidget>
#include <QPushButton>
#include "borderlayout.h"
#include <QAction>
#include "todotable.h"
#include <QMessageBox>
#include "todolist/todolist.h"
#include "settings.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr, TodoList *todolist = nullptr);
    TodoTable* getTodoTable();
    void setTodoList(TodoList *list);
    void setSettings(Settings *settings);

private:
    QPushButton* buttonInit(QPushButton *button, const char *text, QString filename);
    TodoTable *todotable;
    TodoList *todolist;
    Settings *settings;
    QTabWidget *tabs;
    void addTodo(Todo *t);

signals:

public slots:
    int save();
    void quit();
    void newItem();
};

#endif // MAINWINDOW_H
