#pragma once 

#include <QtWidgets>

class Counter : public QObject
{

Q_OBJECT

private:
    int m_value;

public:
    Counter();
    operator bool() {
        return true;
    }

public slots:
    void slotInc();

signals:
    void goodbye();
    void counterChanged(int counter);

};