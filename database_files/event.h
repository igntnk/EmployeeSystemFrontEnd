#ifndef EVENT_H
#define EVENT_H

#include "employee.h"

class Event
{
public:
    Event();

    int id();
    QDate date();
    QString name();
    Employee *employee();

    void setId(int);
    void setDate(QDate);
    void setName(QString);
    void setEmployee(Employee*);

private:
    int m_id = 255;
    QDate m_date = QDate::currentDate();
    QString m_name = "Employee Creation";
    Employee* m_employee = new Employee();
};

#endif // EVENT_H
