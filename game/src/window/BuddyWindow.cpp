//
// Created by razvan on 31/03/24.
//
#include "window/BuddyWindow.h"


BuddyWindow::BuddyWindow(QWidget *parent) : QWidget(parent) {
  setWindowTitle("BitBuddy wins!");

  titleLabel = new QLabel("Bitbuddy has won!", this);
  QFont font = titleLabel->font();
  font.setPointSize(24);
  titleLabel->setFont(font);
  titleLabel->setAlignment(Qt::AlignCenter);
  resize(400,400);

  okButton = new QPushButton("OK", this);
  connect(okButton, &QPushButton::clicked, this, &BuddyWindow::close);

  QVBoxLayout *layout = new QVBoxLayout(this);
  layout->addWidget(titleLabel);
  layout->addWidget(okButton);

  setLayout(layout);
}
