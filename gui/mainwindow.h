#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QRect>
#include <QDesktopWidget>
#include <QPushButton>
#include "borderlayout.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

private:
    QPushButton* buttonInit(QPushButton *button, const char *text, QString filename);

signals:

public slots:
};

#endif // MAINWINDOW_H
