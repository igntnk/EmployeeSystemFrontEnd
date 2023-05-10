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
    Employee(uint8_t id = 255,QString name = "Unknown",QString surname = "Unknown",
             QString lastname = "Unknown", Task task = Task(),Rank rank = Rank(),
             QString username = "unknown12",QString password = "123",
             QDate hiring_date = QDate(QDate::currentDate()),
             bool vacation = false);

    void setId(uint8_t id );
    void setName(QString name);
    void setSurname(QString surname);
    void setLastName(QString lastName);
    void addTask(Task task);
    void setRank(Rank rank);
    void setUsername(QString username);
    void setPassword(QString password);
    void setHiringDate(QDate hiring_date);
    void setVacation(bool vacation);

    uint8_t id();
    QString name();
    QString surname();
    QString lastname();
    Task* task(uint8_t number);
    Rank rank();
    QString username();
    QString password();
    QDate hiringDate();
    bool vacation();

    int getTasksNumber();

private:
    uint8_t m_id;
    QString m_name;
    QString m_surname;
    QString m_lastname;
    std::vector<Task> m_task;
    Rank m_rank;
    QString m_username;
    QString m_password;
    QDate m_hiring_date;
    bool m_vacation;
};

#endif // EMPLOYEE_H
