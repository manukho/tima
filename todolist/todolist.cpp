#include "todolist.h"

TodoList::TodoList(){
    std::vector<Todo> list;
}

bool TodoList::addTodo(Todo todo){
    if (todo.id == 0){
        return false;
    }
    list.push_back(todo);
    return true;
}

bool TodoList::removeTodo(Todo todo){
    int pos = getPos(todo);
    if (pos == -1){ // if it doesn't exist
        return false;
    }
    list.erase(list.begin() + pos);
    return true;
}

int TodoList::getPos(Todo todo){
    for (unsigned long i=0; i < list.size(); i++) {
        if (list.at(i).id == todo.id)
            return i;
    }
    return -1;
}

void TodoList::setTodoTable(TodoTable *table){
    todotable = table;
}

int TodoList::getID(){
    return topID++;
}
