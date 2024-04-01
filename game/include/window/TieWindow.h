//
// Created by razvan on 31/03/24.
//
#ifndef TIEWINDOW_H
#define TIEWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class TieWindow : public QWidget {
  Q_OBJECT

 public:
  explicit TieWindow(QWidget *parent = nullptr);

 private:
  QLabel *titleLabel;
  QPushButton *okButton;
};

#endif // TIEWINDOW_H
