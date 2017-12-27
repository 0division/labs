#include "figureitem.h"
#include <stdexcept>


FigureItem::FigureItem(QObject *parent) : QObject(parent)
{
    polygon << pointA << QPointF(pointB.x()+(pointC.x()-pointB.x())/2, pointB.y()) << pointD;
    outlinePen.setWidth(1);
    outlinePen.setStyle(Qt::DotLine);
}

FigureItem::~FigureItem()
{

}

void FigureItem::SetShape(int s)
{
    if(s>0 && s<4)
    {
        this->shape = s;
    }else{
        throw std::invalid_argument("Shape must be int number from 1 to 3");
    }
}

void FigureItem::SetPen(QPen pen)
{
    majorPen = pen;
}

void FigureItem::SetPolygon(const QList<double> pointList)
{
    pointA = QPointF(pointList.at(0),pointList.at(1));
    pointB = QPointF(pointList.at(2),pointList.at(3));
    pointC = QPointF(pointList.at(4),pointList.at(5));
    pointD = QPointF(pointList.at(6),pointList.at(7));
    polygon.clear();
    if(shape!=2)
    {
        polygon << pointA << pointB << pointC << pointD;
    }else{
        polygon << pointA << QPointF((pointB.x()+pointC.x())/2.0, pointB.y()) << pointD;
    }
    update(this->boundingRect());
}

void FigureItem::SetPos(double x, double y)
{
    this->setPos(QPointF(x,y));
}

QRectF FigureItem::boundingRect() const
{
    return polygon.boundingRect();
}

void FigureItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(majorPen);
    switch(shape){
    case 1: painter->drawPolygon(polygon.boundingRect());
        break;
    case 2: {
        painter->drawPolygon(polygon);
        painter->setPen(outlinePen);
        painter->drawPolygon(polygon.boundingRect());
    }
        break;
    case 3: {
        painter->drawEllipse(polygon.boundingRect());
        painter->setPen(outlinePen);
        painter->drawPolygon(polygon.boundingRect());
    }
        break;
    default: throw std::invalid_argument("Shape was not specified");
    }

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QList<double> FigureItem::GetPolygon() const
{
    QList<double> vec;
    vec << polygon.boundingRect().bottomLeft().x() << polygon.boundingRect().bottomLeft().y() << polygon.boundingRect().topLeft().x() << polygon.boundingRect().topLeft().y() << polygon.boundingRect().topRight().x() << polygon.boundingRect().topRight().y() << polygon.boundingRect().bottomRight().x() << polygon.boundingRect().bottomRight().y();
    return vec;
}

void FigureItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(isShaping)
    {
        pointA = QPointF(event->pos().x(),polygon.at(0).y());
        pointB = QPointF(event->pos().x(),event->pos().y());
        pointC = QPointF(polygon.at(2).x(),event->pos().y());
        polygon.clear();
        if(shape!=2)
        {
            polygon << pointA << pointB << pointC << pointD;
        }else{
            polygon << pointA << QPointF(pointB.x()+(pointC.x()-pointB.x())/2, pointB.y()) << pointD;
        }
        update(this->boundingRect());
    }else if(isMoving){
        this->setPos(mapToScene(event->pos())+mouseShiftCoords);

    }
}

void FigureItem::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    if(abs(event->pos().x()-this->boundingRect().topLeft().x()) < 10.0 && abs(event->pos().y()-this->boundingRect().topLeft().y() < 10.0))
    {
        this->setCursor(Qt::SizeFDiagCursor);
        isShaping = true;
    }else{
        this->setCursor(QCursor(Qt::ClosedHandCursor));
        isMoving = true;
        mouseShiftCoords = this->pos() - mapToScene(event->pos());
    }
    Q_UNUSED(event);
}

void FigureItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(isMoving){
        pointA = this->boundingRect().bottomLeft();
        pointB = this->boundingRect().topLeft();
        pointC = this->boundingRect().topRight();
        pointD = this->boundingRect().bottomRight();
        polygon.clear();
        if(shape!=2)
        {
            polygon << pointA << pointB << pointC << pointD;
        }else{
            polygon << pointA << QPointF(pointB.x()+(pointC.x()-pointB.x())/2, pointB.y()) << pointD;
        }
        update(this->boundingRect());
    }
    this->setCursor(QCursor(Qt::ArrowCursor));
    isMoving = false;
    isShaping = false;

    Q_UNUSED(event);
}
