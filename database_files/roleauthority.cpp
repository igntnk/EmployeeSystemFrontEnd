
#include "roleauthority.h"

RoleAuthority::RoleAuthority()
{
    setId(255);
    m_role = new Role();
    setAuthority_id(255);
}

uint32_t RoleAuthority::id()
{
    return m_id;
}

Role *RoleAuthority::role()
{
    return m_role;
}

uint32_t RoleAuthority::authority_id()
{
    return m_authority_id;
}

void RoleAuthority::setId(uint32_t id)
{
    m_id = id;
}

void RoleAuthority::setRole(Role *role)
{
    m_role = role;
}

void RoleAuthority::setAuthority_id(uint32_t authority_id)
{
    m_authority_id = authority_id;
}

