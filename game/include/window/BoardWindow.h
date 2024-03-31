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

  //private layout thing
 private:
  QGridLayout *gridLayout;

  //Private slots
 private slots:
  void changeButtonText();
};

#endif  // BITBUDDY_BOARDWINDOW_H
