#include <iostream>
#include <QtWidgets>
#include "Counter.hpp"


int main(int argc, char ** argv)
{
    QApplication app(argc, argv);

#if 1   
    auto lb = new QLabel("0");
    lb->setWindowTitle("My Label");
    lb->resize (120, 33);
    lb->setFrameStyle(QFrame::WinPanel | QFrame::Plain);
    auto btn = new QPushButton("ADD");
    btn->setWindowTitle("My Button");
    btn->setEnabled(true);
    Counter counter;

    QBoxLayout* pbxLayout = new QVBoxLayout(/*QBoxLayout::LeftToRight*/);

    pbxLayout->addWidget(lb);
    //pbxLayout->addStretch(2);
    pbxLayout->addWidget(btn, 2);

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
    QScrollArea scroll;
    QWidget* pwgt = new QWidget();
    QPixmap pm(":/AdmiralVinogradov2009.jpg");

    QPalette pal;
    pal.setBrush(pwgt->backgroundRole(), QBrush(pm));
    pwgt->setPalette(pal);
    pwgt->setAutoFillBackground(true);
    std::cout << "Width = " << pm.width() << std::endl << "Height = " <<  pm.height() << std::endl;
    pwgt->setFixedSize(pm.width(), pm.height());
    scroll.setWidget(pwgt);
    scroll.resize(350, 150);
    scroll.show();
#endif

    return app.exec();
}