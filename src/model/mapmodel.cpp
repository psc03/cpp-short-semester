#include "mapmodel.h"
#include "common.h"
#include <QPointF>
#include <QDebug>
int MapModel::max_bullets = MAX_TANK_BULLETS;

MapModel::MapModel(QObject *parent)
    : QObject{parent},
    red_tank(new Tank(RED_TANK, RED_TANK_INIT_X, RED_TANK_INIT_Y, RED_TANK_INIT_ANGLE)),
    green_tank(new Tank(GREEN_TANK, GREEN_TANK_INIT_X, GREEN_TANK_INIT_Y, GREEN_TANK_INIT_ANGLE)),
    bullet_move_timer(new QTimer(this))
{
    // red_bullets.resize(max_bullets);
    for(int i = 0; i < max_bullets; i++){
        Bullet *bullet = new Bullet();
        red_bullets.push_back(bullet);
    }
    // green_bullets.resize(max_bullets);
    for(int i = 0; i < max_bullets; i++){
        Bullet *bullet = new Bullet();
        green_bullets.push_back(bullet);
    }

    bullet_move_timer->start(BULLET_MOVE_TIMER);
    connect(bullet_move_timer, &QTimer::timeout, this, &MapModel::bullet_move);
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

QVector<Bullet *> MapModel::getBullets(Item color)
{
    if(color == RED_TANK) return red_bullets;
    else return green_bullets;
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

void MapModel::tank_shoot(Item color)
{
    Bullet *shoot = nullptr;
    if(color == RED_TANK){
        // get available red bullet
        for(auto iter = red_bullets.begin(); iter != red_bullets.end(); iter++){
            if((*iter)->isAvailable()){
                shoot = (*iter);
                break;
            }
        }
        // shoot, change bullet
        if(shoot == nullptr) return ;
        shoot->setExist();
        QPointF tankLeftup = red_tank->position();
        QPointF tankCenter = tankLeftup + QPointF(TANK_WIDTH/2.0, TANK_HEIGHT/2.0);
        qreal angle = red_tank->getAngle();
        QPointF bulletCenter = tankCenter
                               + QPointF(qCos(qDegreesToRadians(angle)) * (TANK_WIDTH / 2.0 + BULLET_WIDTH / 2.0 + 1), qSin(qDegreesToRadians(angle)) * (TANK_WIDTH / 2.0 + BULLET_WIDTH / 2.0 + 1));
        QPointF bulletLeftup = bulletCenter - QPointF(BULLET_WIDTH/2.0, BULLET_HEIGHT/2.0);

        shoot->setPos(bulletLeftup);
        shoot->setAngle(angle);

        // emit signal
        emit bullet_change(BULLET, BULLET_CHANGE);
    }
    else if(color == GREEN_TANK){
        // get available green bullet
        for(auto iter = green_bullets.begin(); iter != green_bullets.end(); iter++){
            if((*iter)->isAvailable()){
                shoot = (*iter);
                break;
            }
        }
        // shoot, change bullet
        if(shoot == nullptr) return ;
        shoot->setExist();
        QPointF tankLeftup = green_tank->position();
        QPointF tankCenter = tankLeftup + QPointF(TANK_WIDTH/2.0, TANK_HEIGHT/2.0);
        qreal angle = green_tank->getAngle();
        QPointF bulletCenter = tankCenter
                               + QPointF(qCos(qDegreesToRadians(angle)) * (TANK_WIDTH / 2.0 + BULLET_WIDTH / 2.0 + 1), qSin(qDegreesToRadians(angle)) * (TANK_WIDTH / 2.0 + BULLET_WIDTH / 2.0 + 1));
        QPointF bulletLeftup = bulletCenter - QPointF(BULLET_WIDTH/2.0, BULLET_HEIGHT/2.0);

        shoot->setPos(bulletLeftup);
        shoot->setAngle(angle);

        // emit signal
        emit bullet_change(BULLET, BULLET_CHANGE);
    }
}

void MapModel::bullet_move()
{
    // int count = 0;
    for(int i = 0; i < red_bullets.size(); i++){
        if(!red_bullets[i]->isAvailable()){
            red_bullets[i]->moveForward();
            // count++;
        }
    }
    for(int i = 0; i < green_bullets.size(); i++){
        if(!green_bullets[i]->isAvailable()){
            green_bullets[i]->moveForward();
            // count++;
        }
    }
    // qDebug() << "count " << count;
    emit bullet_change(BULLET, BULLET_CHANGE);
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
