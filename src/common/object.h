#ifndef OBJECT_H
#define OBJECT_H

#include <QObject>

class Object: public QObject{
    Q_OBJECT
public:
    // virtual double setX1(double);
    // virtual double setY1(double);
    // virtual double setX2(double);
    // virtual double setY2(double);
    // virtual double getX1(double);
    // virtual double getY1(double);
    // virtual double getX2(double);
    // virtual double getY2(double);
private:
    double x1;
    double y1;
    double x2;
    double y2;
};

#endif // OBJECT_H
