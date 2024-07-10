#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>
#include <QSet>
#include "tankitem.h"

class QHBoxLayout;
class QLabel;
class QLCDNumber;
class QGraphicsView;
class QGraphicsScene;
class QTimer;

class GamePage : public QWidget
{
    Q_OBJECT
public:
    explicit GamePage(QWidget *parent = nullptr);
    ~GamePage();
    void init();
    void attach_redTankItem(TankItem *tankItem);
    void attach_greenTankItem(TankItem *tankItem);

signals:
    // void keyPress_red(QKeyEvent *event);
    void keyPress_red(int key);

public slots:
    void get_Notification(qint32 eId);

private slots:
    void handleKeyPress_cmd();

private:
    QWidget *gameBoardContainer;
    QLabel *mapbg;
    QGraphicsView *gameBoard;

    QGraphicsScene *scene;
    TankItem *redTank;
    TankItem *greenTank;

    QWidget *scoreBoardContainer;
    QHBoxLayout *scoreBoard;
    QLabel *sb_redTank;
    QLabel *sb_greenTank;
    QLCDNumber *redScore;
    QLCDNumber *greenScore;

    QTimer *timer;

    QSet<int> keyPressed;

    // QWidget interface
protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;
};

#endif // GAMEPAGE_H
