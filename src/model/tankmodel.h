#ifndef TANKMODEL_H
#define TANKMODEL_H

#include <QObject>
#include "tpoint.h"

class TankModel : public TPoint
{
    Q_OBJECT
public:
    explicit TankModel(QObject *parent = nullptr);
    TankModel(qreal x, qreal y, qreal angle = 0, QObject *parent = nullptr);
    ~TankModel();

    void moveForward();
    void moveBackward();
    void rotateLeft();
    void rotateRight();
    // virtual
signals:
    void tank_move(qint32 eId);

private:

};

#endif // TANKMODEL_H
