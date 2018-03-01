#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "figure.h"

class PaintScene : public QGraphicsScene
{
    Q_OBJECT
    // Свойство текущего типа используемой фигуры
    Q_PROPERTY(int typeFigure
               READ typeFigure WRITE setTypeFigure
               NOTIFY typeFigureChanged)

public:
    explicit PaintScene(QObject *parent = 0);
    ~PaintScene();

    int typeFigure() const;                 // Возвращение текщего типа
    void setTypeFigure(const int type);     // Установка текущего типа

    // Перечисление типов используемых фигур
    enum FigureTypes {
        LineT,
        CurveT,
        SquareT,
        ElipseT
    };
    QPolygonF pol;
signals:
    void typeFigureChanged();               // Сигнал об изменении типа текущей фигуры

private:
    /* Объект для временного хранения рисуемой фигуры
     * */
    Figure *tempFigure;
    int m_typeFigure;   // текущий тип фигуры
    // Для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};


#endif // PAINTSCENE_H
