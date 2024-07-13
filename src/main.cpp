#include <QApplication>
#include "gameapp.h"

int main(int argc, char *argv[])
{
    // QApplication app(argc, argv);
    GameApp app(argc, argv);
    return app.exec();
}
