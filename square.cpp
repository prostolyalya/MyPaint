#include "square.h"
#include <QPainter>


Square::Square(QPen pen, QPointF point, QObject *parent) :
    Figure(pen,point,parent)
{
    Q_UNUSED(point)
    Figure::penn= pen;
}

Square::~Square()
{

}

// Реализуем метод отрисовки
void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(penn);

    QRectF rect(endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),
                endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y(),
                qAbs(endPoint().x() - startPoint().x()),
                qAbs(endPoint().y() - startPoint().y()));
    painter->drawRect(rect);
    Q_UNUSED(option)
    Q_UNUSED(widget)

}
