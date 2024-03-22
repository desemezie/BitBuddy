//
// Created by Annabel Irani on 2024-03-08.
//
#include "service/BitBuddySpriteHandler.h"
#include "model/SingleAttributeEvent.h"
#include <QDebug>
#include <QPixmap>
#include <QTimer>
#include <QAbstractAnimation>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>

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
    // Gets the value of the current attiribute
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
  }
  if (specificEvent->getAttribute() == BitBuddyAttributeName::THIRST){
    changeSpriteSmoothly(QString::fromStdString(BitBuddyAttributeName::imageURL(attributeName)));
    displayDrink(":/assets/tamagochi_drink_2.png");
  }
  if (specificEvent->getAttribute() == BitBuddyAttributeName::TIREDNESS) {
    changeSpriteSmoothly(":/assets/sleeping_bitbuddy.png");
    displayZZZ(":/assets/tamagochi_zzz.png");
    QTimer::singleShot(5000, this, [this]() {
      QString defaultImagePath = ":/assets/happy_bitbuddy.png"; // Path to your default sprite
      changeSpriteSmoothly(defaultImagePath);
    });

  }
  if (specificEvent->getAttribute() == BitBuddyAttributeName::HYGIENE) {
    displayBubbles(":/assets/tamagochi_bubble.png");
  }
  if (specificEvent->getAttribute() == BitBuddyAttributeName::HEALTH) {
    displayPills(":/assets/tamagochi_pills.png");
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

    // Dynamic positioning based on the parent widget's size
    int xPosition = displayLabel->parentWidget()->width() - newSize.width() - 700; // 20 pixels from the right edge
    int yPosition = displayLabel->parentWidget()->height() - newSize.height() - 335; // 20 pixels from the bottom edge

    // Move the temporary label to the calculated position
    temporaryLabel->move(xPosition, yPosition);

    temporaryLabel->show();
    // Use QTimer to wait 5 seconds before removing the image
    QTimer::singleShot(3000, this, [this]() {
      temporaryLabel->clear(); // Removes the pixmap from the label
      // Optionally reset to a default sprite or state here
    });
  } else {
    qDebug() << "Failed to load image";
  }
}


void BitBuddySpriteHandler::displayTacoAndRemove(const QString &imagePath) {
  QPixmap pixmap(imagePath);

  if (!pixmap.isNull()) {
    QSize newSize(200, 200);

    temporaryLabel->setPixmap(pixmap.scaled(newSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    temporaryLabel->resize(newSize);
    temporaryLabel->move(400, 270);
    temporaryLabel->show();
    // Use QTimer to wait 5 seconds before removing the image
    QTimer::singleShot(3000, this, [this]() {
      temporaryLabel->clear(); // Removes the pixmap from the label
      // Optionally reset to a default sprite or state here
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
    temporaryLabel->move(535, 395);
    temporaryLabel->show();
    // Use QTimer to wait 5 seconds before removing the image
    QTimer::singleShot(5000, this, [this]() {
      temporaryLabel->clear(); // Removes the pixmap from the label
      // Optionally reset to a default sprite or state here
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
    temporaryLabel->move(400, 125);
    temporaryLabel->show();
    // Use QTimer to wait 5 seconds before removing the image
    QTimer::singleShot(5000, this, [this]() {
      temporaryLabel->clear(); // Removes the pixmap from the label

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
    bubbleLabel->move(x, y);
    bubbleLabel->setAttribute(Qt::WA_TranslucentBackground);
    bubbleLabel->show();

    // Set each bubble to clear after 3 seconds
    QTimer::singleShot(3000, bubbleLabel, [bubbleLabel]() {
      bubbleLabel->deleteLater(); // Ensure the label is properly deleted
    });
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



