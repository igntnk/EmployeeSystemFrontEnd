
#include "employee_role.h"

EmployeeRole::EmployeeRole()
{
    m_employee = new Employee();
    m_role = new Role();
}

void EmployeeRole::setEmployee(Employee *employee)
{
    delete m_employee;
    m_employee = employee;
}

void EmployeeRole::setRole(Role *role)
{
    delete m_role;
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

