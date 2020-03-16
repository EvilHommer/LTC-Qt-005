#include <QCoreApplication>
#include "bankaccount.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // don't change type of account, use it as QObject*
    QObject *account = new BankAccount;

    // TODO: set holder name
    account->setProperty("m_holderName", QString("John Doe"));
    // TODO: print it to qDebug()
    qDebug() << account->property("m_holderName").toString();

    // TODO: get balance from property to qDebug()
    qDebug() << account->property("m_balance").toString();
    account->setProperty("m_balance", 200);
    qDebug() << account->property("m_balance").toString();

    return a.exec();
}
