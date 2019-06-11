#ifndef TIMA_H
#define TIMA_H

#include <iostream>
#include <filesystem>
#include "gui/mainwindow.h"
#include "todolist/todolist.h"
#include <QApplication>
#include <QAction>
#include <fstream>
#include <QResource>

using namespace std;

namespace fs = std::filesystem;

class Tima {

public:
    Tima(int, char**);
    TodoList *todolist;
private:

};

#endif // TIMA_H
