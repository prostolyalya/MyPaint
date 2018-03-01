#ifndef CURVE_H
#define CURVE_H
#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Curve : public Figure
{
    Q_OBJECT

public:
    explicit Curve(QPen pen, QPolygonF *pol, QPointF point, QObject *parent = 0);
    ~Curve();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // CURVE_H
