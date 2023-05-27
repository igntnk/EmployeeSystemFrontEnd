#include "task.h"

Task::Task()
{

}

uint8_t Task::id(){return m_id;}
QString Task::name(){return m_name;}
QString Task::description(){return m_decription;}
QDate Task::deadline(){return m_deadline;}
QDate Task::startline(){return m_startline;}
int Task::responce_id(){return m_responce_id;}
uint8_t Task::complete_stage(){return m_complete_stage;}

void Task::setId(uint8_t id){m_id = id;}
void Task::setName(QString name){m_name = name;}
void Task::setDescription(QString refer){m_decription = refer;}
void Task::setDeadline(QDate deadline){m_deadline = deadline;}
void Task::setStartline(QDate startline){m_startline = startline;}
void Task::setResponceId(int responce){m_responce_id = responce;}
void Task::setCompleteStage(uint8_t complete_stage){m_complete_stage = complete_stage;}
