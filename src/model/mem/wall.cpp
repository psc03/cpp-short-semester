#include "wall.h"
Wall::Wall()
{

}

Wall::Wall(qreal x, qreal y):
    x(x),y(y)
{

}

Wall::Wall(qreal x, qreal y, qreal width, qreal height):
    x(x),y(y),width(width),height(height)
{

}

qreal Wall::getX()
{
    return x;
}

qreal Wall::getY()
{
    return y;
}

qreal Wall::getWidth()
{
    return width;
}
qreal Wall::getHeight()
{
    return height;
}

bool Wall::inWall(QPointF position)
{
    if(position.x()>x && position.x() < (x+width) && position.y() > y && position.y() < y + height)
        return true;
    else
        return false;
}
