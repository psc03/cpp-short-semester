// #include "window/mainwindow.h"

#include <QApplication>
#include "gameapp.h"

int main(int argc, char *argv[])
{
    // QApplication app(argc, argv);
    GameApp app(argc, argv);
    // MainWindow w;
    // w.setWindowTitle("Tank Trouble");
    // w.show();
    // app.exec();
    // system("pause");
    return app.exec();
}
