#include "event.h"

Event::Event()
{

}

Event::~Event()
{
    if(m_employee != nullptr)
    {
        delete m_employee;
    }
}

int Event::id()
{
    return m_id;
}

QDate Event::date()
{
    return m_date;
}

QString Event::name()
{
    return m_name;
}

void Event::setId(int id)
{
    m_id = id;
}

void Event::setDate(QDate date)
{
    m_date = date;
}

void Event::setName(QString name)
{
    m_name = name;
}

void Event::setEmployee(Employee *employee)
{
    if(m_employee!=nullptr){delete m_employee;}
    m_employee = employee;
}

