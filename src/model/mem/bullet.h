#ifndef BULLET_H
#define BULLET_H

#include <tpoint.h>

#include <QObject>
#include <QTimer>

class Bullet : public TPoint {
  Q_OBJECT
 public:
  explicit Bullet(QObject *parent = nullptr);
  Bullet(qreal x, qreal y, qreal angle = 0, QObject *parent = nullptr);
  ~Bullet();
  void moveForward();
  bool isAvailable();
  void setExist();
  void destroy();
  QVector<QPointF> getVertices();
  QPointF getNextPosition();

 private:
  bool exist;  // 是否存在地图中
  QTimer *life_timer;
};

#endif  // BULLET_H
