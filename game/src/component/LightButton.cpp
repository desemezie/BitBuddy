//
// Created by Shaylan Pratt on 2024-03-21.
//

#include "component/LightButton.h"
#include <QIcon>
#include <QApplication>

LightButton::LightButton(QWidget *parent) : QPushButton(parent), isLightOn(true) {
  connect(this, &QPushButton::clicked, this, &LightButton::lightClicked);
  setImage(":/assets/switch.png");
  update();
}

void LightButton::lightClicked() {
  isLightOn = !isLightOn;
  update();
}

void LightButton::setImage(QString imagePath) {
  QIcon buttonIcon(imagePath);
  this->setIcon(buttonIcon);
  this->setIconSize(buttonIcon.actualSize(QSize(64, 64)));
}

void LightButton::update() {
  if (isLightOn) {
    //qApp->setStyleSheet("");
    emit themeChange("");
    emit textChange(false);
  } else {
    //qApp->setStyleSheet("QWidget { background-color: black; color: white; }");
    emit themeChange(
        "MainWindow { background-image: url(:/assets/blackbackground.jpeg); background-repeat: no-repeat; background-position: center; background-size: cover; }");
    emit textChange(true);
  }
}