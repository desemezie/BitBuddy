//
// Created by razvan on 31/03/24.
//
#include "window/BoardWindow.h"

// window constructor
BoardWindow::BoardWindow(QWidget *parent) : QWidget(parent) {
  // Window creation
  setWindowTitle("Bitbuddy Game Board");
  // Window sizing
  resize(400, 400);
  // Stylesheet
  setStyleSheet("background-color: white;");
  // Create grid layout
  gridLayout = new QGridLayout(this);
  // Create 9 buttons and add them to the layout
  for(int row = 0; row < 3; row++){
    for(int col = 0; col < 3; col++){
      // Button Object
      QPushButton *button = new QPushButton(QString("").arg(row).arg(col));
      // Expand to fill all space
      button->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
      gridLayout->addWidget(button, row, col);

      // Connect the button signal to the changeletter method
      connect(button, &QPushButton::clicked, this, &BoardWindow::changeButtonText);
    }
  }

  // Set the Window layout
  setLayout(gridLayout);

}

//function to change button text
void BoardWindow::changeButtonText() {
  QPushButton *button = qobject_cast<QPushButton*>(sender());
  if(button){
    button ->setText("X");
    button->setFont(QFont("Arial", 24, QFont::Bold));
  }
}


