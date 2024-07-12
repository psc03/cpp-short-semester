#ifndef TANK_H
#define TANK_H

#include <QObject>
#include <tpoint.h>
#include "common.h"

class Tank : public TPoint
{
    Q_OBJECT
public:
    explicit Tank(QObject *parent = nullptr);
    Tank(qreal x, qreal y, qreal angle = 0, QObject *parent = nullptr);
    Tank(Item color, qreal x, qreal y, qreal angle = 0, QObject *parent = nullptr);
    ~Tank();
    void moveForward();
    void moveBackward();
    void rotateLeft();
    void rotateRight();

private:
    Item color;
};

#endif // TANK_H
