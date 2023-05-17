#include "authority.h"

Authority::Authority()
{
    m_roleauthority = new RoleAuthority();
    setName("Set Name");
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
    delete m_roleauthority;
    m_roleauthority =roleauthority;
}

void Authority::setName(QString name)
{
    m_name = name;
}

