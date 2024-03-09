//
// Created by Annabel Irani on 2024-03-08.
//

#ifndef BITBUDDY_BITBUDDYSPRITEHANDLER_H
#define BITBUDDY_BITBUDDYSPRITEHANDLER_H


#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QObject>
#include "model/BitBuddyAttribute.h"
#include "model/Event.h"

class BitBuddySpriteHandler :public QObject{
    Q_OBJECT

public:
    explicit BitBuddySpriteHandler(QLabel* displayLabel, QObject* parent = nullptr);

    void changeSprite(const std::string& state);

public slots:
    void handleEvent(const Event& event);
private:
    QLabel* displayLabel;
    QLabel* temporaryLabel;

    void displayTacoAndRemove(const QString &imagePath);

    void changeSpriteSmoothly(const QString &imagePath);

    void displayBubbles(const QString &imagePath);

    void displayZZZ(const QString &imagePath);

    void setDefaultSprite();

    void changeSpriteSmoothly(const QString &imagePath, std::function<void()> callback);

    void displayDrink(const QString &imagePath);
};


#endif //BITBUDDY_BITBUDDYSPRITEHANDLER_H
