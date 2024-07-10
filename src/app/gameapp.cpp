#include "gameapp.h"
#include "common.h"

GameApp::GameApp(int &argc, char **argv, int)
    : QApplication(argc, argv),
    red_tankModel(RED_TANK_INIT_X, RED_TANK_INIT_Y, RED_TANK_INIT_ANGLE),
    red_tankVM(RED_TANK_INIT_X, RED_TANK_INIT_Y, RED_TANK_INIT_ANGLE)
{
    this->init();
}

GameApp::~GameApp()
{
    // delete mainWND;
}

void GameApp::init()
{
    // mainWND = new MainWindow();
    mainWND.setWindowTitle("Tank Trouble");

    // binding
    red_tankVM.attach_tankmodel(&red_tankModel);
    connect(&red_tankModel, &TankModel::tank_move, &red_tankVM, &TankViewModel::get_Notification);

    // properties
    // mainWND.getGamePage()->attach_redTankItem(red_tankVM.get_tankItem());
    mainWND.getGamePage()->attach_redTank(red_tankVM.get_tank());

    // command
    connect(mainWND.getGamePage(), &GamePage::keyPress_red, &red_tankVM, &TankViewModel::get_MoveCommand);

    //notifications
    connect(&red_tankVM, &TankViewModel::tank_move, mainWND.getGamePage(), &GamePage::get_Notification);

    mainWND.show();
}
