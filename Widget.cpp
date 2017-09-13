#include "Widget.h"
#include "DrawTree.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    DrawTree * t = new DrawTree();
    t->show();
//    t->setFixedSize(800,600);
}

Widget::~Widget()
{

}
