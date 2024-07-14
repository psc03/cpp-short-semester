#include "gameapp.h"
#include "common.h"

GameApp::GameApp(int &argc, char **argv, int)
    : QApplication(argc, argv)
{
    this->init();
}

GameApp::~GameApp()
{

}

void GameApp::init()
{
    mainWND.setWindowTitle("Tank Trouble");

    // binding
    mapVM.attach_mapModel(&mapModel);
    connect(&mapModel, &MapModel::tank_move, &mapVM, &MapViewModel::get_Notification);
    connect(&mapModel, &MapModel::bullet_change, &mapVM, &MapViewModel::get_Notification);
    connect(&mapModel, &MapModel::score_change, &mapVM, &MapViewModel::get_Notification);

    // properties
    mainWND.getGamePage()->attach_redTank(mapVM.get_tank(RED_TANK));
    mainWND.getGamePage()->attach_greenTank(mapVM.get_tank(GREEN_TANK));

    mainWND.getGamePage()->attach_bullets(mapVM.get_bullets());

    mainWND.getGamePage()->attach_walls(mapVM.get_walls());

    mainWND.getGamePage()->attach_score(mapVM.get_redScore(), mapVM.get_greenScore());

    // command
    connect(mainWND.getGamePage(), &GamePage::tank_move, &mapVM, &MapViewModel::get_moveCommand);
    connect(mainWND.getGamePage(), &GamePage::tank_shoot, &mapVM, &MapViewModel::get_shootCommand);
    connect(mainWND.getGamePage(), &GamePage::game_clear, &mapVM, &MapViewModel::get_clearCommand);

    // notification
    connect(&mapVM, &MapViewModel::tank_move, mainWND.getGamePage(), &GamePage::get_Notification);
    connect(&mapVM, &MapViewModel::bullet_change, mainWND.getGamePage(), &GamePage::get_Notification);
    connect(&mapVM, &MapViewModel::score_change, mainWND.getGamePage(), &GamePage::get_Notification);

    mainWND.show();
}
