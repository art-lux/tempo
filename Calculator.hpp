#pragma once

#include <QtWidgets>
#include <QStack>

class QLCDNumber;
class QPushButton;

class Calculator : public QWidget
{
Q_OBJECT
public:
    Calculator(QWidget* ptr = 0);
    QPushButton* CreateButton(const QString& str);
    void calculate();

public slots:
    void slotButtonClicked();

private:
    QLCDNumber*      m_plcd;
    QStack<QString>  m_stack;
    QString          m_str;

};