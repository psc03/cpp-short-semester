#include "tankviewmodel.h"
#include "common.h"
#include <QObject>
#include <QKeyEvent>

TankViewModel::TankViewModel(QObject *parent)
    : QObject{parent},
    tank(new TPoint())
{}

TankViewModel::TankViewModel(qreal x, qreal y, qreal angle, int id, QObject *parent)
    : QObject{parent},
    tank(new TPoint(x, y, angle))
{
    tank->setId(id);
}

TankViewModel::~TankViewModel()
{

}

void TankViewModel::attach_tankmodel(TankModel *tankModel)
{
    this->tankModel = tankModel;
}

TPoint *TankViewModel::get_tank()
{
    return tank;
}

void TankViewModel::get_moveCommand(int sId)
{
    if(sId == TANK_MOVE_FORWARD){
        this->tankModel->moveForward();
    }
    else if(sId == TANK_MOVE_BACKWARD){
        this->tankModel->moveBackward();
    }
}

void TankViewModel::get_rotateCommand(int sId)
{
    if(sId == TANK_ROTATE_LEFT){
        this->tankModel->rotateLeft();
    }
    else if(sId == TANK_ROTATE_RIGHT){
        this->tankModel->rotateRight();
    }
}

void TankViewModel::get_Notification(qint32 eId)
{
    if(eId == TANK_MOVE_FORWARD){
        this->tank->setPos(this->tankModel->position());
        emit tank_move(this->tank->getId() == RED_TANK ?eId :eId * -1);
    }
    else if(eId == TANK_MOVE_BACKWARD){
        this->tank->setPos(this->tankModel->position());
        emit tank_move(this->tank->getId() == RED_TANK ?eId :eId * -1);
    }
    else if(eId == TANK_ROTATE_LEFT){
        this->tank->setAngle(this->tankModel->getAngle());
        emit tank_move(this->tank->getId() == RED_TANK ?eId :eId * -1);
    }
    else if(eId == TANK_ROTATE_RIGHT){
        this->tank->setAngle(this->tankModel->getAngle());
        emit tank_move(this->tank->getId() == RED_TANK ?eId :eId * -1);
    }
}
