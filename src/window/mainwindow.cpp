#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QWidget{parent}
{
    // tank = new QPixmap;
    // tank->load(":/pic/pictures/Tank_Red.png");
    lay = new QHBoxLayout();
    box1 = new QCheckBox("underline");
    lay->addWidget(box1);
}

MainWindow::~MainWindow()
{

}
