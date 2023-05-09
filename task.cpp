
#include "task.h"

Task::Task(uint8_t task_id,QString task_name, QString task_description,
           uint8_t task_response,QDate time_to_make,QDate getting_date):
    m_task_id(task_id),m_task_name(task_name),m_task_decription(task_description),m_task_response(task_response),
    m_time_to_make(time_to_make),m_getting_date(getting_date)
{

}

uint8_t Task::taskId(){return m_task_id;}
QString Task::taskName(){return m_task_name;}
QString Task::taskDescription(){return m_task_decription;}
uint8_t Task::taskResponse(){return m_task_response;}
QDate Task::timeToMake(){return m_time_to_make;}
QDate Task::gettingGate(){return m_getting_date;}

void Task::setTaskId(uint8_t task_id){m_task_id = task_id;}
void Task::setTaskName(QString task_name){m_task_name = task_name;}
void Task::setTaskDescription(QString refer){m_task_decription = refer;}
void Task::setTaskResponse(uint8_t task_response){m_task_response = task_response;}
void Task::setTimeToMake(QDate time_to_make){m_time_to_make = time_to_make;}
void Task::setGettingGate(QDate getting_date){m_getting_date = getting_date;}
