#ifndef MAPMODEL_H
#define MAPMODEL_H

#include <QObject>
#include <QVector>

#include "common.h"
#include "mem/bullet.h"
#include "mem/tank.h"
#include "mem/wall.h"

class MapModel : public QObject {
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
  void resetBoard();
  void resetGame();
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
  QTimer *reset_interval;
  int redScore;
  int greenScore;

  bool tankCanMove(Tank tankNext);
  bool bulletCollide(Bullet *bullet, qreal &deltaX, qreal &deltaY);
  QPointF randomPosition();
  static int max_bullets;
};

const QVector<QPointF> tankPositions = {
    QPointF(10, 370),  QPointF(40, 290),  QPointF(40, 250),  QPointF(150, 300),
    QPointF(320, 330), QPointF(410, 340), QPointF(410, 280), QPointF(290, 180),
    QPointF(180, 120), QPointF(30, 80),   QPointF(410, 180), QPointF(390, 110),
    QPointF(280, 110), QPointF(270, 30),  QPointF(440, 220), QPointF(440, 310),
    QPointF(230, 430), QPointF(120, 410), QPointF(50, 160),  QPointF(350, 450),
    QPointF(380, 400), QPointF(440, 410), QPointF(350, 300), QPointF(310, 270),
    QPointF(230, 300), QPointF(200, 350), QPointF(190, 390), QPointF(360, 40),
    QPointF(420, 60),  QPointF(440, 100), QPointF(190, 20),  QPointF(120, 50),
    QPointF(70, 360),  QPointF(100, 220), QPointF(180, 230), QPointF(250, 240),
    QPointF(100, 120), QPointF(180, 170), QPointF(30, 220),  QPointF(90, 270),
    QPointF(50, 50),   QPointF(30, 110),  QPointF(100, 160), QPointF(170, 70),
    QPointF(420, 250), QPointF(440, 280), QPointF(320, 240), QPointF(240, 210),
    QPointF(280, 400), QPointF(280, 430), QPointF(160, 450), QPointF(110, 450),
    QPointF(160, 430), QPointF(190, 430), QPointF(240, 450), QPointF(90, 390),
    QPointF(160, 400), QPointF(280, 350), QPointF(350, 230), QPointF(350, 170),
    QPointF(350, 100), QPointF(280, 140)};
#endif  // MAPMODEL_H
