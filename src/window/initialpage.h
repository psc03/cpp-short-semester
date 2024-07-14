#ifndef INITIALPAGE_H
#define INITIALPAGE_H

#include <QWidget>

class QLabel;
class QPushButton;

class InitialPage : public QWidget {
  Q_OBJECT
 public:
  explicit InitialPage(QWidget *parent = nullptr);
  ~InitialPage();
  void Init();

 signals:
  void switchToAboutPage();
  void switchToGamePage();

 private slots:
  void on_DoublePlay_Button_clicked();
  void on_About_Button_clicked();
  void on_Exit_Button_clicked();

 private:
  QLabel *label;
  QPushButton *DoublePlay_Button;
  QPushButton *About_Button;
  QPushButton *Exit_Button;
  // QLabel *backGround;
};

#endif  // INITIALPAGE_H
