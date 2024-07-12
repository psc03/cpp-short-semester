#ifndef MAPMODEL_H
#define MAPMODEL_H

#include <QObject>
#include <QVector>
#include "mem/tank.h"
#include "mem/bullet.h"
#include "common.h"

class MapModel : public QObject
{
    Q_OBJECT
public:
    explicit MapModel(QObject *parent = nullptr);
    ~MapModel();
    QPointF getTankPosition(Item color);
    qreal getTankAngle(Item color);
    QVector<Bullet *> getBullets(Item color);
    void tank_moveForward(Item category);
    void tank_moveBackward(Item category);
    void tank_rotateLeft(Item category);
    void tank_rotateRight(Item category);
    void tank_shoot(Item color);

signals:
    void tank_move(Item catogory, Notification nId);
    void bullet_change(Item catogory, Notification nId);

private slots:
    void bullet_move();

private:
    Tank *red_tank;
    Tank *green_tank;
    QVector<Bullet *> red_bullets;
    QVector<Bullet *> green_bullets;
    QTimer *bullet_move_timer;
    bool tankCanMove(Tank tankNext);
    static int max_bullets;
};

#endif // MAPMODEL_H
