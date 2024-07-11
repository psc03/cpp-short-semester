#ifndef ABOUTPAGE_H
#define ABOUTPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QFrame>

namespace Ui {
class AboutPage;
}

class AboutPage : public QWidget
{
    Q_OBJECT

public:
    explicit AboutPage(QWidget *parent = nullptr);
    ~AboutPage();

private slots:
    void on_pushButton_clicked();

signals:
    void switchToInitialPage();

private:
    QWidget *widget;
    QPushButton *pushButton;
    QLabel *Title;
    QLabel *green_up;
    QLabel *red_right;
    QLabel *green_down;
    QLabel *red_tank;
    QLabel *red_shoot;
    QLabel *red_up;
    QLabel *red_down;
    QLabel *green_tank;
    QLabel *red_left;
    QLabel *green_shoot;
    QLabel *green_right;
    QLabel *green_left;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QFrame *line;
    QLabel *label_5;
    QFrame *line_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *backGround;
};

#endif // ABOUTPAGE_H
