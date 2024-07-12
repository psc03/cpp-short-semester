#include "mapviewmodel.h"
#include <QPointF>

MapViewModel::MapViewModel(QObject *parent)
    : QObject{parent},
    red_tank(new TPoint(RED_TANK_INIT_X, RED_TANK_INIT_Y, RED_TANK, RED_TANK_INIT_ANGLE)),
    green_tank(new TPoint(GREEN_TANK_INIT_X, GREEN_TANK_INIT_Y, GREEN_TANK, GREEN_TANK_INIT_ANGLE))
{}

MapViewModel::~MapViewModel()
{

}

void MapViewModel::attach_mapModel(MapModel *mapModel)
{
    this->mapModel = mapModel;
}

TPoint *MapViewModel::get_tank(Item color)
{
    if(color == RED_TANK) return red_tank;
    else return green_tank;
}

void MapViewModel::get_moveCommand(Item category, Command cId)
{
    if(cId == TANK_MOVE_FORWARD){
        this->mapModel->tank_moveForward(category);
    }
    else if(cId == TANK_MOVE_BACKWARD){
        this->mapModel->tank_moveBackward(category);
    }
    else if(cId == TANK_ROTATE_LEFT){
        this->mapModel->tank_rotateLeft(category);
    }
    else if(cId == TANK_ROTATE_RIGHT){
        this->mapModel->tank_rotateRight(category);
    }
}

// void MapViewModel::get_rotateCommand(Item category, Command cId)
// {
//     if(cId == TANK_ROTATE_LEFT){
//         this->mapModel->tank_rotateLeft(category);
//     }
//     else if(cId == TANK_ROTATE_RIGHT){
//         this->mapModel->tank_rotateRight(category);
//     }
// }

void MapViewModel::get_Notification(Item category, Notification nId)
{
    if(nId == TANK_MOVE_FORWARD){
        if(category == RED_TANK) this->red_tank->setPos(this->mapModel->getTankPosition(category));
        else if(category == GREEN_TANK) this->green_tank->setPos(this->mapModel->getTankPosition(category));
        emit tank_move(category, nId);
    }
    else if(nId == TANK_MOVE_BACKWARD){
        if(category == RED_TANK) this->red_tank->setPos(this->mapModel->getTankPosition(category));
        else if(category == GREEN_TANK) this->green_tank->setPos(this->mapModel->getTankPosition(category));
        emit tank_move(category, nId);
    }
    else if(nId == TANK_ROTATE_LEFT){
        if(category == RED_TANK) this->red_tank->setAngle(this->mapModel->getTankAngle(category));
        else if(category == GREEN_TANK) this->green_tank->setAngle(this->mapModel->getTankAngle(category));
        emit tank_move(category, nId);
    }
    else if(nId == TANK_ROTATE_RIGHT){
        if(category == RED_TANK) this->red_tank->setAngle(this->mapModel->getTankAngle(category));
        else if(category == GREEN_TANK) this->green_tank->setAngle(this->mapModel->getTankAngle(category));
        emit tank_move(category, nId);
    }
}
