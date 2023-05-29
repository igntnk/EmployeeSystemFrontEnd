#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <QString>
#include <QDate>
#include <vector>
#include "task.h"
#include "rank.h"
#include "document.h"
#include "payment.h"

class Employee
{
public:
    Employee();
    ~Employee();

    void setId(int id );
    void setName(QString name);
    void setSurname(QString surname);
    void setUsername(QString username);
    void setPassword(QString password);
    void setHireDate(QDate hire_date);
    void setFireDate(QDate* fire_date);
    void addTask(Task* task);
    void removeTask(int);
    void setRank(Rank* rank);
    void addDocument(Document*);
    void removeDocument(int);
    void addPayment(Payment*);
    void removePayment(int);

    int id();
    QString name();
    QString surname();
    QString username();
    QString password();
    QDate hireDate();
    QDate* fireDate();
    Task* task(int);
    Task *firstTask();
    std::vector<Task*> tasks();
    int tasksAmount();
    Rank* rank();
    Document* document(int);
    Payment* payment(int);

private:
    int m_id =255;
    QString m_name = "Set Name";
    QString m_surname = "Set Surname";
    QString m_username = "Set Username";
    QString m_password = "Set Password";
    QDate m_hire_date = QDate::currentDate();
    QDate* m_fire_date = nullptr;
    std::vector<Task*> m_task;
    Rank* m_rank = nullptr;
    std::vector<Document*> m_document;
    std::vector<Payment*> m_payment;
};

#endif // EMPLOYEE_H
