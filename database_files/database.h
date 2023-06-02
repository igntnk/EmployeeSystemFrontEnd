#ifndef DATABASE_H
#define DATABASE_H

#include <QMessageBox>
#include "role.h"
#include "employee.h"
#include "event.h"
#include "vacation.h"
#include "task.h"
#include "rank.h"
#include <vector>
#include "QFont"

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
    Employee *employeeByIndex(int index);
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

    int rolesAmount();
    Role* role(int number);
    Role* role(QString name);
    void addRole(Role* role);
    void removeRole(int number);
    void changeRole(Role* role, int number);

    void setLoggindeId(int);
    int loggindeId();

    QFont font();
    void setFontPixelSize(int size);

private:
    QFont SFProDisplay;

    int m_logginedId= -1;
    std::vector<Vacation*> m_vacations;
    std::vector<Employee*> m_employeers;
    std::vector<Task*> m_tasks;
    std::vector<Rank*> m_ranks;
    std::vector<Document*> m_documents;
    std::vector<Payment*> m_payments;
    std::vector<Event*> m_events;
    std::vector<Role*> m_roles;

};

#endif // DATABASE_H
