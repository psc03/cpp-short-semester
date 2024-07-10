#include "initialpage.h"
#include <QLabel>
#include <QPushButton>
#include <QApplication>

InitialPage::InitialPage(QWidget *parent)
    : QWidget{parent},
    label(new QLabel(this)),
    DoublePlay_Button(new QPushButton(this)),
    About_Button(new QPushButton(this)),
    Exit_Button(new QPushButton(this))
{
    this->Init();
}

InitialPage::~InitialPage()
{
    // delete this;
}

void InitialPage::Init()
{
    this->setObjectName("InitialPage");
    this->setStyleSheet("background-color: white;");
    this->setWindowModality(Qt::NonModal);
    this->setEnabled(true);
    this->resize(500, 600);
    this->setFocusPolicy(Qt::ClickFocus);
    this->setAutoFillBackground(true);

    label->setObjectName("label");
    label->setGeometry(QRect(-18, 53, 551, 351));
    // QPixmap initpic;
    // initpic.load(":/pic/pictures/Initial.png");
    label->setPixmap(QPixmap(":/pic/pictures/Initial.png"));
    label->setScaledContents(true);

    DoublePlay_Button->setObjectName("DoublePlay_Button");
    DoublePlay_Button->setGeometry(QRect(170, 330, 141, 51));
    // 显示文本 双人模式
    DoublePlay_Button->setText(QCoreApplication::translate("InitialPage", "\345\217\214\344\272\272\346\250\241\345\274\217", nullptr));

    About_Button->setObjectName("About_Button");
    About_Button->setGeometry(QRect(170, 400, 141, 51));
    // 显示文本 双人模式
    About_Button->setText(QCoreApplication::translate("InitialPage", "\345\205\263\344\272\216", nullptr));

    Exit_Button->setObjectName("Exit_Button");
    Exit_Button->setGeometry(QRect(170, 470, 141, 51));
    // 显示文本 双人模式
    Exit_Button->setText(QCoreApplication::translate("InitialPage", "\351\200\200\345\207\272\346\270\270\346\210\217", nullptr));

    QMetaObject::connectSlotsByName(this);
}

void InitialPage::on_DoublePlay_Button_clicked()
{
    emit switchToGamePage();
}

void InitialPage::on_About_Button_clicked()
{
    emit switchToAboutPage();
}

void InitialPage::on_Exit_Button_clicked()
{
    QApplication::quit();
    // 等价于exit(0)
}
