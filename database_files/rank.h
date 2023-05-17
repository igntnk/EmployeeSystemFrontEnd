#ifndef RANK_H
#define RANK_H

#include <iostream>
#include <QString>
#include "department.h"

class Rank
{
public:
    Rank();
    ~Rank();

    uint8_t id();
    QString name();
    Department* department();

    void setId(uint8_t);
    void setName(QString);
    void setDepartment(Department* dep);

private:

    uint8_t m_id;
    QString m_name;
    Department* m_department;
};

#endif // RANK_H
