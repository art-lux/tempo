#include <iostream>
#include <QtWidgets>
#include "Counter.hpp"
#include "Calculator.hpp"


void start_calculator()
{
    Calculator* calc = new Calculator();
    calc->setWindowTitle("Calculator");
    calc->resize(230, 200);
    calc->show();
}

void scroll_area()
{
    auto scroll = new QScrollArea();
    QWidget* pwgt = new QWidget();
    auto pm = new QPixmap (":/AdmiralVinogradov2009.jpg");

    auto pal = new QPalette();
    pal->setBrush(pwgt->backgroundRole(), QBrush(*pm));
    pwgt->setPalette(*pal);
    pwgt->setAutoFillBackground(true);
    std::cout << "Width = " << pm->width() << std::endl << "Height = " <<  pm->height() << std::endl;
    pwgt->setFixedSize(pm->width(), pm->height());
    scroll->setWidget(pwgt);
    scroll->resize(350, 150);

    scroll->show();
}

void label_with_href()
{
    QLabel* plbl = new QLabel("<a href=\"http://www.bhv.ru/\"> www.bhv.ru</a>");
    //plbl->setTextInteractionFlags(Qt::TextBrowserInteraction);
    plbl->setOpenExternalLinks(true);
    plbl->show();
}

void label_with_pixmap()
{
    auto label = new QLabel();   
    auto pm_l = new QPixmap(":/amerigo-vespucci.jpg");
    label->resize(pm_l->size());
    label->setPixmap(*pm_l);
    label->show();
}