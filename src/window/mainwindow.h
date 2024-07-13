#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "initialpage.h"
#include "aboutpage.h"
#include "gamepage.h"
#include <QCheckBox>
#include <QHBoxLayout>

class QStackedWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void init();
    GamePage* getGamePage();

// signals:

private slots:
    void do_showInitialPage();
    void do_showAboutPage();
    void do_showGamePage();

private:
    QStackedWidget *stackedWidget;
    InitialPage *initialpage;
    AboutPage *aboutPage;
    GamePage *gamePage;
};

#endif // MAINWINDOW_H
