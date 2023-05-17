#include "role.h"

Role::Role()
{
    setId(255);
    setName("Set Name");
}

void Role::setId(uint32_t id)
{
    m_id=id;
}

void Role::setName(QString name)
{
    m_name=name;
}


uint32_t Role::id()
{
    return m_id;
}

QString Role::name()
{
    return m_name;
}
