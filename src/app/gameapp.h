#ifndef GAMEAPP_H
#define GAMEAPP_H

#include <QApplication>
#include "tankviewmodel.h"
#include "mainwindow.h"

class GameApp : public QApplication
{
public:
    // GameApp() = delete;
    GameApp(int &argc, char **argv, int = ApplicationFlags);
    ~GameApp();
    void init();

private:
    TankModel red_tankModel;
    TankViewModel red_tankVM;
    TankModel green_tankModel;
    TankViewModel green_tankVM;
    MainWindow mainWND;
};

#endif // GAMEAPP_H
