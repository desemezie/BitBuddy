//
// Created by Ryan Hecht  on 2024-03-24.
//

#include "../../include/window/ShopWindow.h"

#include <QGuiApplication>
#include <QScreen>
#include <QVBoxLayout>

ShopWindow::ShopWindow(QWidget *parent) : QWidget(parent) {
  const QScreen *screen = QGuiApplication::primaryScreen();
  const QRect screenSize = screen->availableGeometry();
  const int width = screenSize.width() * 0.5;    // 50% of the screen width
  const int height = screenSize.height() * 0.5;  // 50% of the screen height

  // Set window title and size based on screen size
  setWindowTitle("Game Store");
  resize(width, height);

  titleLabel = new QLabel("Welcome to the Game Store", this);
  titleLabel->setAlignment(Qt::AlignCenter);

  gameListWidget = new QListWidget(this);
  gameListWidget->addItem("Game 1");
  gameListWidget->addItem("Game 2");
  gameListWidget->addItem("Game 3");

  buyButton = new QPushButton("Buy", this);
  connect(buyButton, &QPushButton::clicked, this, &ShopWindow::onBuyButtonClicked);

  auto *layout = new QVBoxLayout(this);
  layout->addWidget(titleLabel);
  layout->addWidget(gameListWidget);
  layout->addWidget(buyButton);
}

void ShopWindow::onBuyButtonClicked() { qDebug() << "Buy button clicked"; }
