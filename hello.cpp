#include <iostream>
#include <QtWidgets>
#include <thread>
#include <chrono>
#include "Counter.hpp"
#include "Calculator.hpp"

extern void start_calculator();
extern void label_with_href();
extern void scroll_area();
extern void label_with_pixmap();
extern void splitter();

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    start_calculator();

#if 0   
    auto lb = new QLabel("0");
    lb->setWindowTitle("My Label");
    lb->resize (120, 33);
    lb->setFrameStyle(QFrame::WinPanel | QFrame::Plain);
    auto btn = new QPushButton("ADD");
    btn->setWindowTitle("My Button");
    btn->setEnabled(true);
    Counter counter;

    QBoxLayout* pbxLayout = new QBoxLayout(QBoxLayout::LeftToRight);

    pbxLayout->addWidget(lb, 1);
    pbxLayout->addStretch(2);
    pbxLayout->addWidget(btn, 3);

    pbxLayout->setMargin(5);
    pbxLayout->setSpacing(2);
    QWidget pw;
    pw.setLayout(pbxLayout);
    pw.show();
    //lb.show();
    //btn.show();

    QObject::connect (btn, SIGNAL (clicked ()) , &counter, SLOT (slotInc ()) );
    QObject::connect (&counter, SIGNAL (counterChanged (int) ) , lb, SLOT (setNum( int) )) ;
    QObject::connect (&counter, SIGNAL (goodbye ( ) ) , &app, SLOT (quit ( ) ));
#endif

#if 0
   
    label_with_pixmap();
    scroll_area();
    label_with_href();
    splitter();
#endif

    return app.exec();
}