
#include "employee_role.h"

EmployeeRole::EmployeeRole()
{
    m_employee = new Employee();
    m_role = new Role();
}

EmployeeRole::~EmployeeRole()
{

}

void EmployeeRole::setEmployee(Employee *employee)
{
    m_employee = employee;
}

void EmployeeRole::setRole(Role *role)
{
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

