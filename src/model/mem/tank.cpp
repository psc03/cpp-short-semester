#include "tank.h"
#include "common.h"
#include <QPointF>

Tank::Tank(QObject *parent)
    : TPoint{parent},
    color(RED_TANK)
{}

Tank::Tank(qreal x, qreal y, qreal angle, QObject *parent)
    : TPoint{x, y, RED_TANK, angle, parent},
    color(RED_TANK)
{

}

Tank::Tank(Item color, qreal x, qreal y, qreal angle, QObject *parent)
    : TPoint{x, y, color, angle, parent},
    color(color)
{

}

Tank::~Tank()
{

}

void Tank::moveForward()
{
    QPointF delta = QPointF(qCos(qDegreesToRadians(angle)) * TANK_MOVE_SPEED, qSin(qDegreesToRadians(angle)) * TANK_MOVE_SPEED);
    QPointF newPos = this->position() + delta;
    this->setPos(newPos);
}

void Tank::moveBackward()
{
    QPointF delta = QPointF(qCos(qDegreesToRadians(angle)) * TANK_MOVE_SPEED, qSin(qDegreesToRadians(angle)) * TANK_MOVE_SPEED);
    QPointF newPos = this->position() - delta;
    this->setPos(newPos);
}

void Tank::rotateLeft()
{
    qreal newAngle = this->getAngle() - TANK_ROTATE_SPEED;
    this->setAngle(newAngle);
}

void Tank::rotateRight()
{
    qreal newAngle = this->getAngle() + TANK_ROTATE_SPEED;
    this->setAngle(newAngle);
}
