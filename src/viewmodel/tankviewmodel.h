#ifndef TANKVIEWMODEL_H
#define TANKVIEWMODEL_H

#include <QObject>
#include "tankmodel.h"
#include "tankitem.h"
#include "tpoint.h"

class TankViewModel : public QObject
{
    Q_OBJECT
public:
    explicit TankViewModel(QObject *parent = nullptr);
    TankViewModel(qreal x, qreal y, qreal angle = 0, QObject *parent = nullptr);
    ~TankViewModel();
    void attach_tankmodel(TankModel *tankModel);
    // void attach_item(TankItem *tankItem);
    // TankItem* get_tankItem();
    TPoint* get_tank();

signals:
    void tank_move(qint32 eId);

public slots:
    // void get_MoveCommand(QKeyEvent *event);
    void get_MoveCommand(int key);
    void get_Notification(qint32 eId);

private:
    TankModel *tankModel;
    // TankItem *tankItem;
    TPoint *tank;
};

#endif // TANKVIEWMODEL_H
