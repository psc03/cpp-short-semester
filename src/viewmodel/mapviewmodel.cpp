#include "mapviewmodel.h"

#include <QPointF>

MapViewModel::MapViewModel(QObject *parent)
    : QObject{parent},
      red_tank(new TPoint(RED_TANK_INIT_X, RED_TANK_INIT_Y, RED_TANK,
                          RED_TANK_INIT_ANGLE)),
      green_tank(new TPoint(GREEN_TANK_INIT_X, GREEN_TANK_INIT_Y, GREEN_TANK,
                            GREEN_TANK_INIT_ANGLE)),
      redScore(0),
      greenScore(0) {
  for (int i = 0; i < MAX_TANK_BULLETS * 2; i++) {
    TPoint *bullet = new Bullet();
    bullets.push_back(bullet);
  }
}

MapViewModel::~MapViewModel() {
  delete red_tank;
  delete green_tank;
  // for(int i = 0; i < bullets.size(); i++){
  //     delete bullets[i];
  // }
}

void MapViewModel::attach_mapModel(MapModel *mapModel) {
  this->mapModel = mapModel;
  walls = mapModel->getWalls();
}

TPoint *MapViewModel::get_tank(Item color) {
  if (color == RED_TANK)
    return red_tank;
  else
    return green_tank;
}

QVector<TPoint *> *MapViewModel::get_bullets() { return &bullets; }

QVector<Wall *> *MapViewModel::get_walls() { return &walls; }

int *MapViewModel::get_redScore() { return &redScore; }

int *MapViewModel::get_greenScore() { return &greenScore; }

void MapViewModel::get_moveCommand(Item category, Command cId) {
  if (cId == TANK_MOVE_FORWARD) {
    this->mapModel->tank_moveForward(category);
  } else if (cId == TANK_MOVE_BACKWARD) {
    this->mapModel->tank_moveBackward(category);
  } else if (cId == TANK_ROTATE_LEFT) {
    this->mapModel->tank_rotateLeft(category);
  } else if (cId == TANK_ROTATE_RIGHT) {
    this->mapModel->tank_rotateRight(category);
  }
}

void MapViewModel::get_shootCommand(Item category, Command cId) {
  Q_UNUSED(cId);
  this->mapModel->tank_shoot(category);
}

void MapViewModel::get_clearCommand() { this->mapModel->resetGame(); }

void MapViewModel::get_Notification(Item category, Notification nId) {
  if (nId == TANK_MOVE_FORWARD) {
    if (category == RED_TANK)
      this->red_tank->setPos(this->mapModel->getTankPosition(category));
    else if (category == GREEN_TANK)
      this->green_tank->setPos(this->mapModel->getTankPosition(category));
    emit tank_move(category, nId);
  } else if (nId == TANK_MOVE_BACKWARD) {
    if (category == RED_TANK)
      this->red_tank->setPos(this->mapModel->getTankPosition(category));
    else if (category == GREEN_TANK)
      this->green_tank->setPos(this->mapModel->getTankPosition(category));
    emit tank_move(category, nId);
  } else if (nId == TANK_ROTATE_LEFT) {
    if (category == RED_TANK)
      this->red_tank->setAngle(this->mapModel->getTankAngle(category));
    else if (category == GREEN_TANK)
      this->green_tank->setAngle(this->mapModel->getTankAngle(category));
    emit tank_move(category, nId);
  } else if (nId == TANK_ROTATE_RIGHT) {
    if (category == RED_TANK)
      this->red_tank->setAngle(this->mapModel->getTankAngle(category));
    else if (category == GREEN_TANK)
      this->green_tank->setAngle(this->mapModel->getTankAngle(category));
    emit tank_move(category, nId);
  } else if (nId == BULLET_CHANGE) {
    QVector<Bullet *> modelBullets = this->mapModel->getBullets(RED_TANK);
    for (int i = 0; i < MAX_TANK_BULLETS; i++) {
      bullets[i] = modelBullets[i];
    }
    modelBullets = this->mapModel->getBullets(GREEN_TANK);
    for (int i = 0; i < MAX_TANK_BULLETS; i++) {
      bullets[i + MAX_TANK_BULLETS] = modelBullets[i];
    }
    emit bullet_change(category, nId);
  } else if (nId == SCORE_CHANGE) {
    redScore = this->mapModel->getRedScore();
    greenScore = this->mapModel->getGreenScore();
    emit score_change(category, nId);
  }
}
