#include "tankviewmodel.h"
#include "common.h"
#include <QObject>
#include <QKeyEvent>

TankViewModel::TankViewModel(QObject *parent)
    : QObject{parent},
    tankItem(new TankItem())
{}

TankViewModel::TankViewModel(qreal x, qreal y, qreal angle, QObject *parent)
    : QObject{parent},
    tankItem(new TankItem(angle))
{
    tankItem->setPos(x, y);
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

TankItem *TankViewModel::get_tankItem()
{
    return this->tankItem;
}

void TankViewModel::get_MoveCommand(int key)
{
    if(key == Qt::Key_W){
        this->tankModel->moveForward(tankItem);
    }
    else if(key == Qt::Key_S){
        this->tankModel->moveBackward(tankItem);
    }
    else if(key == Qt::Key_A){
        this->tankModel->rotateLeft();
    }
    else if(key == Qt::Key_D){
        this->tankModel->rotateRight();
    }
}

void TankViewModel::get_Notification(qint32 eId)
{
    if(eId == TANK_MOVE_FORWARD){
        this->tankItem->setPos(this->tankModel->position());
        emit tank_move(eId);
    }
    else if(eId == TANK_MOVE_BACKWARD){
        this->tankItem->setPos(this->tankModel->position());
        emit tank_move(eId);
    }
    else if(eId == TANK_ROTATE_LEFT){
        this->tankItem->setRotation(this->tankModel->getAngle());
        emit tank_move(eId);
    }
    else if(eId == TANK_ROTATE_RIGHT){
        this->tankItem->setRotation(this->tankModel->getAngle());
        emit tank_move(eId);
    }
}
