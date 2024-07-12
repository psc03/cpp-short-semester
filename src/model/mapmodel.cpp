#include "mapmodel.h"
#include "common.h"
#include <QPointF>

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
        red_tank->moveForward();
    }
    else if(category == GREEN_TANK){
        green_tank->moveForward();
    }
    emit tank_move(category, TANK_MOVE_FORWARD);
}

void MapModel::tank_moveBackward(Item category)
{
    if(category == RED_TANK){
        red_tank->moveBackward();
    }
    else if(category == GREEN_TANK){
        green_tank->moveBackward();
    }
    emit tank_move(category, TANK_MOVE_BACKWARD);
}

void MapModel::tank_rotateLeft(Item category)
{
    if(category == RED_TANK){
        red_tank->rotateLeft();
    }
    else if(category == GREEN_TANK){
        green_tank->rotateLeft();
    }
    emit tank_move(category, TANK_ROTATE_LEFT);
}

void MapModel::tank_rotateRight(Item category)
{
    if(category == RED_TANK){
        red_tank->rotateRight();
    }
    else if(category == GREEN_TANK){
        green_tank->rotateRight();
    }
    emit tank_move(category, TANK_ROTATE_RIGHT);
}
