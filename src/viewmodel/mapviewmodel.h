#ifndef MAPVIEWMODEL_H
#define MAPVIEWMODEL_H

#include <QObject>
#include "mapmodel.h"
#include "tpoint.h"
#include "common.h"

class MapViewModel : public QObject
{
    Q_OBJECT
public:
    explicit MapViewModel(QObject *parent = nullptr);
    ~MapViewModel();
    void attach_mapModel(MapModel *mapModel);
    TPoint *get_tank(Item color);

signals:
    void tank_move(Item category, Notification nId);

public slots:
    void get_moveCommand(Item category, Command cId);
    // void get_rotateCommand(Item category, Command cId);
    void get_Notification(Item category, Notification nId);


private:
    MapModel *mapModel;
    TPoint *red_tank;
    TPoint *green_tank;
};

#endif // MAPVIEWMODEL_H
