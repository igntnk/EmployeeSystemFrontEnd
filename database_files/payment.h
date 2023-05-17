#ifndef PAYMENT_H
#define PAYMENT_H

#include <QString>

class Payment
{
public:
    Payment();

    void setId(uint32_t);
    void setName(QString);
    void setAmount(uint32_t);

    uint32_t id();
    QString name();
    uint32_t amount();

private:

    uint32_t m_id;
    QString m_name;
    uint32_t m_amount;
};

#endif // PAYMENT_H
