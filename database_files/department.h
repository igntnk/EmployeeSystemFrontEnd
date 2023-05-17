#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <QString>

class Department
{
public:
    Department();

    void setId(uint32_t);
    void setName(QString);

    uint32_t id();
    QString name();

private:

    int m_id;
    QString m_name;
};

#endif // DEPARTMENT_H
