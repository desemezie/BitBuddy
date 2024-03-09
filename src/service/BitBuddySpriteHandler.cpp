//
// Created by Annabel Irani on 2024-03-08.
//
#include "service/BitBuddySpriteHandler.h"
#include <QDebug>
#include <QPixmap>

// Constructor
BitBuddySpriteHandler::BitBuddySpriteHandler(QLabel *displayLabel, QObject *parent)
        : QObject(parent), displayLabel(displayLabel) {
}

// Correctly place the changeSprite method within the BitBuddySpriteHandler class
void BitBuddySpriteHandler::changeSprite(const std::string& state) {
    QString imageName;

    if (state == "Happiness") {
        imageName = ":/assets/happy_bitbuddy.png";
    } else if (state == "Tiredness") {
        imageName = ":/assets/sad_bitbuddy.png";
    } else {
        imageName = ":/assets/happy_bitbuddy.png"; // Default or unknown state
    }

    QPixmap pixmap(imageName);
    if (!pixmap.isNull()) {
        // Note: Fixed the syntax for scaling the pixmap before setting it
        displayLabel->setPixmap(pixmap.scaled(displayLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        qDebug() << "Failed to load sprite for state:" << QString::fromStdString(state);
    }
}
