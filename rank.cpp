
#include "rank.h"

Rank::Rank()
{

}

uint8_t Rank::rankId(){return m_rank_id;}
QString Rank::rankName(){return m_rank_name;}

void Rank::setRankId(uint8_t rank_id){m_rank_id = rank_id;}
void Rank::setRankName(QString rank_name){m_rank_name = rank_name;}
