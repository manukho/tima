#ifndef TODOLIST_H
#define TODOLIST_H

#include "todo.h"
#include "gui/todotable.h"
#include <vector>

class TodoList {
public:
    TodoList();
    bool addTodo(Todo todo);
    bool removeTodo(Todo todo);
    void setTodoTable(TodoTable *table);
    int getID();

private:
    std::vector<Todo> list;
    TodoTable *todotable = nullptr;
    int getPos(Todo todo);
    int topID = 1;

};

#endif // TODOLIST_H
