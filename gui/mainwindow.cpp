#include "mainwindow.h"
#include "../tima.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QRect rec = QApplication::desktop()->availableGeometry();
    resize(rec.width(), rec.height());
    setWindowTitle("Tima");
    BorderLayout *layout = new BorderLayout;
    QResource::registerResource("resources.qrc");

    // menu
    QMenu *file;
    QAction *quit = new QAction("&Quit", this);
    file = menuBar()->addMenu("&File");
    file->addAction(quit);
    connect(quit, &QAction::triggered, qApp, QApplication::quit);

    // buttons
    QWidget *buttonwidget = new QWidget();
    QHBoxLayout *buttonlayout = new QHBoxLayout;
    buttonlayout->setAlignment(Qt::AlignLeft);

    QPushButton *newitem = new QPushButton;
    newitem = buttonInit(newitem, "New Item", QString("additem.png"));
    buttonlayout->addWidget(newitem, Qt::AlignLeft);

    QPushButton *newsubitem = new QPushButton;
    newsubitem = buttonInit(newsubitem, "New Subitem", QString("addsubitem.png"));
    buttonlayout->addWidget(newsubitem);

    buttonwidget->setLayout(buttonlayout);
    layout->addWidget(buttonwidget, BorderLayout::North);

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
