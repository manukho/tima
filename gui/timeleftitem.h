#ifndef TIMELEFTITEM_H
#define TIMELEFTITEM_H

#include <QTableWidgetItem>


class TimeLeftItem : public QTableWidgetItem{
public:
    TimeLeftItem();
    TimeLeftItem(QDateTime *dt);
    void update(QDateTime *dt);
private:
    QString getDHM(qint64 secs);
};

#endif // TIMELEFTITEM_H
