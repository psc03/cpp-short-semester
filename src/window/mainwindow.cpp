#include "mainwindow.h"
#include <QStackedWidget>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent},
    stackedWidget(new QStackedWidget(this)),
    initialpage(new InitialPage(this)),
    aboutPage(new AboutPage(this)),
    gamePage(new GamePage(this))
{
    this->init();
}

MainWindow::~MainWindow()
{

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
