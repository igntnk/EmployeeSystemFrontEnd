#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QString>

class Document
{
public:
    Document();

    void setId(uint32_t);
    void setName(QString);
    void setCode(uint32_t);

    uint32_t id();
    QString name();
    uint32_t code();

private:

    int m_id;
    QString m_name;
    int m_code;
};

#endif // DOCUMENT_H
