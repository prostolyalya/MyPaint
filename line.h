#ifndef LINE_H
#define LINE_H
#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Line : public Figure
{
    Q_OBJECT

public:
    explicit Line(QPen pen,QPointF point, QObject *parent = 0);
    ~Line();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // LINE_H
