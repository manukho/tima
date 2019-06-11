#include "todotable.h"
#include <iostream>
#include <QHeaderView>
#include <QStringView>
#include <QTimer>
#include "timeleftitem.h"
#include <QSpinBox>

using namespace std;

TodoTable::TodoTable(QWidget *parent, Settings *settings) : QTableWidget(0, 9, parent){
    if (settings == nullptr){
        defaultSettings();
    }
    setupTable();

    // setup timer for updating remaining time
    timer = new QTimer(this);
    timer->setInterval(600);
    timer->callOnTimeout(SLOT(updateTimeLeft()));
}

void TodoTable::addTodo(Todo *todo){
    insertRow(rowCount());
    int row = rowCount() - 1;

    setItem(row, 0, new QTableWidgetItem(QString::number(todo->id)));
    setItem(row, 1, new QTableWidgetItem(todo->subject));
    setItem(row, 2, new TimeLeftItem(&(todo->duedate)));
    setItem(row, 3, new QTableWidgetItem(todo->plannedstart.toString(dateFormat)));
    setItem(row, 4, new QTableWidgetItem(todo->duedate.toString(dateFormat)));
    setItem(row, 5, new QTableWidgetItem(todo->startdate.toString(dateFormat)));
    setItem(row, 6, new QTableWidgetItem(todo->plannedCompletionDate.toString(dateFormat)));
    QSpinBox *completionBox = new QSpinBox(this);
    completionBox->setRange(0,100);
    completionBox->setValue(todo->completion);
    setCellWidget(row, 7, completionBox);
    QSpinBox *priorityBox = new QSpinBox(this);
    priorityBox->setRange(1, 10);
    priorityBox->setValue(todo->priority);
    setCellWidget(row, 8, priorityBox);

    // set flags
    for (auto && col : {0, 2, 3, 4, 5, 6}){
        item(row, col)->setFlags(item(row,col)->flags() ^ Qt::ItemIsSelectable ^ Qt::ItemIsEditable);
    }

    // add tooltip
    for (int i = 0; i < 7; i++){
        cout << "setting tooltip for item at (" << row << ", " << i << ")" << endl;
        item(row, i)->setToolTip(todo->description);
    }
    
}

void TodoTable::setupTable(){
    horizontalHeader = new QHeaderView(Qt::Horizontal, this);
    horizontalHeader->setSectionsMovable(true);
    setHorizontalHeader(horizontalHeader);
    verticalHeader = new QHeaderView(Qt::Vertical, this);
    verticalHeader->hide();
    setVerticalHeader(verticalHeader);

    QString headerNames[] = {"ID", "Subject", "Time Left", "Planned Start Date", "Due Date", "Start Date", "Planned End Date",  "Completion", "Priority"};
    int width[] = {15, 500, 115, 115, 115, 115, 115, 70, 70};
    for (int i = 0; i < 9; i++){
        setHorizontalHeaderItem(i, new QTableWidgetItem(headerNames[i]));
        setColumnWidth(i, width[i]);
    }
}

void TodoTable::defaultSettings(){
    dateFormat = QString("dd.MM.yyyy hh:mm");
}

void TodoTable::updateTimeLeft(){
    for (int row = 0; row < rowCount(); row++){
        QDateTime d = QDateTime::fromString(item(row, 4)->text());
        ((TimeLeftItem*)(item(row, 2)))->update(&d);
    }
}
