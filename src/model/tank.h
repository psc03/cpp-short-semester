#ifndef TANK_H
#define TANK_H

#include <QObject>
// #include "object.h"

class tank : public QObject
{
    Q_OBJECT
public:
    explicit tank(QObject *parent = nullptr);
    // void move();

    // virtual
signals:
private:

};

#endif // TANK_H
