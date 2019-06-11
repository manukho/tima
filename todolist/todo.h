#ifndef TODO_H
#define TODO_H

#include <QString>
#include <QDateTime>
#include <vector>

class Todo {
public:
    int id;
    QString subject;
    QDateTime plannedstart;
    QDateTime startdate;
    QDateTime duedate;
    int completion = 0;
    int priority = 0;
    int status;
    QString description;
    std::vector<QDateTime> reminderTime;
    std::vector<QString> reminderComment;
    QDateTime plannedCompletionDate;
    Todo *parent;
    std::vector<Todo> children;
    std::vector<Todo> prerequisites;
    Todo(Todo *parent = nullptr, int id = 0);
    void setID(int i);
    void setSubject(QString subj);
    void setPlannedStart(QDateTime t);
};

#endif // TODO_H
