#include "bankaccount.h"

BankAccount::BankAccount(QObject *parent) : QObject(parent)
{
    m_balance = 5000;
}

void BankAccount::deposit(long amount)
{
    m_balance += amount;
}

void BankAccount::withdraw(long amount)
{
    m_balance -= amount;
}

void BankAccount::setHolderName(const QString &holderName)
{
    m_holderName = holderName;
}

QString BankAccount::holderName() const
{
    return m_holderName;
}

qint64 BankAccount::balance() const
{
    return m_balance;
}
