#include "bullet.h"
#include "common.h"
#include <QPointF>

Bullet::Bullet(QObject *parent)
    : TPoint{parent},
    exist(false)
{}

Bullet::Bullet(qreal x, qreal y, qreal angle, QObject *parent)
    : TPoint{x, y, angle, parent},
    exist(false)
{

}

Bullet::~Bullet()
{

}

void Bullet::moveForward()
{
    QPointF delta = QPointF(qCos(qDegreesToRadians(angle)) * BULLET_MOVE_SPEED, qSin(qDegreesToRadians(angle)) * BULLET_MOVE_SPEED);
    QPointF newPos = this->position() + delta;
    this->setPos(newPos);
}
