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
    category(RED_TANK),
    x(x),
    y(y),
    angle(angle)
{

}

TPoint::TPoint(qreal x, qreal y, Item category, qreal angle, QObject *parent)
    : QObject{parent},
    category(category),
    x(x),
    y(y),
    angle(angle)
{

}

TPoint::TPoint(const TPoint &others)
    : QObject{nullptr},
    category(others.category),
    x(others.x),
    y(others.y),
    angle(others.angle)
{

}

TPoint::~TPoint()
{

}

int TPoint::getId()
{
    return id;
}

void TPoint::setId(int id)
{
    this->id = id;
}

Item TPoint::getCategory()
{
    return category;
}

void TPoint::setCategory(Item category)
{
    this->category = category;
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

bool TPoint::isAvailable()
{
    return true;
}

void TPoint::setAngle(qreal angle)
{
    this->angle = angle;
}

void TPoint::rotate(qreal dangle)
{
    this->angle += dangle;
}

