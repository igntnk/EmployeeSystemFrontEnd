#ifndef RANK_H
#define RANK_H

#include <iostream>
#include <QString>

class Rank
{
public:
    Rank();

    uint8_t rankId();
    QString rankName();

    void setRankId(uint8_t);
    void setRankName(QString);

private:

    uint8_t m_rank_id;
    QString m_rank_name;
};

#endif // RANK_H
