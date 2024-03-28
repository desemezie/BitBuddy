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

const QString ATTRIBUTE_FONT = ":/assets/fonts/GAMES.TTF";

/**
 * @class BitBuddyActionButton
 * @brief Will initialize the button by connecting the button click to the handleButtonClicked method
 * @param icon Icon for the button
 * @param attribute Attribute that the button belongs to
 * @param text The string for the button
 * @param parent The parent widget of the button
 */
BitBuddyActionButton::BitBuddyActionButton(const QIcon &icon,
                                           const QString &text,
                                           BitBuddyAttributeName::UniqueName attribute,
                                           QWidget *parent)
    : QPushButton(icon, text, parent), attribute(attribute) {
  connect(this, &QPushButton::clicked, this, &BitBuddyActionButton::handleButtonClicked);

}

/**
 * @class BitBuddyActionButton
 * @brief Will handle the button click depending on which button it is and its Attribute
 *
 */
void BitBuddyActionButton::handleButtonClicked() {
  // Creates a single attribute event for each of the buttons
  SingleAttributeEvent event(1,
                             attribute,
                             1.0,
                             "Event for: " + BitBuddyAttributeName::toString(attribute));
  // Adds the sound for each button
  QString Sound = QString::fromStdString(BitBuddyAttributeName::toString(attribute));


  // Play sound
  Audio::playSound(Sound);

  // Dispatches event
  EventDispatcherService::getInstance().dispatchEvent(&event);
}

/**
 * @brief setButtonStyle is supposed to set the design of the button.
 */
void  BitBuddyActionButton::setButtonStyle(){

    // set font style
    int id = QFontDatabase::addApplicationFont(ATTRIBUTE_FONT);
    QStringList fontFamilies = QFontDatabase::applicationFontFamilies(id);
    const QString fontFamily = fontFamilies.at(0);

    QString imageName = QString::fromStdString(BitBuddyAttributeName::toString(attribute));

    // String used in the format of the design expectations to send into stylesheet
    QString buttonStyleSheet = QString(
        "QPushButton {\n"
        "    color: #000000;\n"
        "    border: 2px solid #000000;\n"
        "    border-radius: 15px; /* Increase for chubbier corners */\n"
        "    background-color: white;\n"
        "    padding: 10px 20px; /* Increase padding for a chubbier look */\n"
        "    font-size: 25px;\n"
        "    font-family: '%1';\n" // Add the font family here
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
    ).arg(fontFamily); // Replace %1 with the fontFamily variable

    // Apply the constructed style sheet to the widget
    setStyleSheet(buttonStyleSheet);



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




