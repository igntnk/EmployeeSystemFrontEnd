
#include "employee.h"

Employee::Employee()
{

}

Employee::~Employee()
{

}

void Employee::setId(int id){m_id=id;}
void Employee::setName(QString name){m_name=name;}
void Employee::setSurname(QString surname){m_surname=surname;}
void Employee::setUsername(QString username){m_username=username;}
void Employee::setPassword(QString password){m_password=password;}
void Employee::setHireDate(QDate date){m_hire_date=date;}
void Employee::setFireDate(QDate* date){m_fire_date = date;}
void Employee::addTask(Task* task){m_task.push_back(task);}
void Employee::removeTask(int number){if(m_task[number] != nullptr){delete m_task[number];}; m_task.erase(m_task.begin()+number);}
void Employee::setRank(Rank* rank){m_rank=rank;}
void Employee::addDocument(Document* document){m_document.push_back(document);}
void Employee::removeDocument(int number){if(m_document[number] != nullptr){delete m_document[number];} m_document.erase(m_document.begin()+number);}
void Employee::addPayment(Payment* payment){m_payment.push_back(payment);}
void Employee::removePayment(int number){if(m_payment[number] != nullptr){delete m_payment[number];} m_payment.erase(m_payment.begin()+number);}

int Employee::id(){return m_id;}
QString Employee::name(){return m_name;}
QString Employee::surname(){return m_surname;}
QString Employee::username(){return m_username;}
QString Employee::password(){return m_password;}
QDate Employee::hireDate(){return m_hire_date;}
QDate* Employee::fireDate(){return m_fire_date;}
Task* Employee::task(int number){return m_task[number];}
int Employee::tasksAmount(){return m_task.size();}
Rank* Employee::rank(){return m_rank;}
Document* Employee::document(int number){return m_document[number];}
Payment* Employee::payment(int number){return m_payment[number];}
