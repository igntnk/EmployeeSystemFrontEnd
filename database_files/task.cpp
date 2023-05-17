#include "task.h"

Task::Task()
{
    setId(255);
    setName("Set Name");
    setDescription("Set Description");
    setDeadline(QDate::currentDate().addDays(100));
    setStartline(QDate::currentDate());
}

uint8_t Task::id(){return m_id;}
QString Task::name(){return m_name;}
QString Task::description(){return m_decription;}
QDate Task::deadline(){return m_deadline;}
QDate Task::startline(){return m_startline;}

void Task::setId(uint8_t id){m_id = id;}
void Task::setName(QString name){m_name = name;}
void Task::setDescription(QString refer){m_decription = refer;}
void Task::setDeadline(QDate deadline){m_deadline = deadline;}
void Task::setStartline(QDate startline){m_startline = startline;}
