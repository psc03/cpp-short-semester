#include "gamepage.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QHBoxLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QMouseEvent>
#include <QTimer>

GamePage::GamePage(QWidget *parent)
    : QWidget{parent},
    gameBoardContainer(new QWidget(this)),
    mapbg(new QLabel(gameBoardContainer)),
    gameBoard(new QGraphicsView(gameBoardContainer)),
    scene(new QGraphicsScene(this)),
    scoreBoardContainer(new QWidget(this)),
    scoreBoard(new QHBoxLayout(scoreBoardContainer)),
    sb_redTank(new QLabel(scoreBoardContainer)),
    sb_greenTank(new QLabel(scoreBoardContainer)),
    redScore(new QLCDNumber(scoreBoardContainer)),
    greenScore(new QLCDNumber(scoreBoardContainer)),
    timer(new QTimer(this))
{
    this->init();
}

GamePage::~GamePage()
{
    // delete this;
}

void GamePage::init()
{
    // tank = new QPixmap;
    // tank->load(":/pic/pictures/Tank_Red.png");
    // tank->load(".../picture/Tank_Red.png");
    // tank->load("Tank_Red.png");
    // QPainter painter;
    // painter.drawPixmap(100, 100, *tank);
    // QGraphicsScene *pScene = new QGraphicsScene();
    // pScene->setSceneRect(0, 0, 400, 400);
    // pScene->addPixmap(*tank);
    // QGraphicsPixmapItem *pmi_tank = new QGraphicsPixmapItem(*tank);
    // pmi_tank->setPos(0, 0);
    // pmi_tank->setScale(5);
    // pScene->addItem(pmi_tank);
    // QGraphicsView *pView = new QGraphicsView(pScene, this);
    // pView->setMinimumSize(400, 400);
    // lay = new QHBoxLayout();
    // box1 = new QCheckBox("underline");
    // lay->addWidget(box1);
    // setLayout(lay);
    // this->close();

    this->setObjectName("GamePage");
    this->resize(500, 600);

    scoreBoardContainer->setObjectName("scoreBoardContainer");
    scoreBoardContainer->setGeometry(QRect(17, 509, 464, 82));
    scoreBoardContainer->setLayout(scoreBoard);
    scoreBoardContainer->setStyleSheet("QWidget { border: 1px solid black; }");

    scoreBoard->setObjectName("scoreBoard");
    scoreBoard->setContentsMargins(0, 0, 0, 0);
    // scoreBoard->setGeometry(QRect(17, 509, 464, 82));


    sb_redTank->setObjectName("sb_redTank");
    sb_redTank->setPixmap(QPixmap(":/pic/pictures/Tank_Red_Big.png"));
    sb_redTank->setStyleSheet("QLabel { border: 1px solid black; }");
    sb_redTank->setScaledContents(true);

    scoreBoard->addWidget(sb_redTank);

    redScore->setObjectName("redScore");

    scoreBoard->addWidget(redScore);

    sb_greenTank->setObjectName("sb_greenTank");
    sb_greenTank->setPixmap(QPixmap(":/pic/pictures/Tank_Green_Big.png"));
    sb_greenTank->setStyleSheet("QLabel { border: 1px solid black; }");
    sb_greenTank->setScaledContents(true);


    scoreBoard->addWidget(sb_greenTank);

    greenScore->setObjectName("greenScore");

    scoreBoard->addWidget(greenScore);

    gameBoardContainer->setObjectName("gameBoardContainer");
    gameBoardContainer->setGeometry(QRect(0, 0, 500, 500));

    mapbg->setObjectName("mapbg");
    mapbg->setGeometry(QRect(0, 0, 500, 500));
    mapbg->setPixmap(QPixmap(":/pic/pictures/map_background.png"));
    mapbg->setScaledContents(true);

    gameBoard->setObjectName("gameBoard");
    gameBoard->setGeometry(QRect(5, 5, 491, 491));
    gameBoard->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gameBoard->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // redTank = new TankItem(QPixmap(":/pic/pictures/Tank_Red.png"));
    // redTank->setPos(0, 0);
    // scene->addItem(redTank);

    greenTank = new TankItem(QPixmap(":/pic/pictures/Tank_Green.png"));
    greenTank->setPos(3, 300);
    scene->addItem(greenTank);

    // 设置视图
    gameBoard->setScene(scene);
    scene->setSceneRect(0, 0, gameBoard->width(), gameBoard->height());
    qDebug() << gameBoard->width() << Qt::endl;
    qDebug() << gameBoard->height() << Qt::endl;

    connect(timer, &QTimer::timeout, this, &GamePage::handleKeyPress_cmd);
    timer->start(8);  // 大约60帧每秒
}

void GamePage::attach_redTankItem(TankItem *tankItem)
{
    this->redTank = tankItem;
    this->redTank->setPixmap(QPixmap(":/pic/pictures/Tank_Red.png"));
    this->redTank->setPos(0, 0);
    scene->addItem(redTank);
}

void GamePage::attach_greenTankItem(TankItem *tankItem)
{
    this->greenTank = tankItem;
}

void GamePage::get_Notification(qint32 eId)
{
    Q_UNUSED(eId);
}

void GamePage::handleKeyPress_cmd()
{
    if(keyPressed.contains(Qt::Key_W)){
        emit keyPress_red(Qt::Key_W);
    }
    if(keyPressed.contains(Qt::Key_S)){
        emit keyPress_red(Qt::Key_S);
    }
    if(keyPressed.contains(Qt::Key_A)){
        emit keyPress_red(Qt::Key_A);
    }
    if(keyPressed.contains(Qt::Key_D)){
        emit keyPress_red(Qt::Key_D);
    }
    // if(keyPressed.contains(Qt::Key_Up)){
    //     emit keyPress_green(Qt::Key_Up);
    // }
    // if(keyPressed.contains(Qt::Key_Down)){
    //     emit keyPress_green(Qt::Key_Down);
    // }
    // if(keyPressed.contains(Qt::Key_Left)){
    //     emit keyPress_green(Qt::Key_Left);
    // }
    // if(keyPressed.contains(Qt::Key_Right)){
    //     emit keyPress_green(Qt::Key_Right);
    // }
    // emit keyPress_red();
}


void GamePage::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W || event->key() == Qt::Key_S ||
        event->key() == Qt::Key_A || event->key() == Qt::Key_D){
        // qDebug() << "press w" << Qt::endl;
        keyPressed.insert(event->key());
    }
    // QWidget::keyPressEvent(event);
}


void GamePage::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W || event->key() == Qt::Key_S ||
        event->key() == Qt::Key_A || event->key() == Qt::Key_D){
        // qDebug() << "press w" << Qt::endl;
        keyPressed.remove(event->key());
    }
    // QWidget::keyPressEvent(event);
}
