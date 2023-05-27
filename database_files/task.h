#ifndef TASK_H
#define TASK_H

#include <QDate>

class Task
{
public:
    Task();

    uint8_t id();
    QString name();
    QString description();
    uint8_t response();
    QDate deadline();
    QDate startline();
    int responce_id();
    uint8_t complete_stage();

    void setId(uint8_t);
    void setName(QString);
    void setDescription(QString);
    void setResponse(uint8_t);
    void setDeadline(QDate);
    void setStartline(QDate);
    void setResponceId(int responce);
    void setCompleteStage(uint8_t complete_stage);

private:
    uint8_t m_id =255;
    QString m_name = "setname";
    QString m_decription = "setDesc";
    QDate m_deadline = QDate::currentDate().addDays(100);
    QDate m_startline = QDate::currentDate();
    int m_responce_id = 255;
    uint8_t m_complete_stage = 0;
};

#endif // TASK_H
