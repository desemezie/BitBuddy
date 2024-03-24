//
// Created by Shaylan Pratt on 2024-03-21.
//

#include "component/lightButton.h"
#include <QIcon>
#include <QApplication>

lightButton::lightButton(QWidget *parent) : QPushButton(parent), isLightOn(true) {
  connect(this, &QPushButton::clicked, this, &lightButton::lightClicked);
  setImage(":/assets/light.png");
  update();
}

void lightButton::lightClicked() {
  isLightOn = !isLightOn;
  update();
}

void lightButton::setImage(QString imagePath) {
  QIcon buttonIcon(imagePath);
  this->setIcon(buttonIcon);
  this->setIconSize(buttonIcon.actualSize(QSize(64, 64)));
}

void lightButton::update() {
  if (isLightOn) {
    //qApp->setStyleSheet("");
    emit themeChange("");
    emit textChange(false);
  } else {
    //qApp->setStyleSheet("QWidget { background-color: black; color: white; }");
    emit themeChange(
        "MainWindow { background-image: url(:/assets/black.jpeg); background-repeat: no-repeat; background-position: center; background-size: cover; }");
    emit textChange(true);
  }
}


