#ifndef TANKMODEL_H
#define TANKMODEL_H

#include <QObject>
// #include "object.h"
#include "base/tpoint.h"
#include <tankitem.h>

class TankModel : public TPoint
{
    Q_OBJECT
public:
    explicit TankModel(QObject *parent = nullptr);
    TankModel(qreal x, qreal y, qreal angle = 0, QObject *parent = nullptr);
    ~TankModel();
    // void moveForward(TankItem *tankItem);
    // void moveBackward(TankItem *tankItem);
    void moveForward();
    void moveBackward();
    void rotateLeft();
    void rotateRight();
    // virtual
signals:
    void tank_move(qint32 eId);

private:
    // bool canMove(const QPointF &newPos, TankItem *tankItem);
};

#endif // TANKMODEL_H
