
#include "employee_role.h"

EmployeeRole::EmployeeRole()
{
    m_employee = new Employee();
    m_role = new Role();
}

EmployeeRole::~EmployeeRole()
{
    if(m_employee != nullptr)
    {
        delete m_employee;
    }

    if(m_role != nullptr)
    {
        delete m_role;
    }
}

void EmployeeRole::setEmployee(Employee *employee)
{
    if(m_employee!=nullptr){delete m_employee;}
    m_employee = employee;
}

void EmployeeRole::setRole(Role *role)
{
    if(m_role!=nullptr){delete m_role;}
    m_role = role;
}

Employee *EmployeeRole::employee()
{
    return m_employee;
}

Role *EmployeeRole::role()
{
    return m_role;
}

