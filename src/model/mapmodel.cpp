#include "mapmodel.h"
#include "common.h"
#include <QPointF>
#include <QDebug>
int MapModel::max_bullets = 5;

MapModel::MapModel(QObject *parent)
    : QObject{parent},
    red_tank(new Tank(RED_TANK, RED_TANK_INIT_X, RED_TANK_INIT_Y, RED_TANK_INIT_ANGLE)),
    green_tank(new Tank(GREEN_TANK, GREEN_TANK_INIT_X, GREEN_TANK_INIT_Y, GREEN_TANK_INIT_ANGLE))
{
    red_bullet.resize(max_bullets);
    for(int i = 0; i < max_bullets; i++){
        Bullet *bullet = new Bullet();
        red_bullet.push_back(bullet);
    }
    green_bullet.resize(max_bullets);
    for(int i = 0; i < max_bullets; i++){
        Bullet *bullet = new Bullet();
        green_bullet.push_back(bullet);
    }
}

MapModel::~MapModel()
{

}

QPointF MapModel::getTankPosition(Item color)
{
    if(color == RED_TANK) return red_tank->position();
    else return green_tank->position();
}

qreal MapModel::getTankAngle(Item color)
{
    if(color == RED_TANK) return red_tank->getAngle();
    else return green_tank->getAngle();
}

void MapModel::tank_moveForward(Item category)
{

    if(category == RED_TANK){
        Tank nextTank = *red_tank;
        nextTank.moveForward();
        if(tankCanMove(nextTank))
        {
            red_tank->moveForward();
            emit tank_move(category, TANK_MOVE_FORWARD);
        }
    }
    else if(category == GREEN_TANK){
        Tank nextTank = *green_tank;
        nextTank.moveForward();
        if(tankCanMove(nextTank))
        {
            green_tank->moveForward();
            emit tank_move(category, TANK_MOVE_FORWARD);
        }
    }
}

void MapModel::tank_moveBackward(Item category)
{
    if(category == RED_TANK){
        Tank nextTank = *red_tank;
        nextTank.moveBackward();
        if(tankCanMove(nextTank))
        {
            red_tank->moveBackward();
            emit tank_move(category, TANK_MOVE_BACKWARD);
        }
    }
    else if(category == GREEN_TANK){
        Tank nextTank = *green_tank;
        nextTank.moveBackward();
        if(tankCanMove(nextTank))
        {
            green_tank->moveBackward();
            emit tank_move(category, TANK_MOVE_BACKWARD);
        }
    }
}

void MapModel::tank_rotateLeft(Item category)
{
    if(category == RED_TANK){
        Tank nextTank = *red_tank;
        nextTank.rotateLeft();
        if(tankCanMove(nextTank))
        {
            red_tank->rotateLeft();
            emit tank_move(category, TANK_ROTATE_LEFT);
        }
    }
    else if(category == GREEN_TANK){
        Tank nextTank = *green_tank;
        nextTank.rotateLeft();
        if(tankCanMove(nextTank))
        {
            green_tank->rotateLeft();
            emit tank_move(category, TANK_ROTATE_LEFT);
        }
    }
}

void MapModel::tank_rotateRight(Item category)
{
    if(category == RED_TANK){
        Tank nextTank = *red_tank;
        nextTank.rotateRight();
        if(tankCanMove(nextTank))
        {
            red_tank->rotateRight();
            emit tank_move(category, TANK_ROTATE_RIGHT);
        }
    }
    else if(category == GREEN_TANK){
        Tank nextTank = *green_tank;
        nextTank.rotateRight();
        if(tankCanMove(nextTank))
        {
            green_tank->rotateRight();
            emit tank_move(category, TANK_ROTATE_RIGHT);
        }
    }
}

bool MapModel::tankCanMove(Tank tankNext)
{
    // 四周
    QVector<QPointF> Vertices = tankNext.getVertices();
    for(int i = 0; i < 4; i++)
    {
        if(Vertices[i].x() < 0 || Vertices[i].x() > SCENE_WIDTH || Vertices[i].y() < 0 || Vertices[i].y() > SCENE_WIDTH)
            return false;
    }
    // 墙壁
}
