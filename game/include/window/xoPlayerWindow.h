//
// Created by razvan on 30/03/24.
//

#ifndef BITBUDDY_XOPLAYERWINDOW_H
#define BITBUDDY_XOPLAYERWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class xoPlayerWindow : public QWidget {
  Q_OBJECT

 public:
  explicit xoPlayerWindow(QWidget *parent = nullptr);

 private:
  QLabel *label;
  QPushButton *btnX;
  QPushButton *btnO;

  void setupUi();
  void setupConnections();
};

#endif  // BITBUDDY_XOPLAYERWINDOW_H
