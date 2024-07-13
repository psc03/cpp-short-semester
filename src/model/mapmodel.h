#ifndef MAPMODEL_H
#define MAPMODEL_H

#include <QObject>
#include <QVector>
#include "mem/tank.h"
#include "mem/bullet.h"
#include "common.h"
#include "mem/wall.h"
class MapModel : public QObject
{
    Q_OBJECT
public:
    explicit MapModel(QObject *parent = nullptr);
    ~MapModel();
    QPointF getTankPosition(Item color);
    qreal getTankAngle(Item color);
    QVector<Bullet *> getBullets(Item color);
    QVector<Wall *> getWalls();
    int getRedScore();
    int getGreenScore();
    void tank_moveForward(Item category);
    void tank_moveBackward(Item category);
    void tank_rotateLeft(Item category);
    void tank_rotateRight(Item category);
    void tank_shoot(Item color);
    void reset();
    void tankHited(Item color);

signals:
    void tank_move(Item catogory, Notification nId);
    void bullet_change(Item catogory, Notification nId);
    void tank_hit(Item catogory);
    void score_change(Item catogory, Notification nId);
private slots:
    void bullet_move();

private:
    Tank *red_tank;
    Tank *green_tank;
    QVector<Bullet *> red_bullets;
    QVector<Bullet *> green_bullets;
    QVector<Wall *> walls;
    QTimer *bullet_move_timer;
    int redScore;
    int greenScore;

    bool tankCanMove(Tank tankNext);
    bool bulletCollide(Bullet *bullet, qreal &deltaX, qreal &deltaY);
    QPointF randomPosition();
    static int max_bullets;
};

#endif // MAPMODEL_H
