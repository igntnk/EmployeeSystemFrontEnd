#ifndef TASK_H
#define TASK_H

#include <QDate>

class Task
{
public:
    Task(uint8_t task_id = 255,QString task_name = "Unknown", QString task_description = "Unknown",
         uint8_t task_response = 255,QDate time_to_make = QDate(QDate::currentDate()),
         QDate getting_date = QDate(QDate::currentDate()));

    uint8_t taskId();
    QString taskName();
    QString taskDescription();
    uint8_t taskResponse();
    QDate timeToMake();
    QDate gettingGate();

    void setTaskId(uint8_t);
    void setTaskName(QString);
    void setTaskDescription(QString);
    void setTaskResponse(uint8_t);
    void setTimeToMake(QDate);
    void setGettingGate(QDate);

private:
    uint8_t m_task_id;
    QString m_task_name;
    QString m_task_decription;
    uint8_t m_task_response;
    QDate m_time_to_make;
    QDate m_getting_date;
};

#endif // TASK_H
