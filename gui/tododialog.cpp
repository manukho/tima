#include "tododialog.h"
#include "tima.h"
#include <QPushButton>
#include <QCheckBox>
#include <QDateTimeEdit>
#include <QLabel>

TodoDialog::TodoDialog(QWidget *parent, Settings *settings){
    this->setParent(parent);
    if (settings != nullptr){
        dateDisplay = settings->DateDisplay;
        defaultDueTime = settings->dueTime;
    } else { // shouldn't happen but let's just set some default values
        dateDisplay = "dd.MM.yyyy hh:mm";
        defaultDueTime = QTime(23, 59);
    }
    now = QDateTime::currentDateTime();
    defaultDueDateTime = QDateTime(QDate::currentDate(), defaultDueTime);

    QBoxLayout *l = new QBoxLayout(QBoxLayout::TopToBottom, this);
    setLayout(l);

    tabWidget = new QTabWidget(this);

    QWidget *p1 = new QWidget(this);
    QFormLayout *fl1 = new QFormLayout(p1);
    p1->setLayout(fl1);

    subjectEdit = new QLineEdit();
    fl1->addRow(tr("Subject"), subjectEdit);

    descriptionEdit = new QTextEdit();
    fl1->addRow(tr("Description"), descriptionEdit);

    QWidget *plannedStartWidget = new QWidget(this);
    plannedStartCheck = new QCheckBox(plannedStartWidget);
    QBoxLayout *psl = new QBoxLayout(QBoxLayout::LeftToRight);
    plannedStartWidget->setLayout(psl);
    plannedStartCheck->setCheckState(Qt::Checked);
    connect(plannedStartCheck, SIGNAL(clicked()), this, SLOT(plannedStartCalendar()));
    psl->addWidget(plannedStartCheck);
    plannedStartEdit = new QDateTimeEdit(plannedStartWidget);
    plannedStartEdit->setCalendarPopup(true);
    plannedStartEdit->setDisplayFormat(dateDisplay);
    plannedStartEdit->setDateTime(now);
    plannedStartCalendar();
    psl->addWidget(plannedStartEdit);
    fl1->addRow("Planned Start Time", plannedStartWidget);

    QWidget *startWidget = new QWidget(this);
    startCheck = new QCheckBox(startWidget);
    startCheck->setCheckState(Qt::Unchecked);
    QBoxLayout *sl = new QBoxLayout(QBoxLayout::LeftToRight);
    startWidget->setLayout(sl);
    connect(startCheck, SIGNAL(clicked()), this, SLOT(startCalendar()));
    sl->addWidget(startCheck);
    startEdit = new QDateTimeEdit(startWidget);
    startEdit->setCalendarPopup(true);
    startEdit->setDisplayFormat(dateDisplay);
    startEdit->setDateTime(now);
    startCalendar();
    sl->addWidget(startEdit);
    fl1->addRow("Start Time", startWidget);

    QWidget *endWidget = new QWidget(this);
    endCheck = new QCheckBox(endWidget);
    endCheck->setCheckState(Qt::Checked);
    QBoxLayout *el = new QBoxLayout(QBoxLayout::LeftToRight);
    endWidget->setLayout(el);
    connect(endCheck, SIGNAL(clicked()), this, SLOT(endCalendar()));
    el->addWidget(endCheck);
    endEdit = new QDateTimeEdit(endWidget);
    endEdit->setCalendarPopup(true);
    endEdit->setDisplayFormat(dateDisplay);
    endEdit->setDateTime(defaultDueDateTime);
    endCalendar();
    el->addWidget(endEdit);
    fl1->addRow("End Time", endWidget);

    QWidget *plannedEndWidget = new QWidget(this);
    plannedEndCheck = new QCheckBox(plannedEndWidget);
    plannedEndCheck->setCheckState(Qt::Unchecked);
    QBoxLayout *pel = new QBoxLayout(QBoxLayout::LeftToRight);
    plannedEndWidget->setLayout(pel);
    cout << "plannedEndCheck is checked? " << plannedEndCheck->isChecked() << endl;
    connect(plannedEndCheck, SIGNAL(clicked()), this, SLOT(plannedEndCalendar()));
    pel->addWidget(plannedEndCheck);
    plannedEndEdit = new QDateTimeEdit(plannedEndWidget);
    plannedEndEdit->setCalendarPopup(true);
    plannedEndEdit->setDisplayFormat(dateDisplay);
    plannedEndEdit->setDateTime(defaultDueDateTime);
    plannedEndCalendar();
    pel->addWidget(plannedEndEdit);
    fl1->addRow("Planned End Time", plannedEndWidget);

    prioritySpinner = new QSpinBox(this);
    prioritySpinner->setRange(1,10);
    fl1->addRow(tr("Priority"), prioritySpinner);

    QWidget *p2 = new QWidget(this);


    tabWidget->addTab(p1, "Tab 1");
    tabWidget->addTab(p2, "Tab 2");
    l->addWidget(tabWidget);

    buttonBox = new QDialogButtonBox(this);
    buttonBox->addButton(QDialogButtonBox::Cancel);
    buttonBox->addButton(QDialogButtonBox::Ok);
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(ok()));

    l->addWidget(buttonBox);
}

TodoDialog::~TodoDialog(){}



void TodoDialog::cancel(){
    cout << "cancel!!!" << endl;
    reject();
}

void TodoDialog::ok(){
    todo = new Todo();
    todo->subject = subjectEdit->text();
    todo->description = descriptionEdit->toPlainText();
    if (plannedStartCheck->isChecked()){
        todo->plannedstart = plannedEndEdit->dateTime();
    }
    if (plannedEndCheck->isChecked()){
        todo->plannedCompletionDate = plannedEndEdit->dateTime();
    }
    if (startCheck->isChecked()){
        todo->startdate = startEdit->dateTime();
    }
    if (endCheck->isChecked()){
        todo->duedate = endEdit->dateTime();
    }
    todo->priority = prioritySpinner->value();
    // TODO: add rest
    accept();
}

Todo* TodoDialog::getTodo(QWidget* parent, Settings *settings) {
    TodoDialog dialog(parent, settings);
    int exec = dialog.exec();
    if (exec == QDialog::Accepted){
        cout << "accepted" << endl;
        Todo *t = dialog.todo;
        dialog.close();
        return t;
    } else {
        cout << "not accepted" << endl;
        //dialog.close();
        return nullptr;
    }
}

void TodoDialog::plannedStartCalendar(){
    plannedStartEdit->setEnabled(plannedStartCheck->isChecked());
}

void TodoDialog::startCalendar(){
    startEdit->setEnabled(startCheck->isChecked());
}

void TodoDialog::plannedEndCalendar(){
    plannedEndEdit->setEnabled(plannedEndCheck->isChecked());
}

void TodoDialog::endCalendar(){
    endEdit->setEnabled(endCheck->isChecked());}
