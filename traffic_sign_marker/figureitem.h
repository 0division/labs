#ifndef FIGUREITEM_H
#define FIGUREITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>

class FigureItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit FigureItem(QObject *parent = 0);
    void SetPen(QPen pen);
    void SetShape(int s);
    QList<double> GetPolygon() const;
    QPointF GetPos() const{ return this->pos();}
    void SetPos(double x, double y);
    void SetPolygon(const QList<double> pointList);
    ~FigureItem();

private:
    QRectF boundingRect() const;
    QPen majorPen;
    QPen outlinePen;
    QPointF mouseShiftCoords{0.0,0.0};
    QPointF coordChanged{0.0,0.0};
    int shape;
    QPolygonF polygon;
    QPointF pointA{10,110};
    QPointF pointB{10,10};
    QPointF pointC{110,10};
    QPointF pointD{110,110};
    bool isShaping{false};
    bool isMoving{false};
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // FIGUREITEM_H
