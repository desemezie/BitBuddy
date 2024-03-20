//
// Created by Annabel Irani on 2024-03-10.
//

#include <QVBoxLayout>
#include "LauncherWindow.h"
#include "MainWindow.h"
#include "service/GameService.h"
#include <QApplication>
#include <QGraphicsDropShadowEffect>
#include <QLineEdit>
#include <QTimer>

constexpr int SCREEN_WIDTH = 1920;
constexpr int SCREEN_HEIGHT = 1080;

LauncherWindow::LauncherWindow(QWidget *parent) : QWidget(parent) {

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
  QString labelText = R"(
    <h1 style="font-size: 24px;" >Welcome to Bit Buddy!</h1>
    <p style="font-size: 16px;" >Here are some instructions for the game:<br>
    - Do this<br>
    - Do that<br>
    - Have fun!</p>
  )";

  welcomeLabel->setFixedSize(300, 200);
  welcomeLabel->setText(labelText);
  welcomeLabel->setWordWrap(true);

  layout->addWidget(welcomeLabel, 0, Qt::AlignCenter);
  layout->addSpacerItem(new QSpacerItem(20, 250, QSizePolicy::Minimum, QSizePolicy::Expanding));

  this->resize(SCREEN_WIDTH, SCREEN_HEIGHT);

  auto *playButton = new QPushButton("PLAY", this);

  // playbutton design
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

  // add the place to insert a name for your bitbuddy
  nameLineEdit = new QLineEdit(this);
  nameLineEdit->setPlaceholderText("Enter your name");
  nameLineEdit->setFixedSize(200, 30); // Set the width and height according to your preference
  nameLineEdit->setStyleSheet("border: 1px solid black;");
  nameLineEdit->setStyleSheet("QLineEdit { color: black !important; }");


  auto *hLayoutForLineEdit = new QHBoxLayout();
  hLayoutForLineEdit->addStretch(1); // Add a stretchable space on the left side to push everything else to the right
  hLayoutForLineEdit->addWidget(nameLineEdit); // Add the nameLineEdit to the QHBoxLayout
  hLayoutForLineEdit->addStretch(1); // Add a stretchable space on the right side to push everything else to the left
  layout
      ->addLayout(hLayoutForLineEdit); // This adds the QHBoxLayout (which contains your centered nameLineEdit) to the main QVBoxLayout


  layout->addStretch();

  // add shadow effect for the box
  auto *shadowEffect = new QGraphicsDropShadowEffect(welcomeLabel);
  shadowEffect->setBlurRadius(5);
  shadowEffect->setXOffset(5);
  shadowEffect->setYOffset(5);
  shadowEffect->setColor(Qt::black);
  playButton->setGraphicsEffect(shadowEffect);
  welcomeLabel->setGraphicsEffect(shadowEffect);
  playButton->setFixedSize(100, 60);

  // align the box
  // add playButton
  layout->addWidget(playButton);

  // align playbutton
  layout->addStretch();
  layout->setAlignment(playButton, Qt::AlignHCenter);
  layout->setContentsMargins(0, 0, 0, 100); // Adjust top margin
  layout->setSpacing(10);

  // connect the playButton to an action
  connect(playButton, &QPushButton::clicked, this, [this]() {
    QString name = this->nameLineEdit->text().trimmed(); // Get the name from the QLineEdit
    this->hide();
    auto *mainWindow = new MainWindow();
    mainWindow->setAttribute(Qt::WA_DeleteOnClose);
    mainWindow->setName(name);
    mainWindow->show();

    GameService::getInstance().startService();

  });
}

/*
 * addImages() - helper method to add the bitbuddies
 */
void LauncherWindow::addImages() {
  QWidget * imageContainer = new QWidget(this);
  QTimer *timer = new QTimer(this);
  connect(timer, &QTimer::timeout, [imageContainer](){
    static int colorIndex = 0;
    QStringList backgroundColors = {"background-color:#eaaee3", "background-color:#c79dfb", "background-color:#fbfb9d", "background-color:#bbdddd"};
    imageContainer->setStyleSheet(backgroundColors[colorIndex]);

    colorIndex = (colorIndex + 1) % backgroundColors.size();
  });
  timer->start(250);

  imageContainer->setStyleSheet("background-color:#eaaee3");

  /*
   * beige - #d8a38d
   * purple - #c79dfb
   * yellow - #fbfb9d
   * blue - #bbdddd
   * pink - #eaaee3
   */
  imageContainer->setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT); // Adjust as needed

  // Logic for bitbuddies
  int x = 0, y = 0; // Initial position
  int xStep = 100; // Horizontal step size
  int yStep = 100; // Vertical step size
  int numRows = (SCREEN_HEIGHT / yStep) + 2;
  bool moveRight = true; // Direction control
  int count = 0;

  // vector of images
  std::vector<std::string> images =
      {":assets/happy_bitbuddy.png", ":assets/angry_bitbuddy.png", ":assets/mad_bitbuddy.png",
       ":assets/sad_bitbuddy.png", ":assets/sick_bitbuddy.png", ":assets/sick_bitbuddy.png"};

  std::vector<std::string> backgroundColours =
      {"background-color:#eaaee3", "background-color:#c79dfb", "background-color:#fbfb9d", "background-color:#bbdddd"};

  // for loop for image placement
  for (int i = 0; i < numRows; ++i) {
    x = 0;
    for (int j = 0; j < 20; j++) {

      int pos = count % 6;
      QLabel *imageLabel = new QLabel(imageContainer);

      QPixmap pixmap(images[pos].c_str()); // Adjust path accordingly
      imageLabel->setPixmap(pixmap.scaled(QSize(80, 80),
                                          Qt::KeepAspectRatio,
                                          Qt::SmoothTransformation)); // Adjust size as needed
      imageLabel->adjustSize();
      imageLabel->move(x, y);
      x += xStep;
      count++;
    }
    y += yStep;
  }
}

