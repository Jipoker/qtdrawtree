#include "DrawTree.h"
#include "Comm.h"

const QSize rect_size(160,30);
const int Line_width(60);
const int Line_height(3);
const int padding_top(10);
const int padding_right(10);

const int height_interval(10);



DrawTree::DrawTree(QWidget *parent) : QWidget(parent)
{
    rect_wid_size = 3;
}

DrawTree::DrawTree(int rect_wid_size, int rect_height_size ,QWidget *parent)
{
    this->rect_wid_size = rect_wid_size ;
    this->rect_height_size = rect_height_size ;
}


void DrawTree::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    // 反走样
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(Qt::NoBrush);
    // 设置字体：微软雅黑、点大小50、斜体
    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPointSize(10);
//    font.setItalic(true);
    painter.setFont(font);

//    drawXTree(&painter);
    drawXTree1(&painter);
}


void DrawTree::drawXTree(QPainter *painter)
{
    // 设置画笔颜色、宽度
    painter->setPen(QPen(QColor(0, 160, 230), 2));

    HS_Debug<<"width():  "<<width();
    int wid = width() - padding_right;
    HS_Debug<<"width:  "<<wid;
    for(int i =0 ; i <rect_wid_size; ++i){
        int point_x = wid - rect_size.width()*(i+1) - Line_width*i;
        double point_line_y = padding_top + rect_size.height() /2;
        QRectF rect1 ( point_x, padding_top, rect_size.width(),rect_size.height()   );

        painter->drawRect( rect1   );
        painter->drawText( rect1 ,  Qt::AlignCenter, "test："+QString::number(i));
        // 绘制直线
        if( i<rect_wid_size-1 ){
            painter->drawLine(QPointF(point_x, point_line_y), QPointF(point_x-Line_width, point_line_y));
        }
    }


}

void DrawTree::drawXTree1(QPainter *painter)
{

    // 设置画笔颜色、宽度
    painter->setPen(QPen(QColor(0, 160, 230), 2));

    int widthRight = width() - padding_right;  //画图的最右边
    int heightTop =  padding_top; //画图的最上面

    int point_x = 0;
    int point_y = 0;
    double point_line_y = 0;
    QRectF rect1;
    for(int i =0 ; i <rect_wid_size; ++i){
        point_x = widthRight - rect_size.width()*(i+1) - Line_width*i;
        rect1 =  QRectF( point_x, point_y, rect_size.width(),rect_size.height()   );

        if( 0 == i ){
            for( int j =0; j<rect_height_size; ++j  ){
                point_y = heightTop+(height_interval+rect_size.height())*j;
                point_line_y = point_y + rect_size.height() /2;

                rect1 =  QRectF( point_x, point_y, rect_size.width(),rect_size.height()   );
                painter->drawRect( rect1   );
                painter->drawText( rect1 ,  Qt::AlignCenter, "test："+QString::number(i));
                painter->drawLine(QPointF(point_x, point_line_y), QPointF(point_x-Line_width/2, point_line_y));
                if( j < rect_height_size -1){
                    painter->drawLine(QPointF(point_x-Line_width/2, point_line_y),
                                      QPointF(point_x-Line_width/2, point_line_y+rect_size.height()+height_interval));
                }
            }
            point_line_y = (point_line_y - padding_top - rect_size.height()/2 ) /2 + padding_top+rect_size.height()/2;
            painter->drawLine(QPointF(point_x-Line_width/2, point_line_y), QPointF(point_x-Line_width, point_line_y));
        }else{
            rect1 =  QRectF( point_x, point_line_y - rect_size.height()/2, rect_size.width(),rect_size.height()   );
            painter->drawRect( rect1   );
            painter->drawText( rect1 ,  Qt::AlignCenter, "test："+QString::number(i));
            // 绘制直线
            if( i<rect_wid_size-1 ){
                painter->drawLine(QPointF(point_x, point_line_y), QPointF(point_x-Line_width, point_line_y));
            }
        }





    }

}














