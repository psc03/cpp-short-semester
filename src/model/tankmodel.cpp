#include "tankmodel.h"
#include "common.h"
#include <qmath.h>
#include <QPointF>
#include <QGraphicsScene>

TankModel::TankModel(QObject *parent)
    : TPoint{parent}
{}

TankModel::TankModel(qreal x, qreal y, qreal angle, QObject *parent)
    : TPoint{x, y, angle, parent}
{

}

TankModel::~TankModel()
{

}

void TankModel::moveForward()
{
    QPointF delta = QPointF(qCos(qDegreesToRadians(angle)) * TANK_MOVE_SPEED, qSin(qDegreesToRadians(angle)) * TANK_MOVE_SPEED);
    QPointF newPos = this->position() + delta;
    this->setPos(newPos);
    emit tank_move(TANK_MOVE_FORWARD);
}

void TankModel::moveBackward()
{
    QPointF delta = QPointF(qCos(qDegreesToRadians(angle)) * TANK_MOVE_SPEED, qSin(qDegreesToRadians(angle)) * TANK_MOVE_SPEED);
    QPointF newPos = this->position() - delta;

    this->setPos(newPos);
    emit tank_move(TANK_MOVE_BACKWARD);

}

void TankModel::rotateLeft()
{
    qreal newAngle = this->getAngle() - TANK_ROTATE_SPEED;
    this->setAngle(newAngle);
    emit tank_move(TANK_ROTATE_LEFT);
}

void TankModel::rotateRight()
{
    qreal newAngle = this->getAngle() + TANK_ROTATE_SPEED;
    this->setAngle(newAngle);
    emit tank_move(TANK_ROTATE_RIGHT);
}
