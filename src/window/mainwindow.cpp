#include "mainwindow.h"
#include <QStackedWidget>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

MainWindow::MainWindow(QWidget *parent)
    // : QWidget{parent},
    : QMainWindow{parent},
    stackedWidget(new QStackedWidget(this)),
    initialpage(new InitialPage(this)),
    aboutPage(new AboutPage(this)),
    gamePage(new GamePage(this))
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

    this->init();
}

MainWindow::~MainWindow()
{
    // delete this;
}

void MainWindow::init()
{
    this->resize(500, 600);
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(QColor(255,255,255)));

    setCentralWidget(stackedWidget); // QMainWindow写法

    stackedWidget->addWidget(initialpage);
    stackedWidget->addWidget(aboutPage);
    stackedWidget->addWidget(gamePage);

    stackedWidget->setCurrentWidget(initialpage);
    // stackedWidget->setCurrentWidget(aboutPage);
    // stackedWidget->setCurrentWidget(gamePage);

    // this->setLayout(new QVBoxLayout(this)); // QWidget写法
    // this->layout()->addWidget(stackedWidget);

    // initialpage->show();

    connect(initialpage, &InitialPage::switchToAboutPage, this, &MainWindow::do_showAboutPage);
    connect(initialpage, &InitialPage::switchToGamePage, this, &MainWindow::do_showGamePage);
    connect(aboutPage, &AboutPage::switchToInitialPage, this, &MainWindow::do_showInitialPage);
    connect(gamePage,&GamePage::switchToInitialPage, this, &MainWindow::do_showInitialPage);
}

GamePage* MainWindow::getGamePage()
{
    return gamePage;
}

void MainWindow::do_showInitialPage()
{
    stackedWidget->setCurrentWidget(initialpage);
}

void MainWindow::do_showAboutPage()
{
    stackedWidget->setCurrentWidget(aboutPage);
}

void MainWindow::do_showGamePage()
{
    gamePage->grabKeyboard(); // 保证上下左右键按下可以被捕获
    stackedWidget->setCurrentWidget(gamePage);
}
