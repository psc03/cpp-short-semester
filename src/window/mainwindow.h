#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QCheckBox>
#include <QHBoxLayout>


class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
// signals:

private:
    QHBoxLayout *lay;
    QPixmap *tank;
    QCheckBox *box1;
};

#endif // MAINWINDOW_H
