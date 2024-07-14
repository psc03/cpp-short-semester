#ifndef TANK_H
#define TANK_H

#include <tpoint.h>

#include <QObject>

#include "common.h"

class Tank : public TPoint {
  Q_OBJECT
 public:
  explicit Tank(QObject *parent = nullptr);
  Tank(qreal x, qreal y, qreal angle = 0, QObject *parent = nullptr);
  Tank(Item color, qreal x, qreal y, qreal angle = 0,
       QObject *parent = nullptr);
  ~Tank();
  void moveForward();
  void moveBackward();
  void rotateLeft();
  void rotateRight();
  QVector<QPointF> getVertices();

 private:
  Item color;
};

#endif  // TANK_H
