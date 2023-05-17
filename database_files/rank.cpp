#include "rank.h"

Rank::Rank()
{
    setId(255);
    setName("Set Name");
    m_department = new Department();
}

Rank::~Rank()
{

}

uint8_t Rank::id(){return m_id;}
QString Rank::name(){return m_name;}
Department* Rank::department(){return m_department;}

void Rank::setId(uint8_t id){m_id = id;}
void Rank::setName(QString name){m_name = name;}

void Rank::setDepartment(Department* dep)
{
    if(m_department != nullptr){delete m_department;}
    m_department = dep;
}
