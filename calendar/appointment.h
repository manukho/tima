#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <QDateTime>

class Appointment {
public:
    Appointment();
    Appointment(std::string t, QDateTime st, QDateTime en, std::string n = "", std::string p = "",
                bool b = true, QTime bb = QTime(0,0), QTime ba = QTime(0, 0));
    std::string title;
    QDateTime start;
    QDateTime end;
    std::string place;
    std::string note;
    bool blocked = 0;
    QTime blockBefore = QTime(0, 0);
    QTime blockAfter = QTime(0, 0);
};

#endif // APPOINTMENT_H
