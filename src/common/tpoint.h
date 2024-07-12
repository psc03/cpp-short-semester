#ifndef TPOINT_H
#define TPOINT_H

#include <QObject>
#include "common.h"

class TPoint : public QObject
{
    Q_OBJECT
public:
    explicit TPoint(QObject *parent = nullptr);
    TPoint(qreal x, qreal y, qreal angle = 0, QObject *parent = nullptr);
    TPoint(qreal x, qreal y, Item category = RED_TANK, qreal angle = 0, QObject *parent = nullptr);
    TPoint (const TPoint & others);
    ~TPoint();

    virtual int getId();
    virtual void setId(int id);

    virtual Item getCategory();
    virtual void setCategory(Item category);

    virtual QPointF position() const;
    virtual qreal getX() const;
    virtual void setX(qreal x);
    virtual qreal getY() const;
    virtual void setY(qreal y);
    virtual void setPos(const QPointF& pos);
    virtual void setPos(const qreal x, const qreal y);
    virtual void moveBy(const qreal dx, const qreal dy);

    virtual qreal getAngle() const;
    virtual void setAngle(qreal angle);
    virtual void rotate(qreal dangle);

    virtual bool isAvailable();

// signals:

protected:
    int id;
    Item category;
    qreal x;
    qreal y;
    qreal angle;
};

#endif // TPOINT_H
