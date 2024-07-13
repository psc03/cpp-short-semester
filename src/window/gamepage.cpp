#include "gamepage.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsEllipseItem>
#include <QHBoxLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QMouseEvent>
#include <QTimer>

int GamePage::intervalOfShoot = 100;

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
    redScoreLCD(new QLCDNumber(scoreBoardContainer)),
    greenScoreLCD(new QLCDNumber(scoreBoardContainer)),
    commandTimer(new QTimer(this)),
    redTankShootTimer(new QTimer(this)),
    greenTankShootTimer(new QTimer(this)),
    resetGameTimer(new QTimer(this))
{
    init();
}

GamePage::~GamePage()
{
    // delete this;
}

void GamePage::init()
{
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

    redScoreLCD->setObjectName("redScore");

    scoreBoard->addWidget(redScoreLCD);

    sb_greenTank->setObjectName("sb_greenTank");
    sb_greenTank->setPixmap(QPixmap(":/pic/pictures/Tank_Green_Big.png"));
    sb_greenTank->setStyleSheet("QLabel { border: 1px solid black; }");
    sb_greenTank->setScaledContents(true);


    scoreBoard->addWidget(sb_greenTank);

    greenScoreLCD->setObjectName("greenScore");

    scoreBoard->addWidget(greenScoreLCD);

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

    redTankItem = new QGraphicsPixmapItem(QPixmap(":/pic/pictures/Tank_Red.png"));
    redTankItem->setTransformOriginPoint(redTankItem->pixmap().width() / 2, redTankItem->pixmap().height() / 2);
    redTankItem->setPos(RED_TANK_INIT_X, RED_TANK_INIT_Y);
    scene->addItem(redTankItem);

    greenTankItem = new QGraphicsPixmapItem(QPixmap(":/pic/pictures/Tank_Green.png"));
    greenTankItem->setTransformOriginPoint(greenTankItem->pixmap().width() / 2, greenTankItem->pixmap().height() / 2);
    greenTankItem->setPos(GREEN_TANK_INIT_X, GREEN_TANK_INIT_Y);
    scene->addItem(greenTankItem);

    for(int i = 0; i < MAX_TANK_BULLETS * 2; i++){
        QGraphicsEllipseItem *bulletItem = new QGraphicsEllipseItem();
        bulletItem->setBrush(Qt::black);
        bulletItem->setRect(0, 0, BULLET_WIDTH, BULLET_HEIGHT);
        bulletItem->setVisible(false);
        bulletItems.push_back(bulletItem);
        scene->addItem(bulletItem);
    }

    // 设置视图
    gameBoard->setScene(scene);
    scene->setSceneRect(0, 0, gameBoard->width(), gameBoard->height());
    qDebug() << gameBoard->width() << Qt::endl;
    qDebug() << gameBoard->height() << Qt::endl;

    connect(commandTimer, &QTimer::timeout, this, &GamePage::handleKeyPress_cmd);
    commandTimer->start(8);  // 大约60帧每秒

    redTankShootTimer->setSingleShot(true);
    greenTankShootTimer->setSingleShot(true);
    resetGameTimer->setSingleShot(true);
    connect(resetGameTimer,&QTimer::timeout,this,&GamePage::game_clear);

    //设置声音
    out = new QAudioOutput();
    shoot1 = new QMediaPlayer();
    shoot1->setSource(QUrl("qrc:/s/sound/shoot1.mp4"));
    shoot1->setAudioOutput(out);
    out = new QAudioOutput();
    shoot2 = new QMediaPlayer();
    shoot2->setSource(QUrl("qrc:/s/sound/shoot2.mp4"));
    shoot2->setAudioOutput(out);
    out = new QAudioOutput();
    boom = new QMediaPlayer();
    boom->setSource(QUrl("qrc:/s/sound/boom.mp4"));
    boom->setAudioOutput(out);
}

void GamePage::attach_redTank(TPoint *tank)
{
    this->redTank = tank;
}

void GamePage::attach_greenTank(TPoint *tank)
{
    this->greenTank = tank;
}

void GamePage::attach_bullets(QVector<TPoint *> *bullets)
{
    this->bullets = bullets;
}

void GamePage::attach_walls(QVector<Wall *> *walls)
{
    this->walls = walls;
    // Walls TODO: ?
    for(auto wall: (*walls)){
        QGraphicsRectItem* wallItem = new QGraphicsRectItem(wall->getX(), wall->getY(), wall->getWidth(), wall->getHeight());
        wallItem->setBrush(QBrush(Qt::black));
        wallItem->setPen(QPen(Qt::black));
        wallItems.push_back(wallItem);
        scene->addItem(wallItem);
    }
}

void GamePage::attach_score(int *redScore, int *greenScore)
{
    this->redScore = redScore;
    this->greenScore = greenScore;
}

void GamePage::get_Notification(Item category, Notification nId)
{
    if(nId == TANK_MOVE_FORWARD || nId == TANK_MOVE_BACKWARD){
        if(category == RED_TANK) this->redTankItem->setPos(this->redTank->getX(), this->redTank->getY());
        else if(category == GREEN_TANK) this->greenTankItem->setPos(this->greenTank->getX(), this->greenTank->getY());
    }
    else if(nId == TANK_ROTATE_LEFT || nId == TANK_ROTATE_RIGHT){
        if(category == RED_TANK) this->redTankItem->setRotation(this->redTank->getAngle());
        else if(category == GREEN_TANK) this->greenTankItem->setRotation(this->greenTank->getAngle());
    }
    else if(nId == BULLET_CHANGE){
        for(int i = 0; i < bullets->size(); i++){
            bulletItems[i]->setPos((*bullets).at(i)->position());
            if((*bullets).at(i)->isAvailable()) bulletItems[i]->setVisible(false);
            else bulletItems[i]->setVisible(true);
        }
    }
    else if(nId == SCORE_CHANGE){
        if(boom->playbackState()==QMediaPlayer::PlayingState)
            boom->setPosition(0);
        else if(boom->playbackState()==QMediaPlayer::StoppedState)
            boom->play();
        redScoreLCD->display(*redScore);
        greenScoreLCD->display(*greenScore);
    }
}

void GamePage::handleKeyPress_cmd()
{
    // qDebug() << "position "<< redTankItem->x()<<" "<<redTankItem->y();
    if(keyPressed.contains(Qt::Key_W)){
        // emit keyPress_red(Qt::Key_W);
        // emit red_move(TANK_MOVE_FORWARD);
        emit tank_move(RED_TANK, TANK_MOVE_FORWARD);
    }
    if(keyPressed.contains(Qt::Key_S)){
        // emit keyPress_red(Qt::Key_S);
        // emit red_move(TANK_MOVE_BACKWARD);
        emit tank_move(RED_TANK, TANK_MOVE_BACKWARD);
    }
    if(keyPressed.contains(Qt::Key_A)){
        // emit keyPress_red(Qt::Key_A);
        // emit red_rotate(TANK_ROTATE_LEFT);
        emit tank_move(RED_TANK, TANK_ROTATE_LEFT);
    }
    if(keyPressed.contains(Qt::Key_D)){
        // emit keyPress_red(Qt::Key_D);
        // emit red_rotate(TANK_ROTATE_RIGHT);
        emit tank_move(RED_TANK, TANK_ROTATE_RIGHT);
    }
    if(keyPressed.contains(Qt::Key_Space) && !redTankShootTimer->isActive()){
        redTankShootTimer->start(intervalOfShoot); // 冷却
        if(shoot1->playbackState()==QMediaPlayer::PlayingState)
            shoot1->setPosition(0);
        else if(shoot1->playbackState()==QMediaPlayer::StoppedState)
            shoot1->play();
        emit tank_shoot(RED_TANK, TANK_SHOOT);
    }
    if(keyPressed.contains(Qt::Key_Up)){
        // emit keyPress_green(Qt::Key_Up);
        // emit green_move(TANK_MOVE_FORWARD);
        emit tank_move(GREEN_TANK, TANK_MOVE_FORWARD);
    }
    if(keyPressed.contains(Qt::Key_Down)){
        // emit keyPress_green(Qt::Key_Down);
        // emit green_move(TANK_MOVE_BACKWARD);
        emit tank_move(GREEN_TANK, TANK_MOVE_BACKWARD);
    }
    if(keyPressed.contains(Qt::Key_Left)){
        // emit keyPress_green(Qt::Key_Left);
        // emit green_rotate(TANK_ROTATE_LEFT);
        emit tank_move(GREEN_TANK, TANK_ROTATE_LEFT);
    }
    if(keyPressed.contains(Qt::Key_Right)){
        // emit keyPress_green(Qt::Key_Right);
        // emit green_rotate(TANK_ROTATE_RIGHT);
        emit tank_move(GREEN_TANK, TANK_ROTATE_RIGHT);
    }
    if(keyPressed.contains(Qt::Key_M) && !greenTankShootTimer->isActive()){
        greenTankShootTimer->start(intervalOfShoot); // 冷却
        if(shoot2->playbackState()==QMediaPlayer::PlayingState)
            shoot2->setPosition(0);
        else if(shoot2->playbackState()==QMediaPlayer::StoppedState)
            shoot2->play();
        emit tank_shoot(GREEN_TANK, TANK_SHOOT);
    }
    // emit keyPress_red();
}

void GamePage::keyPressEvent(QKeyEvent *event)
{
    // Tank Operation
    if(event->key() == Qt::Key_W || event->key() == Qt::Key_S ||
        event->key() == Qt::Key_A || event->key() == Qt::Key_D ||
        event->key() == Qt::Key_Space ||
        event->key() == Qt::Key_Up || event->key() == Qt::Key_Down ||
        event->key() == Qt::Key_Left || event->key() == Qt::Key_Right ||
        event->key() == Qt::Key_M || event->key() == Qt::Key_R){
        // qDebug() << "press w" << Qt::endl;
        keyPressed.insert(event->key());
    }
    if(keyPressed.contains(Qt::Key_R) && !resetGameTimer->isActive()){
        // qDebug() << "reset timer";
        resetGameTimer->start(500);
    }
    // Page Switch Key
    if(event->key() == Qt::Key_Escape){
        releaseKeyboard();
        emit switchToInitialPage();
    }
}


void GamePage::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W || event->key() == Qt::Key_S ||
        event->key() == Qt::Key_A || event->key() == Qt::Key_D ||
        event->key() == Qt::Key_Space ||
        event->key() == Qt::Key_Up || event->key() == Qt::Key_Down ||
        event->key() == Qt::Key_Left || event->key() == Qt::Key_Right ||
        event->key() == Qt::Key_M || event->key() == Qt::Key_R){
        // qDebug() << "press w" << Qt::endl;
        keyPressed.remove(event->key());
    }
    if(event->key() == Qt::Key_R){
        qDebug() << "stop";
        resetGameTimer->stop();
    }
    // QWidget::keyPressEvent(event);
}
