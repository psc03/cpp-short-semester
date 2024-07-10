#include "aboutpage.h"
#include <QPushButton>
#include <QApplication>

AboutPage::AboutPage(QWidget *parent)
    : QWidget{parent},
    backButton(new QPushButton(this))
{
    this->init();
}

AboutPage::~AboutPage()
{
    // delete this;
}

void AboutPage::init()
{
    this->setObjectName("AboutPage");
    this->resize(500, 600);

    backButton->setObjectName("pushButton");
    backButton->setGeometry(QRect(10, 10, 51, 31));
    // 显示文本 返回
    backButton->setText(QCoreApplication::translate("AboutPage", "\350\277\224\345\233\236", nullptr));

    connect(backButton, &QPushButton::clicked, this, &AboutPage::do_backButton_clicked);
}

void AboutPage::do_backButton_clicked()
{
    emit switchToInitialPage();
}
