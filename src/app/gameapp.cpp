#include "gameapp.h"
#include "common.h"

GameApp::GameApp(int &argc, char **argv, int)
    : QApplication(argc, argv),
    red_tankModel(RED_TANK_INIT_X, RED_TANK_INIT_Y, RED_TANK_INIT_ANGLE),
    red_tankVM(RED_TANK_INIT_X, RED_TANK_INIT_Y, RED_TANK_INIT_ANGLE, RED_TANK),
    green_tankModel(GREEN_TANK_INIT_X, GREEN_TANK_INIT_Y, GREEN_TANK_INIT_ANGLE),
    green_tankVM(GREEN_TANK_INIT_X, GREEN_TANK_INIT_Y, GREEN_TANK_INIT_ANGLE, GREEN_TANK)
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

    green_tankVM.attach_tankmodel(&green_tankModel);
    connect(&green_tankModel, &TankModel::tank_move, &green_tankVM, &TankViewModel::get_Notification);

    // properties
    // mainWND.getGamePage()->attach_redTankItem(red_tankVM.get_tankItem());
    mainWND.getGamePage()->attach_redTank(red_tankVM.get_tank());

    mainWND.getGamePage()->attach_greenTank(green_tankVM.get_tank());

    // command
    // connect(mainWND.getGamePage(), &GamePage::keyPress_red, &red_tankVM, &TankViewModel::get_moveCommand);
    connect(mainWND.getGamePage(), &GamePage::red_move, &red_tankVM, &TankViewModel::get_moveCommand);
    connect(mainWND.getGamePage(), &GamePage::red_rotate, &red_tankVM, &TankViewModel::get_rotateCommand);

    connect(mainWND.getGamePage(), &GamePage::green_move, &green_tankVM, &TankViewModel::get_moveCommand);
    connect(mainWND.getGamePage(), &GamePage::green_rotate, &green_tankVM, &TankViewModel::get_rotateCommand);

    //notifications
    connect(&red_tankVM, &TankViewModel::tank_move, mainWND.getGamePage(), &GamePage::get_Notification);

    connect(&green_tankVM, &TankViewModel::tank_move, mainWND.getGamePage(), &GamePage::get_Notification);

    mainWND.show();
}
