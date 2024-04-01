//
// Created by razvan on 31/03/24.
//
#include "window/TieWindow.h"

TieWindow::TieWindow(QWidget *parent) : QWidget(parent) {
  setWindowTitle("It's a tie!");

  titleLabel = new QLabel("It's a tie!", this);
  QFont font = titleLabel->font();
  font.setPointSize(24);
  titleLabel->setFont(font);
  titleLabel->setAlignment(Qt::AlignCenter);
  resize(400,400);

  okButton = new QPushButton("OK", this);
  connect(okButton, &QPushButton::clicked, this, &TieWindow::close);

  QVBoxLayout *layout = new QVBoxLayout(this);
  layout->addWidget(titleLabel);
  layout->addWidget(okButton);

  setLayout(layout);
}

