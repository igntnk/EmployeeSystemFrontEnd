#include "authority.h"

Authority::Authority()
{
    m_roleauthority = new RoleAuthority();
    setName("Set Name");
}

Authority::~Authority()
{
    if(m_roleauthority != nullptr)
    {
        delete m_roleauthority;
    }
}

RoleAuthority *Authority::roleauthority()
{
    return m_roleauthority;
}

QString Authority::name()
{
    return m_name;
}

void Authority::setRoleauthority(RoleAuthority *roleauthority)
{
    if(m_roleauthority!=nullptr){delete m_roleauthority;}
    m_roleauthority =roleauthority;
}

void Authority::setName(QString name)
{
    m_name = name;
}

