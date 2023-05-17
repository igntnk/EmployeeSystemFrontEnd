#include "vacation.h"

Vacation::Vacation()
{
    setId(255);
    setBeginDate(QDate::currentDate());
    setEndDate(QDate::currentDate().addDays(14));
    m_employee = new Employee();
}

Vacation::~Vacation()
{
    if(m_employee != nullptr)
    {
        delete m_employee;
    }
}

void Vacation::setId(uint32_t id)
{
    m_id = id;
}

void Vacation::setBeginDate(QDate begin_date)
{
    m_begin_date = begin_date;
}

void Vacation::setEndDate(QDate end_date)
{
    m_end_date = end_date;
}

void Vacation::setEmployee(Employee *employee)
{
    if(m_employee != nullptr){delete m_employee;}
    m_employee = employee;
}

uint32_t Vacation::id()
{
    return m_id;
}

QDate Vacation::beginDate()
{
    return m_begin_date;
}

QDate Vacation::endDate()
{
    return m_end_date;
}

Employee *Vacation::employee()
{
    return m_employee;
}


