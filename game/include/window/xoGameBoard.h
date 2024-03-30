//
// Created by razvan on 30/03/24.
//

#ifndef BITBUDDY_XOGAMEBOARD_H
#define BITBUDDY_XOGAMEBOARD_H

#include <QWidget>

class xoGameBoard : public QWidget
{
  Q_OBJECT

 public:
  xoGameBoard(QWidget *parent = nullptr);
  ~xoGameBoard();

 protected:
  void paintEvent(QPaintEvent *event) override;

 private:
  void drawGrid(QPainter *painter);
};

#endif  // BITBUDDY_XOGAMEBOARD_H
