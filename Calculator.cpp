#include "Calculator.hpp"
#include <iostream>

Calculator::Calculator(QWidget *ptr) : QWidget(ptr)
{
    m_plcd = new QLCDNumber(12);
    m_plcd->setMinimumSize(150, 50);
    auto pGridLayout = new QGridLayout();
    pGridLayout->addWidget(m_plcd, 0, 0, 1, 4);

    auto l_ce = new QPushButton("CE");
    l_ce->setMinimumSize(40, 40);
    pGridLayout->addWidget(l_ce, 1, 3);
    connect(l_ce, SIGNAL(clicked()), SLOT(slotButtonClicked()));

    QChar buttonArray[4][4] = {
        {'7', '8', '9', '/'},
        {'6', '5', '4', '*'},
        {'1', '2', '3', '-'},
        {'0', '.', '=', '+'}};

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            pGridLayout->addWidget(CreateButton(buttonArray[i][j]), i + 2, j);
        }
    }

    setLayout(pGridLayout);
}

QPushButton *Calculator::CreateButton(const QString &str)
{
    auto button = new QPushButton(str);
    button->setMinimumSize(40, 40);
    connect(button, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    return button;
}

void Calculator::calculate()
{
    double dOperand2 = m_stack.pop().toDouble();
    QString strOperation = m_stack.pop();
    double dOperandl = m_stack.pop().toDouble();
    double dResult = 0;
    if (strOperation == "+")
    {
        dResult = dOperandl + dOperand2;
    }
    if (strOperation == "-")
    {
        dResult = dOperandl - dOperand2;
    }
    if (strOperation == "/")
    {
        dResult = dOperandl / dOperand2;
    }
    if (strOperation == "*")
    {
        dResult = dOperandl * dOperand2;
    }
    m_plcd->display(dResult);
}

void Calculator::slotButtonClicked()
{
    QString str = ((QPushButton *)sender())->text();
    if (str == "CE")
    {
        m_stack.clear();
        m_str = "";
        m_plcd->display("0");
        return;
    }

    if (str.contains(QRegExp("[0-9]")))
    {
        m_str += str;
        m_plcd->display(m_str.toDouble());
    }
    else if (str == ".")
    {
        m_str += str;
        m_plcd->display(m_str);
    }
    else
    {
        if (m_stack.count() >= 2)
        {
            m_stack.push(QString().setNum(m_plcd->value()));
            calculate();
            m_stack.clear();
            m_stack.push(QString().setNum(m_plcd->value()));
            if (str != "=")
            {
                m_stack.push(str);
            }
        }
        else
        {
            m_stack.push(QString().setNum(m_plcd->value()));
            m_str = "";
            m_stack.push(str);
            m_plcd->display("0");
        }
    }
}
