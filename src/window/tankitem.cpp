#include "tankitem.h"

TankItem::TankItem() {}

TankItem::TankItem(qreal angle)
    : angle(angle)
{

}

TankItem::TankItem(const QPixmap &pixmap)
    : QGraphicsPixmapItem(pixmap),
    angle(0)
{
    this->setTransformOriginPoint(pixmap.width() / 2, pixmap.height() / 2);
}

TankItem::TankItem(const QPixmap &pixmap, qreal angle)
    : QGraphicsPixmapItem(pixmap),
    angle(angle)
{
    this->setTransformOriginPoint(pixmap.width() / 2, pixmap.height() / 2);
}

TankItem::~TankItem()
{

}

void TankItem::setPixmap(const QPixmap &pixmap)
{
    // 非虚函数重载
    QGraphicsPixmapItem::setPixmap(pixmap);
    this->setTransformOriginPoint(pixmap.width() / 2, pixmap.height() / 2);
}

qreal TankItem::getAngle()
{
    return angle;
}
