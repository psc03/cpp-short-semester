#include "aboutpage.h"
#include <QDebug>
AboutPage::AboutPage(QWidget *parent) : QWidget(parent) {
    this->setGeometry(0, 0, 500, 600);
    this->setWindowTitle("Form");
    this->setAutoFillBackground(true);

    pushButton = new QPushButton("返回", this);
    pushButton->setGeometry(10, 10, 51, 31);
    pushButton->setStyleSheet("font: 9pt '阿里巴巴普惠体 H'; background-color: rgb(194, 183, 165);");
    connect(pushButton,&QPushButton::clicked,this,&AboutPage::on_pushButton_clicked);

    widget = new QWidget(this);
    widget->setObjectName("widget");
    widget->setGeometry(QRect(21, 105, 451, 181));
    widget->setStyleSheet(QString::fromUtf8("color: rgb(146, 1, 1);"));

    Title = new QLabel("关于", this);
    Title->setGeometry(210, 13, 80, 53);
    QFont titleFont("霞鹜文楷", 30, QFont::Bold);
    Title->setFont(titleFont);
    Title->setStyleSheet("color: rgb(90, 83, 74);");

    green_up = new QLabel(widget);
    green_up->setGeometry(210, 100, 31, 31);
    green_up->setPixmap(QPixmap(":/pic/pictures/key/w.png"));
    green_up->setScaledContents(true);

    red_right = new QLabel(widget);
    red_right->setGeometry(240, 40, 31, 31);
    red_right->setPixmap(QPixmap(":/pic/pictures/key/right.png"));
    red_right->setScaledContents(true);

    green_down = new QLabel(widget);
    green_down->setGeometry(210, 130, 31, 31);
    green_down->setPixmap(QPixmap(":/pic/pictures/key/s.png"));
    green_down->setScaledContents(true);

    red_tank = new QLabel(widget);
    red_tank->setGeometry(24, 108, 91, 61);
    red_tank->setPixmap(QPixmap(":/pic/pictures/Tank_Red_Big.png"));
    red_tank->setScaledContents(true);

    red_shoot = new QLabel(widget);
    red_shoot->setGeometry(340, 130, 91, 31);
    red_shoot->setPixmap(QPixmap(":/pic/pictures/key/space.png"));
    red_shoot->setScaledContents(true);

    red_up = new QLabel(widget);
    red_up->setGeometry(210, 10, 31, 31);
    red_up->setPixmap(QPixmap(":/pic/pictures/key/up.png"));
    red_up->setScaledContents(true);

    red_down = new QLabel(widget);
    red_down->setGeometry(210, 40, 31, 31);
    red_down->setPixmap(QPixmap(":/pic/pictures/key/down.png"));
    red_down->setScaledContents(true);

    green_tank = new QLabel(widget);
    green_tank->setGeometry(24, 20, 91, 61);
    green_tank->setPixmap(QPixmap(":/pic/pictures/Tank_Green_Big.png"));
    green_tank->setScaledContents(true);

    red_left = new QLabel(widget);
    red_left->setGeometry(180, 40, 31, 31);
    red_left->setPixmap(QPixmap(":/pic/pictures/key/left.png"));
    red_left->setScaledContents(true);

    green_shoot = new QLabel(widget);
    green_shoot->setGeometry(340, 39, 31, 31);
    green_shoot->setPixmap(QPixmap(":/pic/pictures/key/m.png"));
    green_shoot->setScaledContents(true);

    green_right = new QLabel(widget);
    green_right->setGeometry(240, 130, 31, 31);
    green_right->setPixmap(QPixmap(":/pic/pictures/key/d.png"));
    green_right->setScaledContents(true);

    green_left = new QLabel(widget);
    green_left->setGeometry(180, 130, 31, 31);
    green_left->setPixmap(QPixmap(":/pic/pictures/key/a.png"));
    green_left->setScaledContents(true);

    label = new QLabel("移动", widget);
    label->setGeometry(120, 40, 41, 21);
    QFont labelFont("霞鹜文楷", 16);
    label->setFont(labelFont);
    label->setStyleSheet("color: rgb(146, 1, 1);");

    label_2 = new QLabel("移动", widget);
    label_2->setGeometry(120, 130, 41, 21);
    label_2->setFont(labelFont);
    label_2->setStyleSheet("color: rgb(1, 76, 1);");

    label_3 = new QLabel("射击", widget);
    label_3->setGeometry(290, 40, 41, 21);
    label_3->setFont(labelFont);
    label_3->setStyleSheet("color: rgb(146, 1, 1);");

    label_4 = new QLabel("射击", widget);
    label_4->setGeometry(290, 132, 41, 21);
    label_4->setFont(labelFont);
    label_4->setStyleSheet("color: rgb(1, 76, 1);");

    line = new QFrame(this);
    line->setGeometry(10, 65, 20, 41);
    line->setFrameShadow(QFrame::Plain);
    line->setLineWidth(2);
    line->setFrameShape(QFrame::VLine);

    label_5 = new QLabel("游戏玩法", this);
    label_5->setGeometry(29, 63, 81, 41);
    QFont label5Font("阿里巴巴普惠体 B", 15);
    label_5->setFont(label5Font);

    line_2 = new QFrame(this);
    line_2->setGeometry(10, 329, 20, 41);
    line_2->setFrameShadow(QFrame::Plain);
    line_2->setLineWidth(2);
    line_2->setFrameShape(QFrame::VLine);

    label_6 = new QLabel("开发说明", this);
    label_6->setGeometry(29, 327, 81, 41);
    label_6->setFont(label5Font);

    label_7 = new QLabel("在游戏过程中，可以按下 “Esc” 键退出当前游戏", this);
    label_7->setGeometry(20, 280, 371, 31);
    QFont label7Font("霞鹜文楷", 12);
    label_7->setFont(label7Font);

    label_8 = new QLabel("本游戏为浙江大学 2023 - 2024 《C++项目管理及工程实践》\n“坦克动荡”小组课程项目。\n本项目复刻了4399上的 坦克动荡 游戏", this);
    label_8->setGeometry(20, 374, 461, 161);
    label_8->setFont(label7Font);
    label_8->setAlignment(Qt::AlignLeading | Qt::AlignLeft | Qt::AlignTop);

    backGround = new QLabel(this);
    backGround->setGeometry(0, 0, 500, 600);
    backGround->setPixmap(QPixmap(":/pic/pictures/aboutBackground.png"));
    backGround->setScaledContents(true);

    backGround->lower();

    // connect

}

AboutPage::~AboutPage()
{

}

void AboutPage::on_pushButton_clicked()
{
    qDebug() << "on_pushButton";
    emit AboutPage::switchToInitialPage();
}
