#include "payment.h"

Payment::Payment()
{
    setId(255);
    setName("Set Name");
    setAmount(0);
}

void Payment::setId(uint32_t id)
{
    m_id=id;
}

void Payment::setName(QString name)
{
    m_name=name;
}

void Payment::setAmount(uint32_t amount)
{
    m_amount=amount;
}

uint32_t Payment::id()
{
    return m_id;
}

QString Payment::name()
{
    return m_name;
}

uint32_t Payment::amount()
{
    return m_amount;
}

