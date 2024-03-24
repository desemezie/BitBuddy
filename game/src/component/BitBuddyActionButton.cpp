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


void  BitBuddyActionButton::setButtonStyle(){
    QString imageName = QString::fromStdString(BitBuddyAttributeName::toString(attribute));
    setStyleSheet(
            "QPushButton {\n"
            "    color: #000000;\n"
            "    border: 2px solid #000000;\n"
            "    border-radius: 15px; /* Increase for chubbier corners */\n"
            "    background-color: white;\n"
            "    padding: 10px 20px; /* Increase padding for a chubbier look */\n"
            "    font-size: 25px;\n"
            "    text-align: center;\n"
            "    icon-size: 60px; /* Size for the icons */\n"
            "    min-width: 100px; /* Minimum width to accommodate text and icon */\n"
            "    min-height: 40px; /* Minimum height for a chubbier look */\n"

            "}\n"
            "\n"
            "QPushButton:hover {\n"
            "    background-color: #000000;\n"
            "    color: white;\n"
            "}"

    );

    if (imageName == "Hunger") {
        setIcon(QIcon(":/assets/tamagochi_feed.png"));
        setIconSize(QSize(50, 50));
    }
    else if (imageName == "Happiness"){
        setIcon(QIcon(":/assets/happy_bitbuddy.png"));
        setIconSize(QSize(50, 50));
    }
    else if (imageName == "Thirst"){
        setIcon(QIcon(":/assets/tamagochi_drink_2.png"));
        setIconSize(QSize(50, 50));
    }
    else if (imageName == "Health"){
        setIcon(QIcon(":/assets/tamagochi_health.png"));
        setIconSize(QSize(50, 50));
    }
    else if (imageName == "Tiredness"){
        setIcon(QIcon(":/assets/sleeping_bitbuddy.png"));
        setIconSize(QSize(50, 50));
    }
    else if (imageName == "Boredom"){
        setIcon(QIcon(":/assets/tamagochi_dead.png"));
        setIconSize(QSize(50, 50));
    }
    else {//Hygiene
        //Q_ASSERT(type == "snore.mp3");
        setIcon(QIcon(":/assets/tamagochi_soap_final.png"));
        setIconSize(QSize(50, 50));
    }


}




