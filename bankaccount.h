#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <QObject>
#include <QString>

class BankAccount : public QObject
{
    Q_OBJECT
    // TODO: declare QString holderName property that's represents account holder name
    //       this property must have getter and setter
    Q_PROPERTY(QString m_holderName READ holderName WRITE setHolderName)


    // TODO: declare long balance property
    Q_PROPERTY(qint64 m_balance READ balance)
    //       this property should be read-only and associated with variable m_balance
public:
    explicit BankAccount(QObject *parent = nullptr);

    void deposit(long amount);
    void withdraw(long amount);

    // TODO: declare and implement holderName getter/setter
    void setHolderName(const QString &holderName);
    QString holderName()const;
    // TODO: decalre and implement balance getter
    qint64 balance()const;

private:
    // TODO: declare holderName
    long m_balance;
    QString m_holderName;
};

#endif // BANKACCOUNT_H
