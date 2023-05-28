#ifndef DATABASE_H
#define DATABASE_H

#include <QMessageBox>
#include "employee_role.h"
#include "role.h"
#include "roleauthority.h"
#include "authority.h"
#include "employee.h"
#include "event.h"
#include "vacation.h"
#include "task.h"
#include "rank.h"
#include <vector>

class DataBase
{
public:
    DataBase();

    int vacationsAmount();
    Vacation* vacation(int number);
    void addVacation(Vacation* vacation);
    void removeVacation(int number);
    void changeVacation(Vacation* vacation, int number);

    int employeesAmount();
    Employee* employee(int number);
    Employee* employee(QString name);
    std::vector<Employee*> employees();
    void addEmployee(Employee* employee);
    void removeEmployee(int number);
    void changeEmployee(Employee* employee, int number);

    int tasksAmount();
    Task* task(int number);
    Task* task(QString name);
    std::vector<Task*> tasks();
    void addTask(Task* task);
    void removeTask(int number);
    void changeTask(Task* task, int number);

    int ranksAmount();
    Rank* rank(int number);
    Rank* rank(QString name);
    void addRank(Rank* rank);
    void removeRank(int number);
    void changeRank(Rank* rank, int number);

    int documentsAmount();
    Document* document(int number);
    Document* document(QString name);
    void addDocument(Document* document);
    void removeDocument(int number);
    void changeDocument(Document* document, int number);

    int paymentsAmount();
    Payment* payment(int number);
    Payment* payment(QString name);
    void addPayment(Payment* payment);
    void removePayment(int number);
    void changePayment(Payment* payment, int number);

    int eventsAmount();
    Event* event(int number);
    Event* event(QString name);
    void addEvent(Event* event);
    void removeEvent(int number);
    void changeEvent(Event* event, int number);

    int employeeRoleAmount();
    EmployeeRole* employeeRole(int number);
    EmployeeRole* employeeRole(QString name);
    void addEmployeeRole(EmployeeRole* employeeRole);
    void removeEmployeeRole(int number);
    void changeEmployeeRole(EmployeeRole* employeeRole, int number);

    int rolesAmount();
    Role* role(int number);
    Role* role(QString name);
    void addRole(Role* role);
    void removeRole(int number);
    void changeRole(Role* role, int number);

    int roleAuthorityAmount();
    RoleAuthority* roleAuthority(int number);
    RoleAuthority* roleAuthority(QString name);
    void addRoleAuthority(RoleAuthority* roleAuthority);
    void removeRoleAuthority(int number);
    void changeRoleAuthority(RoleAuthority* roleAuthority, int number);

    int authoritiesAmount();
    Authority* authority(int number);
    Authority* authority(QString name);
    void addAuthority(Authority* authority);
    void removeAuthority(int number);
    void changeAuthority(Authority* authority, int number);

private:
    std::vector<Vacation*> m_vacations;
    std::vector<Employee*> m_employeers;
    std::vector<Task*> m_tasks;
    std::vector<Rank*> m_ranks;
    std::vector<Document*> m_documents;
    std::vector<Payment*> m_payments;
    std::vector<Event*> m_events;
    std::vector<EmployeeRole*> m_employee_role;
    std::vector<Role*> m_roles;
    std::vector<RoleAuthority*> m_role_authority;
    std::vector<Authority*> m_authorities;
};

#endif // DATABASE_H
