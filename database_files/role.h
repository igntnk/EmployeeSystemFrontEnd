#ifndef ROLE_H
#define ROLE_H

#include <QString>

class Role
{
public:
    Role();

    void setId(uint32_t);
    void setName(QString);

    uint32_t id();
    QString name();

private:
    uint32_t m_id;
    QString m_name;
};

#endif // ROLE_H
