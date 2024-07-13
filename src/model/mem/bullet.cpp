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
        life_timer->start(BULLET_LIFETIME);
    }
}

void Bullet::destroy()
{
    life_timer->stop();
    exist = false;
}

QVector<QPointF> Bullet::getVertices()
{
    QVector<QPointF> vertices;
    QPointF leftupPoint = position();
    QPointF leftdownPoint = leftupPoint + QPointF(0, BULLET_HEIGHT);
    QPointF rightupPoint = leftupPoint + QPointF(BULLET_WIDTH, 0);
    QPointF rightdownPoint = leftupPoint + QPointF(BULLET_WIDTH, BULLET_HEIGHT);
    vertices.push_back(leftupPoint);
    vertices.push_back(leftdownPoint);
    vertices.push_back(rightupPoint);
    vertices.push_back(rightdownPoint);
    return vertices;
}

QPointF Bullet::getNextPosition()
{
    QPointF delta = QPointF(qCos(qDegreesToRadians(angle)) * BULLET_MOVE_SPEED, qSin(qDegreesToRadians(angle)) * BULLET_MOVE_SPEED);
    QPointF newPos = this->position() + delta;
    return newPos;
}
