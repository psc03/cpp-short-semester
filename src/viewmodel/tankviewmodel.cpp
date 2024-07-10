#include "tankviewmodel.h"
#include "common.h"
#include <QObject>
#include <QKeyEvent>

TankViewModel::TankViewModel(QObject *parent)
    : QObject{parent},
    // tankItem(new TankItem()),
    tank(new TPoint())
{}

TankViewModel::TankViewModel(qreal x, qreal y, qreal angle, QObject *parent)
    : QObject{parent},
    // tankItem(new TankItem(angle)),
    tank(new TPoint(x, y, angle))

{
    // tankItem->setPos(x, y);
}

TankViewModel::~TankViewModel()
{

}

void TankViewModel::attach_tankmodel(TankModel *tankModel)
{
    this->tankModel = tankModel;
}

// void TankViewModel::attach_item(TankItem *tankItem)
// {
//     this->tankItem = tankItem;
// }

// TankItem *TankViewModel::get_tankItem()
// {
//     return this->tankItem;
// }

TPoint *TankViewModel::get_tank()
{
    return tank;
}

void TankViewModel::get_moveCommand(int sId)
{
    // if(key == Qt::Key_W){
    //     this->tankModel->moveForward();
    // }
    // else if(key == Qt::Key_S){
    //     this->tankModel->moveBackward();
    // }
    // else if(key == Qt::Key_A){
    //     this->tankModel->rotateLeft();
    // }
    // else if(key == Qt::Key_D){
    //     this->tankModel->rotateRight();
    // }
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
        // this->tankItem->setPos(this->tankModel->position());
        this->tank->setPos(this->tankModel->position());
        emit tank_move(eId);
    }
    else if(eId == TANK_MOVE_BACKWARD){
        // this->tankItem->setPos(this->tankModel->position());
        this->tank->setPos(this->tankModel->position());
        emit tank_move(eId);
    }
    else if(eId == TANK_ROTATE_LEFT){
        // this->tankItem->setRotation(this->tankModel->getAngle());
        this->tank->setAngle(this->tankModel->getAngle());
        emit tank_move(eId);
    }
    else if(eId == TANK_ROTATE_RIGHT){
        // this->tankItem->setRotation(this->tankModel->getAngle());
        this->tank->setAngle(this->tankModel->getAngle());
        emit tank_move(eId);
    }
}
