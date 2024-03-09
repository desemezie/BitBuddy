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

class BitBuddySpriteHandler :public QObject{
    Q_OBJECT

public:
    explicit BitBuddySpriteHandler(QLabel* displayLabel, QObject* parent = nullptr);

public slots:
    void changeSprite(BitBuddyAttributeName::UniqueName state);

private:
    QLabel* displayLabel;
};


#endif //BITBUDDY_BITBUDDYSPRITEHANDLER_H
