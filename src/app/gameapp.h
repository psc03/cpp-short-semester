#ifndef GAMEAPP_H
#define GAMEAPP_H

#include <QApplication>
#include "mainwindow.h"
#include "mapmodel.h"
#include "mapviewmodel.h"

class GameApp : public QApplication
{
public:
    GameApp(int &argc, char **argv, int = ApplicationFlags);
    ~GameApp();
    void init();

private:
    MapModel mapModel;
    MapViewModel mapVM;
    MainWindow mainWND;
};

#endif // GAMEAPP_H
