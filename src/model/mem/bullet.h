#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <tpoint.h>

class Bullet : public TPoint
{
    Q_OBJECT
public:
    explicit Bullet(QObject *parent = nullptr);
    Bullet(qreal x, qreal y, qreal angle = 0, QObject *parent = nullptr);
    ~Bullet();
    void moveForward();

private:
    bool exist; // 是否存在地图中
};

#endif // BULLET_H
