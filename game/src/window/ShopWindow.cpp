//
// Created by Ryan Hecht  on 2024-03-24.
//

#include "../../include/window/ShopWindow.h"
#include "model/BitBuddy.h"
#include "service/BitBuddyService.h"
#include <QGuiApplication>
#include <QScreen>
#include <QVBoxLayout>
#include <iostream>

ShopWindow::ShopWindow(QWidget *parent) : QWidget(parent, Qt::Window) {
  const QScreen *screen = QGuiApplication::primaryScreen();
  const QRect screenSize = screen->availableGeometry();
  const int width = screenSize.width() * 0.375;    // 50% of the screen width
  const int height = screenSize.height() * 0.5;  // 50% of the screen height


  // Set window title and size based on screen size
  setWindowTitle("Game Store");
  resize(width, height);

  titleLabel = new QLabel("Welcome to the Game Store", this);
  titleLabel->setAlignment(Qt::AlignCenter);


  gameListWidget = new QListWidget(this);

  // Creates items for items in the shop
  ShopWindow::addItem("Soap",  ":/assets/tamagochi_soap_final.png");
  ShopWindow::addItem("Drink", ":/assets/tamagochi_drink.png");
  ShopWindow::addItem("Hotdog", ":/assets/hotdog.png");
  ShopWindow::addItem("Pizza", ":/assets/pizza.png");
  ShopWindow::addItem("Soap",  ":/assets/tamagochi_soap_final.png");
  ShopWindow::addItem("Slushie", ":/assets/slush.png");



  // Stylesheet for the Widget
  gameListWidget->setStyleSheet(R"(
    QListWidget {
        border: 2px solid gray; /* Adjust the border color/width as needed */
        border-radius: 10px; /* Adjust the radius as needed */
        background-color: pink; /* Adjust background color and opacity */
    }
    QListWidget::item {
        background-color: transparent; /* Make item background transparent */
        font-size: 20pt; /* Set font size */
        font-weight: bold; /* Make text bold */
    }
)");

  // Other aesthetics
  gameListWidget->viewport()->setAutoFillBackground(false);
  gameListWidget->setViewMode(QListView::IconMode);
  gameListWidget->setFlow(QListView::LeftToRight);
  gameListWidget->setWrapping(true); // Prevent wrapping to the next line
  gameListWidget->setSpacing(10);
  gameListWidget->setIconSize(*new QSize(100,100));



  buyButton = new QPushButton("Buy", this);

  buyButton->setStyleSheet(
      "QPushButton {\n"
      "    color: #000000;\n"
      "    border: 2px solid #000000;\n"
      "    border-radius: 15px; /* Increase for chubbier corners */\n"
      "    background-color: white;\n"
      "    padding: 10px 20px; /* Increase padding for a chubbier look */\n"
      "    font-size: 25px;\n"
      "    text-align: center;\n"
      "    icon-size: 60px; /* Size for the icons */\n"
      "    min-width: 100px; /* Minimum width to accommodate text and icon */\n"
      "    min-height: 40px; /* Minimum height for a chubbier look */\n"

      "}\n"
      "\n"
      "QPushButton:hover {\n"
      "    background-color: #000000;\n"
      "    color: white;\n"
      "}"

  );

  connect(buyButton, &QPushButton::clicked, this, &ShopWindow::onBuyButtonClicked);

  auto *layout = new QVBoxLayout(this);
  layout->addWidget(titleLabel);
  layout->addWidget(gameListWidget);
  layout->addWidget(buyButton);
}


// Function to add items to the shop
void ShopWindow::addItem(const QString &name, const QString &iconPath) {
  // Creates new item
  auto *item = new QListWidgetItem(name, gameListWidget);

  // Sets the icon for it
  item->setIcon(QIcon(iconPath));
  // Adds it to the gameListWidget
  gameListWidget->addItem(item);

}



void ShopWindow::onBuyButtonClicked() {
  qDebug() << "Buy Button Clicked";
  qDebug() << gameListWidget->currentItem()->text();
  setBitBuddy(&BitBuddyService::getBitBuddy());
  if (gameListWidget->currentItem() != nullptr && bitBuddy != nullptr) {
    QString itemName = gameListWidget->currentItem()->text();
    qDebug() << itemName << "purchased";

    // Call BitBuddy's method to add the item to thingsPurchased
    bitBuddy->addItemPurchased(itemName.toStdString());
  }
  qDebug() << bitBuddy->thingsPurchased.size();
  this->showItemsPurchased();
}
void ShopWindow::setBitBuddy(BitBuddy *BitBuddy) {
  this->bitBuddy = BitBuddy;
}

void ShopWindow::showItemsPurchased(){
  for(const auto &item: bitBuddy->thingsPurchased) {
    std::cout << item << std::endl;
  }
}

