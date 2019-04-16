#include "todolist.h"

TodoList::TodoList(){
    vector<Todo> list;
}

void TodoList::addTodo(Todo todo){
    list.push_back(todo);
}

void TodoList::removeTodo(Todo todo){
    list.erase(list.begin() + getPos(todo));
}

int TodoList::getPos(Todo todo){
    for (int i=0; i < list.size(); i++) {
        if (list.at(i).id == todo.id)
            return i;
    }
    return -1;
}
