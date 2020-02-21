#include "Counter.hpp"

Counter::Counter() : QObject(),
                     m_value(0)
{}                

void Counter::slotInc()
{
    emit counterChanged(++m_value);

    if(5 == m_value)
    {
        emit goodbye();
    }
}