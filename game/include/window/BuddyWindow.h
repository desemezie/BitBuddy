//
// Created by razvan on 31/03/24.
//

#ifndef BUDDYWINDOW_H
#define BUDDYWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class BuddyWindow : public QWidget {
  Q_OBJECT

 public:
  explicit BuddyWindow(QWidget *parent = nullptr);

 private:
  QLabel *titleLabel;
  QPushButton *okButton;
};

#endif // BUDDYWINDOW_H
