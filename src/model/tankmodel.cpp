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
    // if(canMove(newPos, tankItem)){
        this->setPos(newPos);
        emit tank_move(TANK_MOVE_FORWARD);
    // }
}

void TankModel::moveBackward()
{
    QPointF delta = QPointF(qCos(qDegreesToRadians(angle)) * TANK_MOVE_SPEED, qSin(qDegreesToRadians(angle)) * TANK_MOVE_SPEED);
    QPointF newPos = this->position() - delta;
    // if(canMove(newPos, tankItem)){
        this->setPos(newPos);
        emit tank_move(TANK_MOVE_BACKWARD);
    // }
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

// bool TankModel::canMove(const QPointF &newPos, TankItem *tankItem)
// {
//     QRectF sceneRect = tankItem->scene()->sceneRect();
//     QRectF tankRect = tankItem->boundingRect().translated(newPos);
//     // 在场景中移动，因为场景的设置是在地图边框内，所以需要加这一条限制；之后Bullet应该也要特判
//     if (!sceneRect.contains(tankRect)) {
//         return false;
//     }
//     // WARNING: 可能需要修改，现在还不清楚之后墙体怎么设置。暂且当作QGraphicsItem
//     QList<QGraphicsItem *> collidingItems = tankItem->scene()->collidingItems(tankItem);
//     for (auto item:collidingItems) {
//         if (item != tankItem) {
//             return false;
//         }
//     }

//     return true;
// }
