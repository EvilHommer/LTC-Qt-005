#ifndef BANK_H
#define BANK_H

#include <QObject>

class Bank : public QObject
{
    Q_OBJECT
public:
    explicit Bank(QObject *parent = nullptr);

    long totalBalance() const;
signals:
    void totalBalanceChanged(long newTotalBalance);
public slots:
    // TODO: declare slot to listen account changes
    void onAccBalanceChanged(long newAccBalance);
};

#endif // BANK_H
