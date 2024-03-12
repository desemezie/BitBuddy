//
// Created by Ryan Hecht  on 2024-02-25.
//

#include <QApplication>
#include <QGridLayout>
#include "MainWindow.h"
#include "model/BitBuddyAttributeName.h"
#include "component/BitBuddyStatusWidget.h"
#include "model/BitBuddy.h"
#include "component/BitBuddyActionButton.h"
#include "service/EventDispatcherService.h"
#include <iostream>

constexpr int SCREEN_WIDTH = 1280;
constexpr int SCREEN_HEIGHT = 720;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  auto *centralWidget = new QWidget(this);
  setCentralWidget(centralWidget);
  resize(SCREEN_WIDTH, SCREEN_HEIGHT);

  // Grid layout for the central widget
  auto *layout = new QGridLayout(centralWidget);

  centralWidget->setLayout(layout);

  auto *bitBuddy = new BitBuddy("BitBuddy");

  auto *statusWidget = new BitBuddyStatusWidget(bitBuddy, this);

  // Create spacers to push the status widget to the top-left corner
  auto *verticalSpacer = new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

  // connect spriteHandler to bitbuddy
  spriteLabel = new QLabel(centralWidget);
  spriteHandler = new BitBuddySpriteHandler(spriteLabel, this);

  loadDefaultSprite();

  layout->addWidget(statusWidget, 0, 0, Qt::AlignTop | Qt::AlignLeft);
  layout->addItem(verticalSpacer, 1, 0, 1, 2);

  // Setting button icon
  QIcon buttonIcon("");

  auto *rowLayout1 = new QHBoxLayout;
  auto *rowLayout2 = new QHBoxLayout;

  for (int i = 0; i < NUMBER_OF_ATTRIBUTES; i++) {
    auto attribute = static_cast<BitBuddyAttributeName::UniqueName>(i);
    auto *but = new BitBuddyActionButton(buttonIcon,
                                         QString::fromStdString(BitBuddyAttributeName::toString(attribute)),
                                         attribute,
                                         centralWidget);
    if (i < 4) {
      rowLayout1->addWidget(but);
    } else {
      rowLayout2->addWidget(but);
    }
  }

  rowLayout1->setSpacing(0);
  rowLayout2->setSpacing(0);
  layout->addWidget(spriteLabel, 0, 0, 2, 2, Qt::AlignCenter);
  layout->addLayout(rowLayout1, 2, 0, 2, 2);
  layout->addLayout(rowLayout2, 4, 0, 2, 2);

  layout->setAlignment(Qt::AlignBottom);
  connect(&EventDispatcherService::getInstance(), &EventDispatcherService::eventDispatched,
          spriteHandler, &BitBuddySpriteHandler::handleEvent);

}

MainWindow::~MainWindow() = default;

void MainWindow::loadDefaultSprite() {
  QImage image(":/assets/happy_bitbuddy.png");

  if (image.isNull()) {
    qDebug() << "Failed to load the image.";
  } else {
    QSize imageSize(400, 400);
    QPixmap pixmap = QPixmap::fromImage(image.scaled(imageSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    if (!pixmap.isNull()) {
      spriteLabel->setPixmap(pixmap);
    } else {
      qDebug() << "Failed to create a pixmap from image.";
    }
  }
}
