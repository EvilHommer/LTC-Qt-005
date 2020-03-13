#include "bankaccount.h"
#include <QDebug>

BankAccount::BankAccount(Bank *parentBank) : QObject(parentBank)
{
    m_balance = 0;
    // TODO: connect Bank slots to BankAccount signals
    connect(this, &BankAccount::balanceChanged, parentBank, &Bank::onAccBalanceChanged);
}

long BankAccount::balance() const
{
    return m_balance;
}

void BankAccount::setBalance(long newBalance)
{
    m_balance = newBalance;
    // TODO: add here signal emition
    emit balanceChanged(m_balance);
}

void BankAccount::deposit(long amount)
{
    // TODO: implement this function
    amount += balance();
    setBalance(amount);
}

void BankAccount::withdraw(long amount)
{
    // TODO: implement this function
    long currentBalance = balance();
    if(currentBalance < amount)
    {
        qDebug() << "Not enoth money on accout";
        return;
    }
    currentBalance -= amount;
    setBalance(currentBalance);
}
