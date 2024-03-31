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

      // Add the Button to the array
      buttons.push_back(button);

    }
  }

  // Set the Window layout
  setLayout(gridLayout);
}
// function to change button text ON CALL
void BoardWindow::setButtonText(int index, const QString &text){
  if(index >= 0 && index <= buttons.size()){
    buttons[index]->setText(text);
    buttons[index]->setFont(QFont("Arial", 24, QFont::Bold));
  }
}
//function to change button text ON CLICK
void BoardWindow::changeButtonText() {
  QPushButton *button = qobject_cast<QPushButton*>(sender());
  int index = -1;

  // Find the index of the button which was clicked
  for(int i = 0; i < 9; i++){
    if(button == buttons[i]){
      index = i;
      break;
    }
  }
  //if(button){
  // button ->setText("X");
  //button->setFont(QFont("Arial", 24, QFont::Bold));
  //}

  //Signal + the button that sent it
  emit buttonClicked(index);
}


