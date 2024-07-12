#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <tpoint.h>
#include <QTimer>

class Bullet : public TPoint
{
    Q_OBJECT
public:
    explicit Bullet(QObject *parent = nullptr);
    Bullet(qreal x, qreal y, qreal angle = 0, QObject *parent = nullptr);
    ~Bullet();
    void moveForward();
    bool isAvailable();
    void setExist();
    void destroy();

private:
    bool exist; // 是否存在地图中
    // QTimer *move_timer;
    QTimer *life_timer;

    // friend class MapModel;
};

#endif // BULLET_H