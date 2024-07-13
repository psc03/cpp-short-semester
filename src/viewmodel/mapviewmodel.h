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
    QVector<TPoint *> *get_bullets();
    QVector<Wall *> *get_walls();
    int *get_redScore();
    int *get_greenScore();

signals:
    void tank_move(Item category, Notification nId);
    void bullet_change(Item catogory, Notification nId);
    void score_change(Item catogory, Notification nId);

public slots:
    void get_moveCommand(Item category, Command cId);
    void get_shootCommand(Item category, Command cId);
    void get_clearCommand();
    void get_Notification(Item category, Notification nId);


private:
    MapModel *mapModel;
    TPoint *red_tank;
    TPoint *green_tank;
    QVector<TPoint *> bullets;
    QVector<Wall *> walls;
    int redScore;
    int greenScore;
};

#endif // MAPVIEWMODEL_H
