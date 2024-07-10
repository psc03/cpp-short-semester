#ifndef TPOINT_H
#define TPOINT_H

#include <QObject>

class TPoint : public QObject
{
    Q_OBJECT
public:
    explicit TPoint(QObject *parent = nullptr);
    TPoint(qreal x, qreal y, qreal angle = 0, QObject *parent = nullptr);
    ~TPoint();

    virtual int getId();
    virtual void setId(int id);

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

// signals:

protected:
    int id;
    qreal x;
    qreal y;
    qreal angle;
};

#endif // TPOINT_H
