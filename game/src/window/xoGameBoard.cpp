//
// Created by razvan on 30/03/24.
//
#include "window/xoGameBoard.h"
#include <QPainter>

xoGameBoard::xoGameBoard(QWidget *parent)
    : QWidget(parent)
{
  setFixedSize(300, 300);
}

xoGameBoard::~xoGameBoard()
{
}

void xoGameBoard::paintEvent(QPaintEvent *event)
{
  Q_UNUSED(event);

  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

  // Filling the background with black color
  painter.fillRect(rect(), Qt::black);

  drawGrid(&painter);
}

void xoGameBoard::drawGrid(QPainter *painter)
{
  int cellWidth = width() / 3;
  int cellHeight = height() / 3;

  painter->setPen(Qt::white);

  // Drawing vertical lines
  for (int i = 1; i < 3; ++i)
    painter->drawLine(i * cellWidth, 0, i * cellWidth, height());

  // Drawing horizontal lines
  for (int j = 1; j < 3; ++j)
    painter->drawLine(0, j * cellHeight, width(), j * cellHeight);
}