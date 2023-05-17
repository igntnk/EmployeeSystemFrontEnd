#ifndef AUTHORITY_H
#define AUTHORITY_H

#include <QString>
#include "roleauthority.h"

class Authority
{
public:
    Authority();
    ~Authority();

    RoleAuthority* roleauthority();
    QString name();

    void setRoleauthority(RoleAuthority*);
    void setName(QString);

private:
    RoleAuthority* m_roleauthority;
    QString m_name;
};

#endif // AUTHORITY_H
