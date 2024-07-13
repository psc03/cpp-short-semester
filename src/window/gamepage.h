#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>
#include <QSet>
#include <QVector>
#include <QGraphicsRectItem>
// #include "tankitem.h"
#include "tpoint.h"

// TODO: 哪里放置wall

#include "mem/wall.h"
#include "common.h"

class QHBoxLayout;
class QLabel;
class QLCDNumber;
class QGraphicsView;
class QGraphicsScene;
class QGraphicsPixmapItem;
class QGraphicsEllipseItem;
class QTimer;

class GamePage : public QWidget
{
    Q_OBJECT
public:
    explicit GamePage(QWidget *parent = nullptr);
    ~GamePage();
    void init();
    // void attach_redTankItem(TankItem *tankItem);
    // void attach_greenTankItem(TankItem *tankItem);
    void attach_redTank(TPoint *tank);
    void attach_greenTank(TPoint *tank);
    void attach_bullets(QVector<TPoint *> *bullets);
    void attach_walls(QVector<Wall *> *walls);
    void attach_score(int *redScore, int *greenScore);

signals:
    // void keyPress_red(QKeyEvent *event);
    // void keyPress_red(int key);
    // void red_move(int sId);
    // void red_rotate(int sId);

    // void green_move(int sId);
    // void green_rotate(int sId);

    void tank_move(Item color, Command cId);
    void tank_shoot(Item color, Command cId);

    void switchToInitialPage();

public slots:
    // void get_Notification(qint32 eId);
    void get_Notification(Item category, Notification nId);

private slots:
    void handleKeyPress_cmd();

private:
    QWidget *gameBoardContainer;
    QLabel *mapbg;
    QGraphicsView *gameBoard;

    QGraphicsScene *scene;
    // TankItem *redTankItem;
    // TankItem *greenTankItem;
    QGraphicsPixmapItem *redTankItem;
    QGraphicsPixmapItem *greenTankItem;
    QVector<QGraphicsEllipseItem *> bulletItems;
    QVector<QGraphicsRectItem *> wallItems;

    QWidget *scoreBoardContainer;
    QHBoxLayout *scoreBoard;
    QLabel *sb_redTank;
    QLabel *sb_greenTank;
    QLCDNumber *redScoreLCD;
    QLCDNumber *greenScoreLCD;

    QTimer *commandTimer;
    QTimer *redTankShootTimer; // 发射间隔 冷却时间
    QTimer *greenTankShootTimer;

    QSet<int> keyPressed;

    TPoint *redTank;
    TPoint *greenTank;
    QVector<TPoint *> *bullets;

    static int intervalOfShoot; // ms 发射间隔

    QVector<Wall *> *walls;

    int *redScore;
    int *greenScore;
    // QWidget interface

protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;
};

#endif // GAMEPAGE_H
