//
// Created by Annabel Irani on 2024-03-08.
//
#include "service/BitBuddySpriteHandler.h"
#include <QDebug>
#include <QPixmap>
#include <QTimer>
#include <QAbstractAnimation>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>

// Constructor
BitBuddySpriteHandler::BitBuddySpriteHandler(QLabel *displayLabel, QObject *parent)
    : QObject(parent), displayLabel(displayLabel) {
  temporaryLabel = new QLabel(displayLabel->parentWidget());
  temporaryLabel->setAttribute(Qt::WA_TransparentForMouseEvents);
  temporaryLabel->hide();
}

// Correctly place the changeSprite method within the BitBuddySpriteHandler class
void BitBuddySpriteHandler::changeSprite(const std::string &state) {
  QString imageName;

  if (state.find("stomach rumbles loudly") != std::string::npos) {
    qDebug() << "Found and identified for hungry";
    imageName = ":/assets/angry_bitbuddy.png";
    changeSpriteSmoothly(imageName);

  } else if (state.find("seems a bit withdrawn") != std::string::npos) {
    qDebug() << "Found and identified for withdrawn";
    imageName = ":/assets/mad_bitbuddy.png";

  } else if (state.find("desperately thirsty") != std::string::npos) {
    qDebug() << "Found and identified for thirsty";
    imageName = ":/assets/sad_bitbuddy.png";

  } else if (state.find("doesn't seem to be feeling well") != std::string::npos) {
    qDebug() << "Found and identified for sick";
    imageName = ":/assets/sad_bitbuddy.png";

  } else if (state.find("eyelids are drooping") != std::string::npos) {
    qDebug() << "Found and identified for tired";
    imageName = ":/assets/sleeping_bitbuddy.png";

  } else if (state.find("lets out a big yawn") != std::string::npos) {
    qDebug() << "Found and identified for bored";
    imageName = ":/assets/sad_bitbuddy.png";

  } else if (state.find("could use a bath") != std::string::npos) {
    qDebug() << "Found and identified for bath";
    imageName = ":/assets/angry_bitbuddy.png";

  } else if (state.find("Event for: Hunger") != std::string::npos) {
    QString imagePath = ":/assets/tamagochi_feed.png";
    displayTacoAndRemove(imagePath);

  } else if (state.find("Event for: Hygiene") != std::string::npos) {
    QString imagePath = ":/assets/tamagochi_bubble.png";
    displayBubbles(imagePath);

  } else if (state.find("Event for: Tiredness") != std::string::npos) {
    QString imagePath = ":/assets/sleeping_bitbuddy.png";
    changeSpriteSmoothly(imagePath);
    QString zzzPath = ":/assets/tamagochi_zzz.png";
    displayZZZ(zzzPath);

    QTimer::singleShot(5000, this, [this]() {
      QString defaultImagePath = ":/assets/happy_bitbuddy.png"; // Path to your default sprite
      changeSpriteSmoothly(defaultImagePath);
    });
  } else if (state.find("Event for: Thirst") != std::string::npos) {
    qDebug() << "HERE";
    QString imagePath = ":/assets/happy_bitbuddy.png";
    changeSpriteSmoothly(imagePath);
    QString drink = ":/assets/tamagochi_drink_2.png";
    displayDrink(drink);
  } else if (state.find("Event for: Health") != std::string::npos) {
    QString imagePath = ":/assets/happy_bitbuddy.png";
    changeSpriteSmoothly(imagePath);
    QString pills = ":/assets/tamagochi_pills.png";
    displayPills(pills);
  }

}

void BitBuddySpriteHandler::handleEvent(const Event &event) {

  std::string state = event.getDescription();
  qDebug() << "Received event desc: " << QString::fromStdString(state);
  changeSprite(state);
}

void BitBuddySpriteHandler::displayPills(const QString &imagePath) {
  qDebug() << "load image for pill event.";
  QPixmap pixmap(imagePath);
  if (!pixmap.isNull()) {
    QSize newSize(50, 50);

    temporaryLabel->setPixmap(pixmap.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    temporaryLabel->resize(newSize);
    temporaryLabel->move(607, 380);

    temporaryLabel->show();
    // Use QTimer to wait 5 seconds before removing the image
    QTimer::singleShot(3000, this, [this]() {
      temporaryLabel->clear(); // Removes the pixmap from the label
      // Optionally reset to a default sprite or state here
    });
  } else {
    qDebug() << "Failed to load image for pill event.";
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
      // Optionally reset to a default sprite or state here
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

