#include "Widget.h"
#include <QApplication>
#include "DrawTree.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();

    DrawTree * t = new DrawTree(10,10);
    t->setMinimumWidth(1200);
    t->show();

    return a.exec();
}
