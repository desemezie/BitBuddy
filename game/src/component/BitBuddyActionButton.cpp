//
// Created by Annabel Irani on 2024-03-04.
//
#include <QPushButton>
#include <QVBoxLayout>
#include "service/EventDispatcherService.h"
#include "model/BitBuddyAttributeName.h"
#include "model/BitBuddyEvents.h"
#include "component/BitBuddyActionButton.h"
#include "QtMultimedia"
#include "model/audio.h"

BitBuddyActionButton::BitBuddyActionButton(const QIcon &icon,
                                           const QString &text,
                                           BitBuddyAttributeName::UniqueName attribute,
                                           QWidget *parent)
    : QPushButton(icon, text, parent), attribute(attribute) {
  connect(this, &QPushButton::clicked, this, &BitBuddyActionButton::handleButtonClicked);

}

void BitBuddyActionButton::handleButtonClicked() {
  SingleAttributeEvent event(1,
                             attribute,
                             1.0,
                             "Event for: " + BitBuddyAttributeName::toString(attribute));
  QString Sound = QString::fromStdString(BitBuddyAttributeName::toString(attribute));
  //std::string myString =  BitBuddyAttributeName::toString(attribute);

  //play sound
  Audio::playSound(Sound);







  EventDispatcherService::getInstance().dispatchEvent(&event);
}





