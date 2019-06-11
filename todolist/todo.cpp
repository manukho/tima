#include "todo.h"
#include "todolist.h"

Todo::Todo(Todo* p, int i){
    parent = p;
    id = i;
}

void Todo::setSubject(QString subj){
    subject = subj;
}

void Todo::setID(int i){
    id = i;
}
