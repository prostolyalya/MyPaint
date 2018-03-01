#include "paintscene.h"
#include "line.h"
#include "square.h"
#include "curve.h"
#include "elipse.h"
#include "z.h"

PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent)
{

}

PaintScene::~PaintScene()
{

}

int PaintScene::typeFigure() const
{
    return m_typeFigure;
}

void PaintScene::setTypeFigure(const int type)
{
    m_typeFigure = type;
}


void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Устанавливаем конечную координату положения мыши
     * в текущую отрисовываемую фигуру
     * */
    tempFigure->setEndPoint(event->scenePos());
    /* Обновляем содержимое сцены */
    this->update(QRectF(0,0,this->width(), this->height()));
    if (m_typeFigure == CurveT)
    {
    pol.push_back(event->scenePos());
    }

}

void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    extern bla ii;
    if (m_typeFigure == CurveT)
    {
    Curve *item = new Curve(QPen(ii.col,ii.val),&pol, event->scenePos());
    item->setPos(event->pos());
    tempFigure = item;
    this->addItem(tempFigure);
    }
    this->update(QRectF(0,0,this->width(), this->height()));
    ii.y.push_back(tempFigure);
}



void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    pol.clear();
    extern bla ii;
    switch (m_typeFigure) {
    case LineT: {
        Line *item = new Line(QPen(ii.col,ii.val), event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        this->addItem(tempFigure);
        break;
    }
    case CurveT:{
        extern bla ii;
        Curve *item = new Curve(QPen(ii.col,ii.val),&pol, event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        this->addItem(tempFigure);
        break;
    }
    case SquareT: {
        Square *item = new Square(QPen(ii.col,ii.val),event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        this->addItem(tempFigure);
        break;
    }
    case ElipseT: {
        Elipse *item = new Elipse(QPen(ii.col,ii.val),event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        this->addItem(tempFigure);
        break;
    }
    default:{
        Line *item = new Line(QPen(ii.col,ii.val),event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        this->addItem(tempFigure);
        break;
    }
    }

}
