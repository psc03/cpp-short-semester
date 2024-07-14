#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCheckBox>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QWidget>

#include "aboutpage.h"
#include "gamepage.h"
#include "initialpage.h"

class QStackedWidget;

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void init();
  GamePage *getGamePage();

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

#endif  // MAINWINDOW_H
