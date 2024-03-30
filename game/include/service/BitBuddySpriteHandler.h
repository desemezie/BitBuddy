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

/**
 * @class BitBuddySpriteHandler
 * @brief The BitBuddySpriteHandler is responsible for the changing sprites of the bitbuddy based on his emotional levels
 */
class BitBuddySpriteHandler :public QObject{
 Q_OBJECT

 public:
  /**
   * @class BitBuddySpriteHandler
   * @brief constructor for Sprite Handler
   * @param displayLabel - takes the base label
   * @param parent - the parent object
   * @param bitBuddy - and the bitbuddy instance
   */
  explicit BitBuddySpriteHandler(QLabel* displayLabel, QObject* parent = nullptr, BitBuddy *bitBuddy = nullptr);


  /**
   * @brief will change the sprite of the bitbuddy
   * @param state - given the state in string form
   */
  void changeSprite(const std::string& state);
  /**
   * @brief function to update the position of the pills once the window is resized
   */
  void updatePillsPosition();
  /**
   * @brief function to update the position of the drink once the window is resized
   */
  void updateDrinkPosition();
  /**
   * @brief function to update the position of the taco once the window is resized
   */
  void updateTacoPosition();
  /**
   * @brief function to update the position of the bubbles once the window is resized
   */
  void updateBubblePosition();
  /**
   * @brief function to update the position of the zzz's once the window is resized
   */
  void updateZZZPosition();

 public slots:
  /**
   * handleEvent will take the events that are sent out by the Event dispatcher and in return change the sprite accordingly
   * @param event
   */
  void handleEvent(const Event& event);
 private:
  QLabel* displayLabel;
  QLabel* temporaryLabel;
  BitBuddy * bitBuddy;
  QList<QLabel*> bubbleLabels;

  /**
   * Methods to display temporary objects.
   * Each method will display the item in a position dynamically according to screen size.
   *
   */
  void displayTacoAndRemove(const QString &imagePath);

  void changeSpriteSmoothly(const QString &imagePath);

  void displayBubbles(const QString &imagePath);

  void displayZZZ(const QString &imagePath);

  void setDefaultSprite();

  /**
   * changeSpriteSmoothly will take the given imagePath and change the sprite
   * @param imagePath - url path to image
   * @param callback
   */
  void changeSpriteSmoothly(const QString &imagePath, std::function<void()> callback);


  /**
   * Methods to display temporary objects.
   * Each method will display the item in a position dynamically according to screen size.
   *
   */
  void displayDrink(const QString &imagePath);

  void displayPills(const QString &imagePath);


  void checkAndUpdateSprite();

  void postUpdateCheck();

  void spriteOrganizer();

  /**
   *
   * @param event
   */
  void spriteOrganizer(const Event &event);

  /**
   * Function responsible for maintaining the correct sprites after event occurs
   * @return BitBuddyAttributeName for the current attribute set off
   */
  BitBuddyAttributeName checkLevels();
};


#endif //BITBUDDY_BITBUDDYSPRITEHANDLER_H