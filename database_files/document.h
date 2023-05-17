#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QString>

class Document
{
public:
    Document();

    void setId(uint32_t);
    void setName(QString);
    void setCode(QString);

    uint32_t id();
    QString name();
    QString code();

private:

    uint32_t m_id;
    QString m_name;
    QString m_code;
};

#endif // DOCUMENT_H
