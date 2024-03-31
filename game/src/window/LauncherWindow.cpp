//
// Created by Annabel Irani on 2024-03-10.
//

#include <QVBoxLayout>
#include "window/LauncherWindow.h"
#include "MainWindow.h"
#include "service/BitBuddyService.h"
#include "model/BitBuddy.h"
#include <QApplication>
#include <QGraphicsDropShadowEffect>
#include <QLineEdit>
#include <QTimer>
#include <QFontDatabase>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>


const QString LABEL_FONT = ":/assets/fonts/ARCADECLASSIC.TTF";
const QString GAMES_FONT = ":/assets/fonts/GAMES.TTF";
constexpr int SCREEN_WIDTH = 1920;
constexpr int SCREEN_HEIGHT = 1080;

/**
 * @brief Launcher window Constructor
 * @brief Will initialize the launcher window and call the addImages function to add the background
 * @param parent
 */
LauncherWindow::LauncherWindow(QWidget *parent) : QWidget(parent) {
  // font
  int id = QFontDatabase::addApplicationFont(LABEL_FONT);
  QStringList fontFamilies = QFontDatabase::applicationFontFamilies(id);
  const QString fontFamily = fontFamilies.at(0);

  int gameFontID = QFontDatabase::addApplicationFont(GAMES_FONT);
  QStringList fontFamilies2 = QFontDatabase::applicationFontFamilies(gameFontID);
  const QString fontFamily2 = fontFamilies2.at(0);
  // adding background of layout
  this->setStyleSheet("background-color: white;");
  auto *layout = new QVBoxLayout(this);

  // adding background images
  addImages();
  layout->addStretch(1);


  auto *welcomeLabel = new QLabel(this);

  // set design for welcome label
  welcomeLabel->setStyleSheet(R"(
    QLabel {
        background-color: white;
        border-radius: 15px; /* Adjust for desired roundness */
        border: 1px solid #000; /* Optional: adds a border */
        padding: 10px; /* Adjust spacing inside the label */
        color : black;
    }
    )");
  welcomeLabel->setAlignment(Qt::AlignCenter);


  // Using HTML to format the text content, allowing for different sizes/styles
  QString labelText = QString(R"(
    <p style="font-size: 46px; font-family: '%1';" >Welcome to Bit Buddy!</p>
    <p style="font-size: 18px; font-family: '%1' " >BitBuddy is your newest digital interactive friend<br>
    Like a pet, a BitBuddy is a lot of responsibility<br>
    Make sure you keep an eye on it and take care of it accordingly<br>
    And dont forget to have fun!</p>
  )").arg(fontFamily2);

  // Sets size and text
  welcomeLabel->setFixedSize(400, 300);
  welcomeLabel->setText(labelText);
  welcomeLabel->setWordWrap(true);

  // Adding fade in widget
  QGraphicsOpacityEffect *fadeinEffect = new QGraphicsOpacityEffect(welcomeLabel);
  welcomeLabel->setGraphicsEffect(fadeinEffect);
  QPropertyAnimation *fadeInAnimation = new QPropertyAnimation(fadeinEffect, "opacity");
  // Fade in lasts for 1.5 seconds
  fadeInAnimation->setDuration(1500);
  // Original opacity
  fadeInAnimation->setStartValue(0.0);
  // End opacity
  fadeInAnimation->setEndValue(1.0);
  fadeInAnimation->setEasingCurve(QEasingCurve::InOutQuad);

  // Start the animation
  fadeInAnimation->start(QPropertyAnimation::DeleteWhenStopped);

  layout->addWidget(welcomeLabel, 0, Qt::AlignCenter);

  // Adds spacer
  layout->addSpacerItem(new QSpacerItem(20, 250, QSizePolicy::Minimum, QSizePolicy::Expanding));

  this->resize(SCREEN_WIDTH, SCREEN_HEIGHT);

  auto *playButton = new QPushButton("PLAY", this);
  // supposed to make the button press when enter is clicked
  playButton->setAutoDefault(true);
  playButton->setDefault(true);

  // playButton design
  playButton->setStyleSheet(
      "QPushButton { " "color: #000000; "
                        "border: 2px solid #000000; "
                        "border-radius: 10px; "
                        "background-color: white;"
                        "padding: 5px; " "}"

      "QPushButton:hover { " "background-color: #000000;"
                             "color: white;"
                             "}");


  // add the place to insert a name for your bitbuddy

  //nameLineEdit = new QLineEdit(this);
  //nameLineEdit->setPlaceholderText("Enter your name");
  //nameLineEdit->setFixedSize(200, 30);
  // Set the width and height according to your preference
  //nameLineEdit->setStyleSheet("border: 1px solid black;");
  //nameLineEdit->setStyleSheet("QLineEdit { color: black !important; }");

  nameLine = new QLineEdit(this);
  nameLine->setPlaceholderText("Enter your BitBuddy's name");
  nameLine->setFixedSize(350, 50);

  if (fontFamilies.isEmpty()) {
    qWarning() << "Failed to load font from" << LABEL_FONT;
  } else {
    const QString &family = fontFamilies.at(0);
    QFont retroFont(family, 24, QFont::Bold);
    nameLine->setFont(retroFont);
  }
  // Set the width and height according to your preference

  nameLine->setStyleSheet("border: 1px solid black;");
  nameLine->setStyleSheet("QLineEdit { color: black !important; "
                                           "border: 3px solid black; "
                              "}");


  auto *hLayoutForLineEdit = new QHBoxLayout();
  hLayoutForLineEdit->addStretch(1);
  // Add a stretchable space on the left side to push everything else to the right
  hLayoutForLineEdit->addWidget(nameLine);
  // Add the nameLine to the QHBoxLayout
  hLayoutForLineEdit->addStretch(1);
  // Add a stretchable space on the right side to push everything else to the left
  layout->addLayout(hLayoutForLineEdit);
  // This adds the QHBoxLayout (which contains your centered nameLine) to the main QVBoxLayout


  layout->addStretch();

  // Sets size of playButton
  playButton->setFixedSize(100, 60);

  // Align the box
  // Add playButton
  layout->addWidget(playButton);

  // Align playButton
  layout->addStretch();
  layout->setAlignment(playButton, Qt::AlignHCenter);
  layout->setContentsMargins(0, 0, 0, 100); // Adjust top margin
  layout->setSpacing(10);

  // connect the playButton to an action
  connect(playButton, &QPushButton::clicked, this, [this]() {
    BitBuddyService::getBitBuddy().setName(nameLine->text().toStdString());
    this->hide();
    auto *mainWindow = new MainWindow();
    mainWindow->setAttribute(Qt::WA_DeleteOnClose);
    mainWindow->show();
  });
}

/**
  * @brief addImages() - helper method to add the bitbuddies
  */
void LauncherWindow::addImages() {
  // Initializes container
  QWidget *imageContainer = new QWidget(this);
  QTimer *timer = new QTimer(this);
  connect(timer, &QTimer::timeout, [imageContainer]() {
    static int colorIndex = 0;
    // Array of background colours to transition throughout
    QStringList backgroundColors = {"background-color:#eaaee3", "background-color:#c79dfb", "background-color:#fbfb9d",
                                    "background-color:#bbdddd", "background-color:#ffae42",  "background-color:#77dd77"};
    // Sets the stylesheet as the backgroundColors
    imageContainer->setStyleSheet(backgroundColors[colorIndex]);
    // Will have a changing index
    colorIndex = (colorIndex + 1) % backgroundColors.size();
  });
  // Will change the colors every .25 of a second
  timer->start(250);

  imageContainer->setStyleSheet("background-color:#eaaee3");


  imageContainer->setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT); // Adjust as needed

  // Logic for bitbuddies
  int x = 0, y = 0; // Initial position
  int xStep = 100; // Horizontal step size
  int yStep = 100; // Vertical step size
  int numRows = (SCREEN_HEIGHT / yStep) + 2;
  bool moveRight = true; // Direction control
  int count = 0;

  // vector of images
  std::vector<std::string> images = {":assets/happy_bitbuddy.png", ":assets/angry_bitbuddy.png",
                                     ":assets/mad_bitbuddy.png", ":assets/sad_bitbuddy.png",
                                     ":assets/sick_bitbuddy.png", ":assets/sick_bitbuddy.png"};

  // for loop for image placement
  for (int i = 0; i < numRows; ++i) {
    x = 0;
    for (int j = 0; j < 20; j++) {
      int pos = count % 6;
      QLabel *imageLabel = new QLabel(imageContainer);

      QPixmap pixmap(images[pos].c_str()); // Adjust path accordingly
      imageLabel->setPixmap(pixmap.scaled(QSize(80, 80), Qt::KeepAspectRatio, Qt::SmoothTransformation));
      // Adjust size as needed
      imageLabel->adjustSize();
      imageLabel->move(x, y);
      x += xStep;
      count++;
    }
    y += yStep;
  }
}
