#include "mapmodel.h"
#include "common.h"
#include <QPolygonF>
#include <QRectF>
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
    // walls
    walls.push_back(new Wall(100, 0, 4, 100));
    walls.push_back(new Wall(246, 53, 4, 150));
    walls.push_back(new Wall(0, 200, 250, 4));
    walls.push_back(new Wall(241, 380, 250, 4));
    walls.push_back(new Wall(140, 280, 4, 100));
    walls.push_back(new Wall(140, 280, 150, 4));
    walls.push_back(new Wall(40, 330, 100, 4));
    walls.push_back(new Wall(424, 441, 4, 50));
    walls.push_back(new Wall(350, 380, 4, 50));
    walls.push_back(new Wall(340, 150, 150, 4));
    walls.push_back(new Wall(250, 80, 150, 4));
    walls.push_back(new Wall(390, 220, 4, 50));
    walls.push_back(new Wall(340, 220, 50, 4));
    walls.push_back(new Wall(50, 440, 4, 50));
    walls.push_back(new Wall(0, 440, 50, 4));
    walls.push_back(new Wall(100, 100, 50, 4));
    walls.push_back(new Wall(260, 355, 4, 25));
    walls.push_back(new Wall(150, 175, 4, 25));

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

QVector<Wall *> MapModel::getWalls()
{
    return walls;
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
    qreal deltaX = 0;
    qreal deltaY = 0;
    for(int i = 0; i < red_bullets.size(); i++){
        if(!red_bullets[i]->isAvailable()){
            // TODO: MoveForward之前检测
            if(bulletCollide(red_bullets[i], deltaX, deltaY)){
                if(deltaX == 0){ // 撞横着的墙
                    QPointF nextPosition = red_bullets[i]->getNextPosition();
                    red_bullets[i]->setPos(nextPosition.x() + deltaX, nextPosition.y() + deltaY);
                    red_bullets[i]->setAngle(-1 * red_bullets[i]->getAngle());
                }
                else { // 撞竖着的墙
                    QPointF nextPosition = red_bullets[i]->getNextPosition();
                    red_bullets[i]->setPos(nextPosition.x() + deltaX, nextPosition.y() + deltaY);
                    red_bullets[i]->setAngle(180 - red_bullets[i]->getAngle());
                }

            }
            else red_bullets[i]->moveForward();
            // QPointF point = red_bullets[i]->position();
            // qreal angle = red_bullets[i]->getAngle();
            // count++;
        }
    }
    for(int i = 0; i < green_bullets.size(); i++){
        if(!green_bullets[i]->isAvailable()){
            if(bulletCollide(green_bullets[i], deltaX, deltaY)){
                if(deltaX == 0){ // 撞横着的墙
                    QPointF nextPosition = green_bullets[i]->getNextPosition();
                    green_bullets[i]->setPos(nextPosition.x() + deltaX, nextPosition.y() + deltaY);
                    green_bullets[i]->setAngle(-1 * green_bullets[i]->getAngle());
                }
                else { // 撞竖着的墙
                    QPointF nextPosition = green_bullets[i]->getNextPosition();
                    green_bullets[i]->setPos(nextPosition.x() + deltaX, nextPosition.y() + deltaY);
                    green_bullets[i]->setAngle(180 - green_bullets[i]->getAngle());
                }
            }
            else green_bullets[i]->moveForward();
            // count++;
        }
    }
    // qDebug() << "count " << count;
    emit bullet_change(BULLET, BULLET_CHANGE);
}

bool MapModel::tankCanMove(Tank tankNext)
{
    // 如果细化它的边界，碰撞可能更加丝滑
    QVector<QPointF> tankVertices = tankNext.getVertices();
    // 边界
    for (auto vertex : tankVertices) {
        if (vertex.x() < 0 || vertex.x() > SCENE_WIDTH || vertex.y() < 0 || vertex.y() > SCENE_HEIGHT) {
            return false;
        }
    }
    // 墙壁
    QPolygonF tankPolygon(tankVertices);
    for (auto wall : walls) {
        QRectF wallPolygon(wall->getX(),wall->getY(),wall->getWidth(),wall->getHeight());
        if (tankPolygon.intersects(wallPolygon)) {
            // qDebug() << "tank " << tankVertices[0].x() << tankVertices[0].y();
            return false;
        }
    }
    return true;
}

bool MapModel::bulletCollide(Bullet *bullet, qreal &deltaX, qreal &deltaY)
{
    Bullet bulletNext = *bullet;
    bulletNext.moveForward();
    QVector<QPointF> bulletVertices = bulletNext.getVertices();
    QRectF bulletRect(bulletNext.position().x(), bulletNext.position().y(), BULLET_WIDTH, BULLET_HEIGHT);
    deltaX = 0;
    deltaY = 0;
    // 边界
    for (auto vertex : bulletVertices) {
        if(vertex.x() < 0){
            deltaX = 2 * 0 - 2 * bulletRect.left();
            return true;
        }
        else if(vertex.x() > SCENE_WIDTH){
            deltaX = 2 * SCENE_WIDTH - 2 * bulletRect.right();
            return true;
        }
        else if(vertex.y() < 0){
            deltaY = 2 * 0 - 2 * bulletRect.top();
            return true;
        }
        else if(vertex.y() > SCENE_HEIGHT){
            deltaY = 2 * SCENE_HEIGHT - 2 * bulletRect.bottom();
            return true;
        }
    }
    // 墙壁
    for (auto wall : walls) {
        QRectF wallRect(wall->getX(), wall->getY(), wall->getWidth(), wall->getHeight());
        // if(!bulletRect.intersects(wallRect)) continue;
        QRectF intersection = bulletRect.intersected(wallRect);
        if(intersection.isEmpty()) continue;
        if(intersection.left() != bulletRect.left()){
            deltaX = 2 * wallRect.left() - 2 * bulletRect.right();
            return true;
        }
        else if(intersection.right() != bulletRect.right()){
            deltaX = 2 * wallRect.right() - 2 * bulletRect.left();
            return true;
        }
        else if(intersection.bottom() != bulletRect.bottom()){
            deltaY = 2 * wallRect.bottom() - 2 * bulletRect.top();
            return true;
        }
        else if(intersection.top() != bulletRect.top()){
            deltaY = 2 * wallRect.top() - 2 * bulletRect.bottom();
            return true;
        }
    }
    return false;
}

