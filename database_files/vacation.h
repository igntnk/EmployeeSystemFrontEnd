#ifndef VACATION_H
#define VACATION_H

#include <QDate>
#include "employee.h"

class Vacation
{
public:
    Vacation();
    ~Vacation();

    void setId(uint32_t);
    void setBeginDate(QDate);
    void setEndDate(QDate);
    void setEmployee(Employee*);

    uint32_t id();
    QDate beginDate();
    QDate endDate();
    Employee* employee();

private:

    int m_id;
    QDate m_begin_date;
    QDate m_end_date;
    Employee* m_employee;

};

#endif // VACATION_H
