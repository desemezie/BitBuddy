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

    if (state.find("stomach rumbles loudly") != std::string::npos) {
        qDebug() << "Found and identified for hungry";
        imageName = "/Users/annabelirani/Desktop/3307repo/group17/assets/sad_bitbuddy.png";
    } else if (state.find("seems a bit withdrawn") != std::string::npos) {
        qDebug() << "Found and identified for withdrawn";
        imageName = "/Users/annabelirani/Desktop/3307repo/group17/assets/sad_bitbuddy.png";
    } else if (state.find("desperately thirsty") != std::string::npos) {
        qDebug() << "Found and identified for thirsty";
        imageName = "/Users/annabelirani/Desktop/3307repo/group17/assets/sad_bitbuddy.png";
    } else if (state.find("doesn't seem to be feeling well") != std::string::npos) {
        qDebug() << "Found and identified for sick";
        imageName = "/Users/annabelirani/Desktop/3307repo/group17/assets/sad_bitbuddy.png";
    } else if (state.find("eyelids are drooping") != std::string::npos) {
        qDebug() << "Found and identified for tired";
        imageName = "/Users/annabelirani/Desktop/3307repo/group17/assets/sad_bitbuddy.png";
    } else if (state.find("lets out a big yawn") != std::string::npos) {
        qDebug() << "Found and identified for bored";
        imageName = "/Users/annabelirani/Desktop/3307repo/group17/assets/sad_bitbuddy.png";
    } else if (state.find("could use a bath") != std::string::npos) {
        qDebug() << "Found and identified for bath";

        imageName = "/Users/annabelirani/Desktop/3307repo/group17/assets/angry_bitbuddy.png";
    }

    QPixmap pixmap(imageName);
    if (!pixmap.isNull()) {
        // Note: Fixed the syntax for scaling the pixmap before setting it
        displayLabel->setPixmap(pixmap.scaled(displayLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        qDebug() << "Failed to load sprite for state:" << QString::fromStdString(state);
    }
}
void BitBuddySpriteHandler::handleEvent(const Event &event) {

    std::string state = event.getDescription();
    qDebug() << "Recieved event desc: " << QString::fromStdString(state);
    changeSprite(state);
}
