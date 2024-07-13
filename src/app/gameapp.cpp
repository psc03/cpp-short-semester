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
    // red_tankVM.attach_tankmodel(&red_tankModel);
    // connect(&red_tankModel, &TankModel::tank_move, &red_tankVM, &TankViewModel::get_Notification);
    // green_tankVM.attach_tankmodel(&green_tankModel);
    // connect(&green_tankModel, &TankModel::tank_move, &green_tankVM, &TankViewModel::get_Notification);

    mapVM.attach_mapModel(&mapModel);
    connect(&mapModel, &MapModel::tank_move, &mapVM, &MapViewModel::get_Notification);
    connect(&mapModel, &MapModel::bullet_change, &mapVM, &MapViewModel::get_Notification);
    connect(&mapModel, &MapModel::score_change, &mapVM, &MapViewModel::get_Notification);
    // properties
    // mainWND.getGamePage()->attach_redTankItem(red_tankVM.get_tankItem());
    // mainWND.getGamePage()->attach_redTank(red_tankVM.get_tank());
    // mainWND.getGamePage()->attach_greenTank(green_tankVM.get_tank());

    mainWND.getGamePage()->attach_redTank(mapVM.get_tank(RED_TANK));

    mainWND.getGamePage()->attach_greenTank(mapVM.get_tank(GREEN_TANK));

    mainWND.getGamePage()->attach_bullets(mapVM.get_bullets());

    mainWND.getGamePage()->attach_walls(mapVM.get_walls());

    mainWND.getGamePage()->attach_score(mapVM.get_redScore(), mapVM.get_greenScore());

    // command
    // connect(mainWND.getGamePage(), &GamePage::keyPress_red, &red_tankVM, &TankViewModel::get_moveCommand);
    // connect(mainWND.getGamePage(), &GamePage::red_move, &red_tankVM, &TankViewModel::get_moveCommand);
    // connect(mainWND.getGamePage(), &GamePage::red_rotate, &red_tankVM, &TankViewModel::get_rotateCommand);
    // connect(mainWND.getGamePage(), &GamePage::green_move, &green_tankVM, &TankViewModel::get_moveCommand);
    // connect(mainWND.getGamePage(), &GamePage::green_rotate, &green_tankVM, &TankViewModel::get_rotateCommand);

    connect(mainWND.getGamePage(), &GamePage::tank_move, &mapVM, &MapViewModel::get_moveCommand);
    connect(mainWND.getGamePage(), &GamePage::tank_shoot, &mapVM, &MapViewModel::get_shootCommand);
    connect(mainWND.getGamePage(), &GamePage::game_clear,&mapVM, &MapViewModel::get_clearCommand);


    connect(&mapVM, &MapViewModel::tank_move, mainWND.getGamePage(), &GamePage::get_Notification);
    connect(&mapVM, &MapViewModel::bullet_change, mainWND.getGamePage(), &GamePage::get_Notification);
    connect(&mapVM, &MapViewModel::score_change, mainWND.getGamePage(), &GamePage::get_Notification);

    mainWND.show();
}
