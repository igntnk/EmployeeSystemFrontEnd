#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <QString>
#include <QDate>
#include <vector>
#include "task.h"
#include "rank.h"

class Employee
{
public:
    Employee();

    void setId(uint8_t id );
    void setName(QString name);
    void setSurname(QString surname);
    void addTask(Task* task);
    void setRank(uint8_t rank_id);
    void setUsername(QString username);
    void setPassword(QString password);
    void setHiringDate(QDate hiring_date);
    void setVacation(bool vacation);

    uint8_t id();
    QString name();
    QString surname();
    Task task();
    Rank rank();
    QString username();
    QString password();
    QDate hiringDate();
    bool vacation();

private:
    uint8_t m_id;
    QString m_name;
    QString m_surname;
    std::vector<Task*> m_task;
    Rank m_rank;
    QString m_username;
    QString m_password;
    QDate m_hiring_date;
    bool m_vacation;
};

#endif // EMPLOYEE_H
