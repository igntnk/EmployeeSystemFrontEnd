#include "rank.h"

Rank::Rank()
{
    setId(255);
    setName("Set Name");
}

Rank::~Rank()
{

}

uint8_t Rank::id(){return m_id;}
QString Rank::name(){return m_name;}

void Rank::setId(uint8_t id){m_id = id;}
void Rank::setName(QString name){m_name = name;}
