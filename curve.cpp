#include "curve.h"
#include <QPainter>
#include <QDebug>
Curve::Curve(QPen pen, QPolygonF *pol, QPointF point, QObject *parent) :
    Figure(pen,point,parent)
{
    Q_UNUSED(point)
    Figure::penn = pen;
    Figure::polyg = *pol;
}

Curve::~Curve()
{

}

void Curve::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(penn);
    painter->drawPolyline(polyg);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
