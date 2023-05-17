#ifndef EMPLOYEE_ROLE_H
#define EMPLOYEE_ROLE_H

#include "employee.h"
#include "role.h"

class EmployeeRole
{
public:
    EmployeeRole();
    ~EmployeeRole();

    void setEmployee(Employee* employee);
    void setRole(Role* role);

    Employee *employee();
    Role *role();

private:
    Employee* m_employee;
    Role* m_role;
};

#endif // EMPLOYEE_ROLE_H
