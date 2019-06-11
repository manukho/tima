#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>
#include <QTime>

class Settings {
public:
    Settings();
    QString DateDisplay = QString("dd.MM.yyyy");
    QTime dueTime = QTime(23, 59);
};

#endif // SETTINGS_H
