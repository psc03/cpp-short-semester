#include "tpoint.h"
#include <QPointF>

TPoint::TPoint(QObject *parent)
    : QObject{parent},
    x(0),
    y(0),
    angle(0)
{}

TPoint::TPoint(qreal x, qreal y, qreal angle, QObject *parent)
    : QObject{parent},
    x(x),
    y(y),
    angle(angle)
{

}

TPoint::~TPoint()
{

}

QPointF TPoint::position() const
{
    return QPointF(x, y);
}

qreal TPoint::getX() const
{
    return x;
}

void TPoint::setX(qreal x)
{
    this->x = x;;
}

qreal TPoint::getY() const
{
    return y;
}

void TPoint::setY(qreal y)
{
    this->y = y;
}

void TPoint::setPos(const QPointF &pos)
{
    x = pos.x();
    y = pos.y();
}

void TPoint::setPos(const qreal x, const qreal y)
{
    this->x = x;
    this->y = y;
}

void TPoint::moveBy(const qreal dx, const qreal dy)
{
    this->x += dx;
    this->y += dy;
}

qreal TPoint::getAngle() const
{
    return angle;
}

void TPoint::setAngle(qreal angle)
{
    this->angle = angle;
}

void TPoint::rotate(qreal dangle)
{
    this->angle += dangle;
}

