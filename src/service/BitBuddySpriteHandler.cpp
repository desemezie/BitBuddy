//
// Created by Annabel Irani on 2024-03-08.
//

#include "service/BitBuddySpriteHandler.h"
#include <QPixmap>

BitBuddySpriteHandler::BitBuddySpriteHandler(QLabel *displayLabel, QObject *parent)
    : QObject(parent), displayLabel(displayLabel) {}


void BitBuddySpriteHandler::changeSprite(BitBuddyAttributeName::UniqueName state) {
    QString imageName;
    switch (state){
        case BitBuddyAttributeName::HAPPINESS:
            imageName = "happy_bitbuddy.png";
            break;
        case BitBuddyAttributeName::HEALTH:
            imageName = "sick_bitbuddy.png";
            break;
        case BitBuddyAttributeName::TIREDNESS:
            imageName = "sad_bitbuddy.png";
            break;
        case BitBuddyAttributeName::BOREDOM:
            imageName = "sad_bitbuddy.png";
            break;
        case BitBuddyAttributeName::THIRST:
            imageName = "sad_bitbuddy.png";
            break;
        case BitBuddyAttributeName::HUNGER:
            imageName = "sad_bitbuddy.png";
            break;
        case BitBuddyAttributeName::HYGIENE:
            imageName = "angry_bitbuddy.png";
            break;
        default:
            imageName = "happy_bitbuddy.png";
    }
}
