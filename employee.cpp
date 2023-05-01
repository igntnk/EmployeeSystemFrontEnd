
#include "employee.h"

Employee::Employee(uint8_t id,QString name,
                   QString surname,Task task, Rank rank,QString username,
                   QString password,QDate hiring_date,bool vacation):
    m_id(id),m_name(name),m_surname(surname),m_rank(rank),
    m_username(username),m_password(password),m_hiring_date(hiring_date),
    m_vacation(vacation)
{
    m_task.push_back(task);
}

void Employee::setId(uint8_t id){m_id=id;}
void Employee::setName(QString name){m_name=name;}
void Employee::setSurname(QString surname){m_surname=surname;}
void Employee::addTask(Task task){m_task.push_back(task);}
void Employee::setRank(Rank rank){m_rank=rank;}
void Employee::setUsername(QString username){m_username=username;}
void Employee::setPassword(QString password){m_password=password;}
void Employee::setHiringDate(QDate date){m_hiring_date=date;}
void Employee::setVacation(bool vacation){ m_vacation=vacation;}

uint8_t Employee::id(){return m_id;}
QString Employee::name(){return m_name;}
QString Employee::surname(){return m_surname;}
Task Employee::task(uint8_t number){return m_task[number];}
Rank Employee::rank(){return m_rank;}
QString Employee::username(){return m_username;}
QString Employee::password(){return m_password;}
QDate Employee::hiringDate(){return m_hiring_date;}
bool Employee::vacation(){return m_vacation;}
