//
// Created by Shaylan Pratt on 2024-03-21.
//

#include "component/LightButton.h"
#include "model/SingleAttributeEvent.h"
#include "model/audio.h"
#include "service/EventDispatcherService.h"
#include "model/BitBuddyAttributeName.h"
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
  if(isLightOn == false){
    SingleAttributeEvent event(1,
                               BitBuddyAttributeName::TIREDNESS,
                               1.0,
                               "Event for: " + BitBuddyAttributeName::toString(BitBuddyAttributeName::TIREDNESS));
    QString Sound = QString::fromStdString(BitBuddyAttributeName::toString(BitBuddyAttributeName::TIREDNESS));
    //std::string myString =  BitBuddyAttributeName::toString(attribute);

    //play sound
    Audio::playSound(Sound);

    EventDispatcherService::getInstance().dispatchEvent(&event);

  }
}

void LightButton::setImage(QString imagePath) {
  QIcon buttonIcon(imagePath);
  this->setIcon(buttonIcon);
  this->setIconSize(buttonIcon.actualSize(QSize(64, 64)));
}

void LightButton::update() {
  if (isLightOn) {
    //qApp->setStyleSheet("");
    emit themeChange("QWidget#centralWidget { background-image: url(:/assets/background.png); }");
    emit textChange(false);
  } else {
    //qApp->setStyleSheet("QWidget { background-color: black; color: white; }");
    emit themeChange(
        "QWidget#centralWidget { background-image: url(:/assets/nightbackground.tiff); }");
    emit textChange(true);
  }
}