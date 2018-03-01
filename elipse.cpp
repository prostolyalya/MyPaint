#include "elipse.h"
#include <QPainter>

Elipse::Elipse(QPen pen,QPointF point, QObject *parent) :
    Figure(pen,point,parent)
{
    Q_UNUSED(point)
    Figure::penn = pen;
}

Elipse::~Elipse()
{

}

// Реализуем метод отрисовки
void Elipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(penn);
    painter->drawEllipse(endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),
                         endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y(),
                         qAbs(endPoint().x() - startPoint().x()),
                         qAbs(endPoint().y() - startPoint().y()));
    Q_UNUSED(option)
    Q_UNUSED(widget)

}
