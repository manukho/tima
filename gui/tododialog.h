#ifndef TODODIALOG_H
#define TODODIALOG_H

#include <QDialog>
#include "todolist/todo.h"
#include <QLineEdit>
#include <QTextEdit>
#include <QSpinBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QCheckBox>
#include <QTableWidget>
#include "settings.h"

class TodoDialog : public QDialog {
    Q_OBJECT
public:
    TodoDialog(QWidget *parent = nullptr, Settings *settings = nullptr);
    ~TodoDialog();
    static Todo* getTodo(QWidget* parent = nullptr, Settings *settings = nullptr);

private:
    QString dateDisplay;
    QTabWidget *tabWidget;
    QStringList inputs;
    QLineEdit *subjectEdit;
    QTextEdit *descriptionEdit;
    QCheckBox *plannedStartCheck;
    QCheckBox *startCheck;
    QCheckBox *plannedEndCheck;
    QCheckBox *endCheck;
    QDateTimeEdit *plannedStartEdit;
    QDateTimeEdit *startEdit;
    QDateTimeEdit *plannedEndEdit;
    QDateTimeEdit *endEdit;
    QSpinBox *prioritySpinner;
    QDialogButtonBox *buttonBox;
    void popupCalendar(QDateTimeEdit *edit);
    Todo *todo;
    QTime defaultDueTime;
    QDateTime now;
    QDateTime defaultDueDateTime;

signals:

public slots:
    void cancel();
    //Todo* ok(Todo *todo = nullptr, Todo *parent = nullptr);
    void ok();
    void plannedStartCalendar();
    void startCalendar();
    void plannedEndCalendar();
    void endCalendar();
};

#endif // TODODIALOG_H
