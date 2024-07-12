#include "bullet.h"
#include "common.h"
#include <QPointF>

Bullet::Bullet(QObject *parent)
    : TPoint{parent},
    exist(false),
    life_timer(new QTimer(this))
{
    connect(life_timer, &QTimer::timeout, this, &Bullet::destroy);
}

Bullet::Bullet(qreal x, qreal y, qreal angle, QObject *parent)
    : TPoint{x, y, angle, parent},
    exist(false),
    life_timer(new QTimer(this))
{
    connect(life_timer, &QTimer::timeout, this, &Bullet::destroy);
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

bool Bullet::isAvailable()
{
    return !exist;
}

void Bullet::setExist()
{
    exist = true;
    if(exist){
        // move_timer = new QTimer(this);
        // move_timer->start(BULLET_MOVE_TIMER);
        // connect(move_timer, &QTimer::timeout, this, &Bullet::moveForward);

        life_timer->start(BULLET_LIFETIME);
    }
}

void Bullet::destroy()
{
    life_timer->stop();
    exist = false;
}
