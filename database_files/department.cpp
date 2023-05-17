#include "department.h"

Department::Department()
{
    setId(255);
    setName("Set Name");
}

void Department::setId(uint32_t id)
{
    m_id=id;
}

void Department::setName(QString name)
{
    m_name=name;
}

uint32_t Department::id()
{
    return m_id;
}

QString Department::name()
{
    return m_name;
}

