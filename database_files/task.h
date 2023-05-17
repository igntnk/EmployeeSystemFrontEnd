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

    void setId(uint8_t);
    void setName(QString);
    void setDescription(QString);
    void setResponse(uint8_t);
    void setDeadline(QDate);
    void setStartline(QDate);

private:
    uint8_t m_id;
    QString m_name;
    QString m_decription;
    QDate m_deadline;
    QDate m_startline;
};

#endif // TASK_H
