#include "mainwindow.h"
#include "../tima.h"
#include "todotable.h"
#include "tododialog.h"


MainWindow::MainWindow(QWidget *parent, TodoList *list) : QMainWindow(parent) {
    todolist = list;
    QRect rec = QApplication::desktop()->availableGeometry();
    resize(rec.width(), rec.height());
    setWindowTitle("Tima");
    BorderLayout *layout = new BorderLayout;

    // menu
    QMenu *file;
    file = menuBar()->addMenu("&File");
    QAction *save = new QAction("&Save", this);
    file->addAction(save);
    connect(save, SIGNAL(triggered()), this, SLOT(save()));
    QAction *quit = new QAction("&Quit", this);
    file->addAction(quit);
    connect(quit, SIGNAL(triggered()), this, SLOT(quit()));

    // buttons
    QWidget *buttonwidget = new QWidget();
    QHBoxLayout *buttonlayout = new QHBoxLayout;
    buttonlayout->setAlignment(Qt::AlignLeft);

    QPushButton *newitem = new QPushButton;
    newitem = buttonInit(newitem, "New Item", QString("additem.png"));
    connect(newitem, SIGNAL(clicked()), this, SLOT(newItem()));
    buttonlayout->addWidget(newitem);

    QPushButton *newsubitem = new QPushButton;
    newsubitem = buttonInit(newsubitem, "New Subitem", QString("addsubitem.png"));
    buttonlayout->addWidget(newsubitem);

    QPushButton *deleteitem = new QPushButton;
    deleteitem = buttonInit(deleteitem, "Delete Item", QString("delete.png"));
    buttonlayout->addWidget(deleteitem);

    buttonwidget->setLayout(buttonlayout);
    layout->addWidget(buttonwidget, BorderLayout::North);

    // tabs
    tabs = new QTabWidget(this);
    todotable = new TodoTable(this, settings);
    tabs->addTab(todotable, tr("TODO"));

    layout->addWidget(tabs, BorderLayout::Center);

    QWidget *widget = new QWidget();
    setCentralWidget(widget);
    widget->setLayout(layout);
    show();
}

QPushButton* MainWindow::buttonInit(QPushButton *button, const char *text, QString filename){
    button->setToolTip(tr(text));
    QPixmap image("icons/"+filename);
    QIcon icon;
    icon.addPixmap(image, QIcon::Normal, QIcon::Off);
    button->setIcon(icon);
    button->setIconSize(QSize(25,25));
    button->setFixedSize(QSize(28,28));

    return button;
}

int MainWindow::save(){
    cout << "save: not yet implemented" << endl;
    return 0;
}

void MainWindow::quit(){
    QMessageBox mbox;
    mbox.setText(tr("Do you want to save your changes?"));
    mbox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    mbox.setDefaultButton(QMessageBox::Save);
    int ret = mbox.exec();
    switch (ret) {
        case QMessageBox::Save:
            save();
            break;
        case QMessageBox::Cancel:
            return;
        case QMessageBox::Discard:
            break;
        default: // we should never get here
            break;
    }
    QApplication::quit();
}

void MainWindow::newItem(){
    cout << "newItem clicked" << endl;
    if (tabs->currentIndex() == 0){ // todo list
        Todo *t = TodoDialog::getTodo(nullptr, settings);
        if (t != nullptr) {
            addTodo(t);
            cout << "newItem: todo added" << endl;
        }
        else cout << "nullptr" << endl;
    } else {

    }
    cout << "newItem: leaving function" << endl;
}

TodoTable* MainWindow::getTodoTable(){
    return todotable;
}

void MainWindow::setTodoList(TodoList *list){
    todolist = list;
}

void MainWindow::addTodo(Todo *t){
    t->setID(todolist->getID());
    todolist->addTodo(t);
    todotable->addTodo(t);
    cout << "MainWindow: Todo added" << endl;
}

void MainWindow::setSettings(Settings *s){
    settings = s;
}
