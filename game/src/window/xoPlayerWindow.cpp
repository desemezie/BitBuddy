//
// Created by razvan on 30/03/24.
//
#include "window/xoPlayerWindow.h"

xoPlayerWindow::xoPlayerWindow(QWidget *parent) : QWidget(parent) {
  setupUi();
  setupConnections();
}

void xoPlayerWindow::setupUi() {
  // Main window
  setWindowTitle("Choose Player");
  setStyleSheet("background-color: black;");

  // The "Choose Player" text
  label = new QLabel("Choose Player", this);
  QFont font = label->font();
  font.setPointSize(24);
  label->setFont(font);
  label->setStyleSheet("color: white;");
  label->setAlignment(Qt::AlignHCenter);

  // X button
  btnX = new QPushButton("X", this);
  //X button styling
  QFont xFont("Arial", 24, QFont::Bold);
  btnX->setFont(xFont);
  btnX->setStyleSheet("color: white;");

  // O button
  btnO = new QPushButton("O", this);

  //O button styling
  QFont oFont("Arial", 24, QFont::Bold);
  btnO->setFont(oFont);
  btnO->setStyleSheet("color: white;");

  // Create layouts
  QVBoxLayout *mainLayout = new QVBoxLayout(this);
  QHBoxLayout *buttonLayout = new QHBoxLayout;

  // Add all widgets to layouts
  mainLayout->addWidget(label);
  mainLayout->addLayout(buttonLayout);
  buttonLayout->addWidget(btnX);
  buttonLayout->addWidget(btnO);

  // Stretch centers the buttons in the middle
  mainLayout->addStretch();
  buttonLayout->setAlignment(Qt::AlignCenter);
  mainLayout->addStretch();

  // Set layout to the main window
  setLayout(mainLayout);
}

void xoPlayerWindow::setupConnections() {
  // Connect button signals to slots here if needed
}