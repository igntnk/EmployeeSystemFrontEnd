#ifndef RANK_H
#define RANK_H

#include <iostream>
#include <QString>

class Rank
{
public:
    Rank();
    ~Rank();

    uint8_t id();
    QString name();

    void setId(uint8_t);
    void setName(QString);

private:

    uint8_t m_id;
    QString m_name;
};

#endif // RANK_H
