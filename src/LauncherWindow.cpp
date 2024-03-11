//
// Created by Annabel Irani on 2024-03-10.
//

#include <QVBoxLayout>
#include "LauncherWindow.h"
#include "MainWindow.h"
#include "service/GameService.h"
#include <QApplication>
#include <QGraphicsDropShadowEffect>

constexpr int SCREEN_WIDTH = 1280;
constexpr int SCREEN_HEIGHT = 720;

LauncherWindow::LauncherWindow(QWidget *parent) : QWidget(parent) {
  this->setStyleSheet("background-color: white;");
  auto *layout = new QVBoxLayout(this);
  addImages();
  layout->addStretch(1);
  auto *welcomeLabel = new QLabel(this);

  welcomeLabel->setStyleSheet(R"(
    QLabel {
        background-color: white;
        border-radius: 15px; /* Adjust for desired roundness */
        border: 1px solid #000; /* Optional: adds a border */
        padding: 10px; /* Adjust spacing inside the label */
    }
    )");
  welcomeLabel->setAlignment(Qt::AlignCenter);

// Using HTML to format the text content, allowing for different sizes/styles
  QString labelText = R"(
    <h1 style="font-size: 24px;" >Welcome to Bit Buddy!</h1>
    <p style="font-size: 16px;" >Here are some instructions for the game:<br>
    - Do this<br>
    - Do that<br>
    - Have fun!</p>
  )";

  welcomeLabel->setFixedSize(300,200);
  welcomeLabel->setText(labelText);
  welcomeLabel->setWordWrap(true);

  layout->addWidget(welcomeLabel, 0, Qt::AlignCenter);
  layout->addSpacerItem(new QSpacerItem(20, 250, QSizePolicy::Minimum, QSizePolicy::Expanding));

  this->resize(SCREEN_WIDTH, SCREEN_HEIGHT);

  auto *playButton = new QPushButton("PLAY",this);


  playButton->setStyleSheet(
      "QPushButton { "
      "color: #000000; "
      "border: 2px solid #000000; "
      "border-radius: 10px; "
      "background-color: white; "
      "padding: 5px; "
      "}"
      "QPushButton:hover { "
      "background-color: #000000;"
      "color: white;"

      "}"
      );

  auto *shadowEffect = new QGraphicsDropShadowEffect(welcomeLabel);
  shadowEffect->setBlurRadius(5);
  shadowEffect->setXOffset(5);
  shadowEffect->setYOffset(5);
  shadowEffect->setColor(Qt::black);
  playButton->setGraphicsEffect(shadowEffect);
  welcomeLabel->setGraphicsEffect(shadowEffect);
  playButton->setFixedSize(100,60);
  layout->addWidget(playButton); // Add the button to the layout
  layout->addStretch();
  layout->setAlignment(playButton, Qt::AlignHCenter);
  layout->setContentsMargins(0, 0, 0, 100); // Adjust top margin
  layout->setSpacing(10);

  connect(playButton, &QPushButton::clicked, this, [this]() {
    this->hide();
    auto *mainWindow = new MainWindow();
    mainWindow->setAttribute(Qt::WA_DeleteOnClose);
    mainWindow->show();

    GameService::getInstance().startService();


  });
}

void LauncherWindow::addImages() {
  QWidget *imageContainer = new QWidget(this);
  imageContainer->setStyleSheet("background-color:#eaaee3");

  /*
   * beige - #d8a38d
   * purple - #c79dfb
   * yellow - #fbfb9d
   * blue - #bbdddd
   * pink - #eaaee3
   */
  imageContainer->setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT); // Adjust as needed


  int x = 0, y = 0; // Initial position
  int xStep = 100; // Horizontal step size
  int yStep = 100; // Vertical step size
  int numRows = (SCREEN_HEIGHT / yStep ) + 2;
  bool moveRight = true; // Direction control
  int count = 0;
  std::vector<std::string> images = {":assets/happy_bitbuddy.png",":assets/angry_bitbuddy.png", ":assets/mad_bitbuddy.png", ":assets/sad_bitbuddy.png", ":assets/sick_bitbuddy.png", ":assets/sick_bitbuddy.png"};
  for (int i = 0; i < numRows; ++i) {
    x = 0;
    for (int j = 0; j < 13; j++) {

      int pos = count % 6;
      QLabel *imageLabel = new QLabel(imageContainer);

      QPixmap pixmap(images[pos].c_str()); // Adjust path accordingly
      imageLabel->setPixmap(pixmap.scaled(QSize(80, 80),
                                          Qt::KeepAspectRatio,
                                          Qt::SmoothTransformation)); // Adjust size as needed
      imageLabel->adjustSize();
      imageLabel->move(x, y);
      x += xStep;
      count ++;
    }
    y += yStep;
  }
}