//
// Created by Ryan Hecht  on 2024-02-25.
//

#include "MainWindow.h"

#include <QApplication>
#include <QGridLayout>
#include <QGuiApplication>
#include <QScreen>
#include <iostream>

#include "../include/window/SettingsWindow.h"
#include "../include/window/StatsWindow.h"
#include "component/BitBuddyActionButton.h"
#include "component/BitBuddyStatusWidget.h"
#include "component/LightButton.h"
#include "component/StatsButton.h"
#include "component/UserBankAccountBalanceWidget.h"
#include "model/BitBuddyAttributeName.h"
#include "service/BitBuddyService.h"
#include "service/EventDispatcherService.h"
#include "service/FileStorageService.h"
#include "service/GameService.h"
#include "service/UserBankAccountService.h"
#include "window/ShopWindow.h"

constexpr double DEFAULT_SCREEN_PERCENTAGE = 0.7;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  BitBuddyService::registerBitBuddy(FileStorageService::loadBitBuddy("BitBuddy"));
  UserBankAccountService::registerUserBankAccount(&FileStorageService::loadUserBankAccount());

  setupUi();

  connect(settingsButton, &QPushButton::clicked, this, &MainWindow::openSettings);
  connect(lightSwitch, &LightButton::themeChange, this, &MainWindow::updateTheme);
  connect(lightSwitch, &LightButton::textChange, bitBuddyStatusWidget, &BitBuddyStatusWidget::updateDarkMode);
  connect(stats, &QPushButton::clicked, this, [this]() {
    auto *statsWindow = new StatsWindow(QString::fromStdString(BitBuddyService::getBitBuddy().getName()), this);
    statsWindow->setAttribute(Qt::WA_DeleteOnClose);
    statsWindow->show();
  });
  connect(&EventDispatcherService::getInstance(), &EventDispatcherService::eventDispatched, spriteHandler,
          &BitBuddySpriteHandler::handleEvent);

  GameService::startService();
}

MainWindow::~MainWindow() {
  FileStorageService::saveBitBuddy(BitBuddyService::getBitBuddy());
  FileStorageService::saveUserBankAccount(UserBankAccountService::getUserBankAccount());

  delete spriteHandler;
  delete spriteLabel;
  delete settingsButton;
}

void MainWindow::setupUi() {
  // Set up central widget
  auto *centralWidget = new QWidget(this);
  setCentralWidget(centralWidget);
  centralWidget->setObjectName("centralWidget");
  auto *layout = new QGridLayout(centralWidget);
  centralWidget->setLayout(layout);
  centralWidget->setStyleSheet("QWidget#centralWidget { background-image: url(:/assets/background.png); }");
  const QRect screenSize = QGuiApplication::primaryScreen()->availableGeometry();
  const int width = screenSize.width() * DEFAULT_SCREEN_PERCENTAGE;
  const int height = screenSize.height() * DEFAULT_SCREEN_PERCENTAGE;
  resize(width, height);

  // Add bit buddy status widget
  bitBuddyStatusWidget = new BitBuddyStatusWidget(&BitBuddyService::getBitBuddy(), this);
  layout->addWidget(bitBuddyStatusWidget, 0, 0, Qt::AlignTop | Qt::AlignLeft);

  // Add user bank account balance widget
  auto *userBankAccountBalanceWidget = new UserBankAccountBalanceWidget(this);
  layout->addWidget(userBankAccountBalanceWidget, 0, 1, Qt::AlignTop | Qt::AlignLeft);
  // To the right of statusWidget

  // Create spacers to push the status widget to the top-left corner
  auto *verticalSpacer = new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);
  layout->addItem(verticalSpacer, 1, 0, 1, 2);

  // connect spriteHandler to bitbuddy
  spriteLabel = new QLabel(centralWidget);
  spriteHandler = new BitBuddySpriteHandler(spriteLabel, this, &BitBuddyService::getBitBuddy());
  loadDefaultSprite();

  // Add the settings button
  QIcon buttonIcon("");
  QIcon settingsIcon(":/assets/settings.png");
  settingsButton = new QPushButton();
  settingsButton->setIcon(settingsIcon);
  settingsButton->setIconSize(QSize(40, 40));
  layout->addWidget(settingsButton, 0, 1, Qt::AlignTop | Qt::AlignRight);

  // Add the light switch button
  lightSwitch = new LightButton();
  layout->addWidget(lightSwitch, 1, 1, Qt::AlignTop | Qt::AlignCenter);

  // Add the stats button
  QIcon statsIcon(":/assets/info.png");
  stats = new QPushButton();
  stats->setIcon(statsIcon);
  stats->setIconSize(QSize(40, 40));
  layout->addWidget(stats, 0, 1, Qt::AlignCenter | Qt::AlignRight);

  // Add the shop button
  QIcon shopIcon(":/assets/shopicon.png");
  shop = new QPushButton();
  shop->setIcon(shopIcon);
  shop->setIconSize(QSize(40, 40));
  layout->addWidget(shop, 0, 1, Qt::AlignBottom | Qt::AlignRight);
  connect(shop, &QPushButton::clicked, this, &MainWindow::openShopWindow);



  // Add action buttons on the botton
  auto *rowLayout1 = new QHBoxLayout;
  auto *rowLayout2 = new QHBoxLayout;

  for (int i = 0; i < NUMBER_OF_ATTRIBUTES; i++) {
    auto attribute = static_cast<BitBuddyAttributeName::UniqueName>(i);

    auto *but = new BitBuddyActionButton(buttonIcon, QString::fromStdString(BitBuddyAttributeName::toString(attribute)),
                                         attribute, centralWidget);
    but->setButtonStyle();

    if (i < 4) {
      rowLayout1->addWidget(but);
    } else {
      rowLayout2->addWidget(but);
    }
  }

  rowLayout1->setSpacing(1);
  rowLayout2->setSpacing(1);
  layout->addWidget(spriteLabel, 0, 0, 2, 2, Qt::AlignCenter);
  layout->addLayout(rowLayout1, 2, 0, 2, 2);
  layout->addLayout(rowLayout2, 4, 0, 2, 2);
  layout->setAlignment(Qt::AlignBottom);
}

void MainWindow::loadDefaultSprite() const {
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

void MainWindow::resizeEvent(QResizeEvent *event) {
  QWidget::resizeEvent(event);
  if (spriteHandler) {
    spriteHandler->updatePillsPosition();
    spriteHandler->updateDrinkPosition();
    spriteHandler->updateTacoPosition();
    spriteHandler->updateBubblePosition();
    spriteHandler->updateZZZPosition();
  }
}

void MainWindow::openSettings() {
  SettingsWindow settingsDialog(this);
  settingsDialog.exec();
}

void MainWindow::openShopWindow() {
  auto *shopWindow = new ShopWindow(this); // Pass 'this' to set MainWindow as the parent
  shopWindow->setAttribute(Qt::WA_DeleteOnClose); // Ensure the window is deleted automatically when closed
  shopWindow->show();
}


void MainWindow::updateTheme(const QString &newStyle) {
  this->setStyleSheet(newStyle);  // NOTE, THIS CAUSES THE BLUE STATUS BARS TO BECOME GREY
}


