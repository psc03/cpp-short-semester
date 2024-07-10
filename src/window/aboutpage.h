#ifndef ABOUTPAGE_H
#define ABOUTPAGE_H

#include <QWidget>

class QPushButton;
// class QTextBrowser;

class AboutPage : public QWidget
{
    Q_OBJECT
public:
    explicit AboutPage(QWidget *parent = nullptr);
    ~AboutPage();
    void init();

signals:
    void switchToInitialPage();

private slots:
    void do_backButton_clicked();

private:
    QPushButton *backButton;

};

#endif // ABOUTPAGE_H
