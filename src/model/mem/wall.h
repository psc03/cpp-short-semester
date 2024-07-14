#ifndef WALL_H
#define WALL_H

#include <QObject>
#include <QPointF>

class Wall : public QObject {
 public:
  Wall();
  Wall(qreal x, qreal y);
  Wall(qreal x, qreal y, qreal width, qreal height);
  ~Wall() = default;
  // 左上角坐标
  qreal getX();
  qreal getY();
  qreal getWidth();
  qreal getHeight();
  // 判断某个点是否在wall中
  bool inWall(QPointF position);

 private:
  qreal x;
  qreal y;
  qreal width;
  qreal height;
};

#endif  // WALL_H
