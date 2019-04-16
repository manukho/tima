#ifndef TODOLIST_H
#define TODOLIST_H

#include "tima.h"
#include "todo.h"
#include <vector>

class TodoList {
public:
    TodoList();
    void addTodo(Todo todo);
    void removeTodo(Todo todo);

private:
    vector<Todo> list;
    int getPos(Todo todo);
};

#endif // TODOLIST_H
