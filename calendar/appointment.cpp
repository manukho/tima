#include "appointment.h"

Appointment::Appointment() {

}


Appointment::Appointment(std::string t, QDateTime st, QDateTime en, std::string n, std::string p, bool b, QTime bb, QTime ba){
    title = t;
    start = st;
    end = en;
    note = n;
    place = p;
    blocked = b;
    blockBefore = bb;
    blockAfter = ba;
}
