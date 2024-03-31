//
// Created by razvan on 31/03/24.
//

#ifndef BITBUDDY_BOARDWINDOW_H
#define BITBUDDY_BOARDWINDOW_H


//includes
#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>

//class definition
class BoardWindow : public QWidget{
  Q_OBJECT

  //public constructor
 public:
  BoardWindow(QWidget *parent = nullptr);

  //container for the buttons
  QVector<QPushButton *> buttons;

  //method to set a button's text
  void setButtonText(int index, const QString &text);

  //private layout thing
 private:
  QGridLayout *gridLayout;

  //Private slots
 private slots:
  void changeButtonText();

 signals:
  void buttonClicked(int index);
};

#endif  // BITBUDDY_BOARDWINDOW_H
