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
#include "model/SingleAttributeEvent.h"
#include "model/BitBuddy.h"

class BitBuddySpriteHandler :public QObject{
 Q_OBJECT

 public:
  explicit BitBuddySpriteHandler(QLabel* displayLabel, QObject* parent = nullptr, BitBuddy *bitBuddy = nullptr);


  void changeSprite(const std::string& state);
  void updatePillsPosition();
  void updateDrinkPosition();
  void updateTacoPosition();
  void updateBubblePosition();
  void updateZZZPosition();

 public slots:
  void handleEvent(const Event& event);
 private:
  QLabel* displayLabel;
  QLabel* temporaryLabel;
  BitBuddy * bitBuddy;
  QList<QLabel*> bubbleLabels;
  QRect bubbleSquare;

  void displayTacoAndRemove(const QString &imagePath);

  void changeSpriteSmoothly(const QString &imagePath);

  void displayBubbles(const QString &imagePath);

  void displayZZZ(const QString &imagePath);

  void setDefaultSprite();

  void changeSpriteSmoothly(const QString &imagePath, std::function<void()> callback);

  void displayDrink(const QString &imagePath);

  void displayPills(const QString &imagePath);

  void checkAndUpdateSprite();

  void postUpdateCheck();

  void spriteOrganizer();
  void spriteOrganizer(const Event &event);

  BitBuddyAttributeName checkLevels();
};


#endif //BITBUDDY_BITBUDDYSPRITEHANDLER_H