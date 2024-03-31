//
// Created by Annabel Irani on 2024-03-08.
//
#include "service/BitBuddySpriteHandler.h"
#include "model/SingleAttributeEvent.h"
#include "window/LauncherWindow.h"
#include <QDebug>
#include <QPixmap>
#include <QTimer>
#include <QAbstractAnimation>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <iostream>

// Constructor
BitBuddySpriteHandler::BitBuddySpriteHandler(QLabel *displayLabel, QObject *parent, BitBuddy *bitBuddy)
    : QObject(parent), displayLabel(displayLabel), bitBuddy(bitBuddy){
  temporaryLabel = new QLabel(displayLabel->parentWidget());
  temporaryLabel->setAttribute(Qt::WA_TransparentForMouseEvents);
  temporaryLabel->hide();

}


// Event handler for event dispatch
void BitBuddySpriteHandler::handleEvent(const Event &event) {
  // Casts as a SingleAttributeEvent
  auto specificEvent = dynamic_cast<const SingleAttributeEvent*>(&event);

  // Checks if it is a bitbuddy feeling or user action
  if (specificEvent->getIncrement() < 0) {
    BitBuddyAttributeName::UniqueName attributeName = specificEvent->getAttribute();
    // Gets the value of the current attribute
    int value = bitBuddy->getAttributeValue(attributeName);
    qDebug() << "Attribute: " << QString::fromStdString(BitBuddyAttributeName::toString(attributeName)) << " With Value: " << value;
    qDebug() << "URL: " << QString::fromStdString(BitBuddyAttributeName::imageURL(attributeName));
    qDebug() << "Value to change at: " << BitBuddyAttributeName::valueWhereChange(attributeName);
    // Changes the sprite based on the URL and the attribute
    if (value < BitBuddyAttributeName::valueWhereChange(attributeName)) {
      changeSpriteSmoothly(QString::fromStdString(BitBuddyAttributeName::imageURL(attributeName)));
    }


  } else {
    spriteOrganizer(event);
    qDebug() << "Clicked a Button";

  }


}

void BitBuddySpriteHandler::spriteOrganizer(const Event &event){

  auto specificEvent = dynamic_cast<const SingleAttributeEvent*>(&event);
  auto attributeName = specificEvent->getAttribute();

  if (specificEvent->getAttribute() == BitBuddyAttributeName::HUNGER){
    displayTacoAndRemove(":/assets/tamagochi_feed.png");

    int value = bitBuddy->getAttributeValue(BitBuddyAttributeName::HUNGER);
    if (value < BitBuddyAttributeName::valueWhereChange(BitBuddyAttributeName::HUNGER)) {
      changeSpriteSmoothly(QString::fromStdString(BitBuddyAttributeName::imageURL(attributeName)));
    }
    else {
      changeSpriteSmoothly(":/assets/happy_bitbuddy.png");
    }

  }

  if (specificEvent->getAttribute() == BitBuddyAttributeName::THIRST){

    changeSpriteSmoothly(":/assets/happy_bitbuddy.png");
    displayDrink(":/assets/tamagochi_drink_2.png");

    int value = bitBuddy->getAttributeValue(BitBuddyAttributeName::THIRST);
    if (value < BitBuddyAttributeName::valueWhereChange(BitBuddyAttributeName::THIRST)) {
      changeSpriteSmoothly(QString::fromStdString(BitBuddyAttributeName::imageURL(attributeName)));
    }
    else {
      changeSpriteSmoothly(":/assets/happy_bitbuddy.png");
    }

  }

  if (specificEvent->getAttribute() == BitBuddyAttributeName::TIREDNESS) {

    changeSpriteSmoothly(":/assets/sleeping_bitbuddy.png");
    displayZZZ(":/assets/tamagochi_zzz.png");
    QTimer::singleShot(5000, this, [this]() {
      QString defaultImagePath = ":/assets/happy_bitbuddy.png"; // Path to your default sprite
      changeSpriteSmoothly(defaultImagePath);
    });

    int value = bitBuddy->getAttributeValue(BitBuddyAttributeName::TIREDNESS);
    if (value < BitBuddyAttributeName::valueWhereChange(BitBuddyAttributeName::TIREDNESS)) {
      changeSpriteSmoothly(QString::fromStdString(BitBuddyAttributeName::imageURL(attributeName)));
    }

  }

  if (specificEvent->getAttribute() == BitBuddyAttributeName::HYGIENE) {
    displayBubbles(":/assets/tamagochi_bubble.png");
    int value = bitBuddy->getAttributeValue(BitBuddyAttributeName::HYGIENE);
    if (value < BitBuddyAttributeName::valueWhereChange(BitBuddyAttributeName::HYGIENE)) {
      changeSpriteSmoothly(QString::fromStdString(BitBuddyAttributeName::imageURL(attributeName)));
    }
  }

  if (specificEvent->getAttribute() == BitBuddyAttributeName::HEALTH) {
    displayPills(":/assets/tamagochi_pills.png");
    int value = bitBuddy->getAttributeValue(BitBuddyAttributeName::HEALTH);
    if (value < BitBuddyAttributeName::valueWhereChange(BitBuddyAttributeName::HEALTH)) {
      changeSpriteSmoothly(QString::fromStdString(BitBuddyAttributeName::imageURL(attributeName)));
    }
  }
  if (specificEvent->getAttribute() == BitBuddyAttributeName::HAPPINESS) {
    displayDessert(":/assets/lollipop.png");
    int value = bitBuddy->getAttributeValue(BitBuddyAttributeName::HAPPINESS);
    if (value < BitBuddyAttributeName::valueWhereChange(BitBuddyAttributeName::HAPPINESS)) {
      changeSpriteSmoothly(QString::fromStdString(BitBuddyAttributeName::imageURL(attributeName)));
    }
  }

}

void BitBuddySpriteHandler::displayPills(const QString &imagePath) {
  qDebug() << "load image for pill event.";
  QPixmap pixmap(imagePath);
  if (!pixmap.isNull()) {
    QSize newSize(50, 50); // Size of the pills image

    // Set the pixmap with the new size
    temporaryLabel->setPixmap(pixmap.scaled(newSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    temporaryLabel->resize(newSize);

    updatePillsPosition();

    temporaryLabel->show();
    // Use QTimer to wait 5 seconds before removing the image
    QTimer::singleShot(3000, this, [this]() {
      temporaryLabel->clear(); // Removes the pixmap from the label
      checkLevels();
    });
  } else {
    qDebug() << "Failed to load image";
  }
}


void BitBuddySpriteHandler::displayTacoAndRemove(const QString &imagePath) {
  QPixmap pixmap(imagePath);
  checkLevels();

  if (!pixmap.isNull()) {
    QSize newSize(200, 200);

    temporaryLabel->setPixmap(pixmap.scaled(newSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    temporaryLabel->resize(newSize);
    updateTacoPosition();
    temporaryLabel->show();
    // Use QTimer to wait 5 seconds before removing the image
    QTimer::singleShot(3000, this, [this]() {
      temporaryLabel->clear(); // Removes the pixmap from the label
      checkLevels();
    });
  } else {
    qDebug() << "Failed to load image for taco event.";
  }
}
void BitBuddySpriteHandler::displayDrink(const QString &imagePath) {
  qDebug() << "Trying to load image from:" << imagePath;
  QPixmap pixmap(imagePath);
  if (!pixmap.isNull()) {
    QSize newSize(250, 250);
    //temporaryLabel->setStyleSheet("background-color: red;");
    temporaryLabel->setPixmap(pixmap.scaled(newSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    temporaryLabel->resize(newSize);
    updateDrinkPosition();
    temporaryLabel->show();
    // Use QTimer to wait 5 seconds before removing the image
    QTimer::singleShot(5000, this, [this]() {
      temporaryLabel->clear(); // Removes the pixmap from the label
      checkLevels();
    });
  } else {
    qDebug() << "Failed to load image for taco event.";
  }
}

void BitBuddySpriteHandler::displayZZZ(const QString &imagePath) {
  QPixmap pixmap(imagePath);
  if (!pixmap.isNull()) {
    QSize newSize(200, 200);

    temporaryLabel->setPixmap(pixmap.scaled(newSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    temporaryLabel->resize(newSize);
    updateZZZPosition();
    temporaryLabel->show();
    // Use QTimer to wait 5 seconds before removing the image
    QTimer::singleShot(5000, this, [this]() {
      temporaryLabel->clear(); // Removes the pixmap from the label
      checkLevels();
    });

  } else {
    qDebug() << "Failed to load image for taco event.";
  }
}

void BitBuddySpriteHandler::displayBubbles(const QString &imagePath) {
  const int numberOfBubbles = 30; // Adjust the number of bubbles as needed

  QSize bubbleSize(50, 50); // Adjust the size of each bubble as needed

  for (int i = 0; i < numberOfBubbles; ++i) {
    QLabel *bubbleLabel = new QLabel(displayLabel->parentWidget());
    QPixmap pixmap(imagePath);
    bubbleLabel->setPixmap(pixmap.scaled(bubbleSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    bubbleLabel->resize(bubbleSize);
    // Random position for each bubble

    int x = rand() % (displayLabel->width() - bubbleSize.width()) + 470;
    int y = rand() % (displayLabel->height() - bubbleSize.height()) + 150;
    bubbleLabels.append(bubbleLabel);
    bubbleLabel->move(x, y);
    bubbleLabel->setAttribute(Qt::WA_TranslucentBackground);

    bubbleLabel->show();

    // Set each bubble to clear after 3 seconds
    QTimer::singleShot(3000, bubbleLabel, [bubbleLabel, this]() {
      bubbleLabel->deleteLater(); // Ensure the label is properly deleted
      bubbleLabels.removeAll(bubbleLabel);
      checkLevels();
    });
  }
}

void BitBuddySpriteHandler::displayDessert(const QString &imagePath) {
  QPixmap pixmap(imagePath);
  if (!pixmap.isNull()) {
    QSize newSize(200, 200);

    temporaryLabel->setPixmap(pixmap.scaled(newSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    temporaryLabel->resize(newSize);
    updateDessertPosition();
    temporaryLabel->show();
    // Use QTimer to wait 5 seconds before removing the image
    QTimer::singleShot(3000, this, [this]() {
      temporaryLabel->clear(); // Removes the pixmap from the label
      checkLevels();
    });

  } else {
    qDebug() << "Failed to load image for taco event.";
  }
}

void BitBuddySpriteHandler::changeSpriteSmoothly(const QString &imagePath) {
  auto *effect = new QGraphicsOpacityEffect(this);
  displayLabel->setGraphicsEffect(effect);

  auto *animation = new QPropertyAnimation(effect, "opacity");
  animation->setDuration(500); // 500 ms for fade out
  animation->setStartValue(1.0);
  animation->setEndValue(0.0);
  animation->setEasingCurve(QEasingCurve::InOutQuad);

  connect(animation, &QPropertyAnimation::finished, [this, imagePath, effect, animation]() {
    qDebug() << "Attempting to load image from:" << imagePath;
    QPixmap pixmap(imagePath);
    if (pixmap.isNull()) {
      qDebug() << "Failed to load image from:" << imagePath;
    } else {
      qDebug() << "Image loaded successfully";
    }
    if (!pixmap.isNull()) {
      displayLabel->setPixmap(pixmap.scaled(400, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

    QPropertyAnimation *fadeInAnimation = new QPropertyAnimation(effect, "opacity");
    fadeInAnimation->setDuration(500); // 500 ms for fade in
    fadeInAnimation->setStartValue(0.0);
    fadeInAnimation->setEndValue(1.0);
    fadeInAnimation->setEasingCurve(QEasingCurve::InOutQuad);
    fadeInAnimation->start(QPropertyAnimation::DeleteWhenStopped);

    // Cleanup
    connect(fadeInAnimation, &QPropertyAnimation::finished, effect, &QObject::deleteLater);
    connect(fadeInAnimation, &QPropertyAnimation::finished, animation, &QObject::deleteLater);
  });

  animation->start(QPropertyAnimation::DeleteWhenStopped);

}

void BitBuddySpriteHandler::updatePillsPosition() {

  QSize newSize = temporaryLabel->pixmap().size(); // Get the size of the image
  int parentWidth = temporaryLabel->parentWidget()->width();
  int parentHeight = temporaryLabel->parentWidget()->height();

  int xPosition = (parentWidth - newSize.width()) / 2 + ((parentWidth - newSize.width()) / 45)/3 - ((parentWidth - newSize.width()) / 65);
  int yPosition = (parentHeight - newSize.height()) / 2 + (parentHeight - newSize.height()) / 45;

  temporaryLabel->move(xPosition, yPosition);

}

void BitBuddySpriteHandler::updateDrinkPosition() {
  QSize newSize = temporaryLabel->pixmap().size(); // Get the size of the image
  int parentWidth = temporaryLabel->parentWidget()->width();
  int parentHeight = temporaryLabel->parentWidget()->height();

  int xPosition = (parentWidth - newSize.width()) / 2 + ((parentWidth - newSize.width()) / 45)/3 - ((parentWidth - newSize.width()) / 65) - 20;
  int yPosition = (parentHeight - newSize.height()) / 2 + 125;

  temporaryLabel->move(xPosition, yPosition);

}

void BitBuddySpriteHandler::updateTacoPosition() {
  QSize newSize = temporaryLabel->pixmap().size(); // Get the size of the image
  int parentWidth = temporaryLabel->parentWidget()->width();
  int parentHeight = temporaryLabel->parentWidget()->height();

  int xPosition = ((parentWidth - newSize.width()) / 2) - 100;
  int yPosition = (parentHeight - newSize.height()) / 2 + 75;

  temporaryLabel->move(xPosition, yPosition);

}

void BitBuddySpriteHandler::updateBubblePosition() {
  // Dimensions of the central box
  const int boxWidth = 300;
  const int boxHeight = 300;

  // Calculate the top-left corner of the central box
  int boxStartX = ((displayLabel->width() - boxWidth) / 2 ) + 500;
  int boxStartY = ((displayLabel->height() - boxHeight) / 2 ) + 150 ;

  // Ensure bubbles are positioned within the 300x300 central box
  for (QLabel* bubble : bubbleLabels) {
    if (bubble) {
      int x = boxStartX + (rand() % boxWidth) ; // Ensuring x is within the box
      int y = boxStartY + (rand() % boxHeight); // Ensuring y is within the box
      bubble->move(x, y);
    }
  }
}

void BitBuddySpriteHandler::updateZZZPosition() {
  QSize newSize = temporaryLabel->pixmap().size(); // Get the size of the image
  int parentWidth = temporaryLabel->parentWidget()->width();
  int parentHeight = temporaryLabel->parentWidget()->height();

  int xPosition = ((parentWidth - newSize.width()) / 2) -135;
  int yPosition = ((parentHeight - newSize.height()) / 2) - 185;

  temporaryLabel->move(xPosition, yPosition);

}

void BitBuddySpriteHandler::updateDessertPosition() {
  QSize newSize = temporaryLabel->pixmap().size(); // Get the size of the image
  int parentWidth = temporaryLabel->parentWidget()->width();
  int parentHeight = temporaryLabel->parentWidget()->height();

  int xPosition = (parentWidth - newSize.width()) / 2 + ((parentWidth - newSize.width()) / 45)/3 - ((parentWidth - newSize.width()) / 65) - 10;
  int yPosition = (parentHeight - newSize.height()) / 2 + 90;

  temporaryLabel->move(xPosition, yPosition);
}

BitBuddyAttributeName BitBuddySpriteHandler::checkLevels(){
  std::vector<BitBuddyAttributeName::UniqueName> attributes = {
      BitBuddyAttributeName::HUNGER, BitBuddyAttributeName::HAPPINESS, BitBuddyAttributeName::THIRST, BitBuddyAttributeName::HEALTH, BitBuddyAttributeName::TIREDNESS, BitBuddyAttributeName::BOREDOM, BitBuddyAttributeName::HYGIENE
  };

  for (const auto& attr : attributes) {
    int value = 0;
    switch (attr) {
      case BitBuddyAttributeName::HUNGER:
        value = bitBuddy->getAttributeValue(BitBuddyAttributeName::HUNGER);
        if (value < BitBuddyAttributeName::valueWhereChange(BitBuddyAttributeName::HUNGER)) {
          changeSpriteSmoothly(QString::fromStdString(BitBuddyAttributeName::imageURL(BitBuddyAttributeName::HUNGER)));
        }
        break;
      case BitBuddyAttributeName::HAPPINESS:
        value = bitBuddy->getAttributeValue(BitBuddyAttributeName::HAPPINESS);
        if (value < BitBuddyAttributeName::valueWhereChange(BitBuddyAttributeName::HAPPINESS)) {
          changeSpriteSmoothly(QString::fromStdString(BitBuddyAttributeName::imageURL(BitBuddyAttributeName::HAPPINESS)));
        }
        break;
      case BitBuddyAttributeName::THIRST:
        value = bitBuddy->getAttributeValue(BitBuddyAttributeName::THIRST);
        if (value < BitBuddyAttributeName::valueWhereChange(BitBuddyAttributeName::THIRST)) {
          changeSpriteSmoothly(QString::fromStdString(BitBuddyAttributeName::imageURL(BitBuddyAttributeName::THIRST)));
        }
        break;
      case BitBuddyAttributeName::HEALTH:
        value = bitBuddy->getAttributeValue(BitBuddyAttributeName::HEALTH);
        if (value < BitBuddyAttributeName::valueWhereChange(BitBuddyAttributeName::HEALTH)) {
          changeSpriteSmoothly(QString::fromStdString(BitBuddyAttributeName::imageURL(BitBuddyAttributeName::HEALTH)));
        }
        break;
      case BitBuddyAttributeName::TIREDNESS:
        value = bitBuddy->getAttributeValue(BitBuddyAttributeName::TIREDNESS);
        if (value < BitBuddyAttributeName::valueWhereChange(BitBuddyAttributeName::TIREDNESS)) {
          changeSpriteSmoothly(QString::fromStdString(BitBuddyAttributeName::imageURL(BitBuddyAttributeName::TIREDNESS)));
        }
        break;
      case BitBuddyAttributeName::BOREDOM:
        value = bitBuddy->getAttributeValue(BitBuddyAttributeName::BOREDOM);
        if (value < BitBuddyAttributeName::valueWhereChange(BitBuddyAttributeName::BOREDOM)) {
          changeSpriteSmoothly(QString::fromStdString(BitBuddyAttributeName::imageURL(BitBuddyAttributeName::BOREDOM)));
        }
        break;
      case BitBuddyAttributeName::HYGIENE:
        value = bitBuddy->getAttributeValue(BitBuddyAttributeName::HYGIENE);
        if (value < BitBuddyAttributeName::valueWhereChange(BitBuddyAttributeName::HYGIENE)) {
          changeSpriteSmoothly(QString::fromStdString(BitBuddyAttributeName::imageURL(BitBuddyAttributeName::HYGIENE)));
        }
        break;
      default:
        std::cout << "Unknown Attribute" << std::endl;
    }
  }


}

