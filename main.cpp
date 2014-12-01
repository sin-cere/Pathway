#include "pathway.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pathway w;


    //设置窗体无边框
    w.setWindowFlags(Qt::Window|
                     Qt::FramelessWindowHint|
                     Qt::WindowSystemMenuHint|
                     Qt::WindowMinimizeButtonHint|
                     Qt::WindowMaximizeButtonHint
                    );

    QObject::connect(&w,SIGNAL(closed()),&a,SLOT(quit()));

    w.show();

    return a.exec();
}
