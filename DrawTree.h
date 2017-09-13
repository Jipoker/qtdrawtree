#ifndef DRAWTREE_H
#define DRAWTREE_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QColor>

class DrawTree : public QWidget
{
    Q_OBJECT
public:
    explicit DrawTree(QWidget *parent = 0);
    DrawTree(int rect_wid_size, int rect_height_size ,QWidget *parent = 0);
    void drawXTree(QPainter *painter);

    void drawXTree1(QPainter *painter);


protected:
    void paintEvent(QPaintEvent *event);

signals:

public slots:
private:
    int rect_wid_size = 0;  // 树的深度
    int rect_height_size = 0;  // 树的广度
};

#endif // DRAWTREE_H
