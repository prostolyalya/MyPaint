#include "line.h"
#include <QPainter>

Line::Line(QPen pen, QPointF point, QObject *parent) :
    Figure(pen,point,parent)
{
    Q_UNUSED(point)
    Figure::penn = pen;
}

Line::~Line()
{

}

// Реализуем метод отрисовки
void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(penn);
    QLineF Line(startPoint().x(),
                startPoint().y(),
                endPoint().x(),
                endPoint().y());

    painter->drawLine(Line);
    Q_UNUSED(option)
    Q_UNUSED(widget)

}
