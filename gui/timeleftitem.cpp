#include "timeleftitem.h"
#include <QDateTime>
#include <QtMath>

TimeLeftItem::TimeLeftItem(){}

TimeLeftItem::TimeLeftItem(QDateTime *dt){
    update(dt);
}

QString TimeLeftItem::getDHM(qint64 secs){
    QString dhm;
    if (secs < 0){
        dhm += QString("-");
        secs = -secs;
    }
    qint64 days = qFloor(secs / 86400);
    dhm += QString::number(days);
    dhm += QString("d ");
    secs %= (86400);
    qint64 hours = qFloor(secs / 3600);
    dhm += QString::number(hours);
    dhm += QString("h ");
    secs %= 3600;
    qint64 minutes = qFloor((secs / 60));
    dhm += QString::number(minutes);
    dhm += QString("m");
    return dhm;
}

void TimeLeftItem::update(QDateTime *dt){
    QDateTime current = QDateTime::currentDateTime();
    qint64 secs = -(dt->secsTo(current));
    setText(getDHM(secs));
}
