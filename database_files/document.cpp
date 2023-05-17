#include "document.h"

Document::Document()
{
    setId(255);
    setName("Set Name");
    setCode("99999999");
}

void Document::setId(uint32_t id)
{
    m_id=id;
}

void Document::setName(QString name)
{
    m_name=name;
}

void Document::setCode(QString code)
{
    m_code=code;
}

uint32_t Document::id()
{
    return m_id;
}

QString Document::name()
{
    return m_name;
}

QString Document::code()
{
    return m_code;
}

