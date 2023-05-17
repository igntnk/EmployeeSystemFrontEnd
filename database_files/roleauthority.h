#ifndef ROLEAUTHORITY_H
#define ROLEAUTHORITY_H

#include "role.h"

class RoleAuthority
{
public:
    RoleAuthority();

    uint32_t id();
    Role* role();
    uint32_t authority_id();

    void setId(uint32_t);
    void setRole(Role*);
    void setAuthority_id(uint32_t);

private:
    uint32_t m_id;
    Role* m_role;
    uint32_t m_authority_id;
};

#endif // ROLEAUTHORITY_H
