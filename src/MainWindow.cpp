//
// Created by Ryan Hecht  on 2024-02-25.
//

#include <QApplication>
#include <QGridLayout>
#include "MainWindow.h"
#include "component/BitBuddyStatusWidget.h"
#include "component/BitBuddyWidget.h"
#include "component/BitBuddyActionButton.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  auto *centralWidget = new QWidget(this);
  setCentralWidget(centralWidget);
  resize(1280, 720);

  // Grid layout for the central widget
  auto *layout = new QGridLayout(centralWidget);
  centralWidget->setLayout(layout);

  auto *bitBuddyWidget = new BitBuddyWidget("BitBuddy", this);

  auto *statusWidget = new BitBuddyStatusWidget(bitBuddyWidget, this);

  // Create spacers to push the status widget to the top-left corner
  auto *verticalSpacer = new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

  layout->addWidget(statusWidget, 0, 0, Qt::AlignTop | Qt::AlignLeft);
  layout->addItem(verticalSpacer, 1, 0, 1, 2);

  // Setting button icon
  QIcon buttonIcon("./thumb.png");

  std::string buttonNames[8] = {"feed", "clean", "discipline", "play", "blah", "blah", "blah", "blah "};
  for (int i = 0; i < 8; i++) {
    buttons[i] = new BitBuddyActionButton(buttonIcon, QString::fromStdString(buttonNames[i]), centralWidget);

  }

  QHBoxLayout * rowLayout1 = new QHBoxLayout;
  QHBoxLayout * rowLayout2 = new QHBoxLayout;

  for (int i = 0; i < 4; ++i) {
    rowLayout1->addWidget(buttons[i]);
    rowLayout2->addWidget(buttons[i + 4]);

  }
  rowLayout1->setSpacing(0);
  rowLayout2->setSpacing(0);

  layout->addLayout(rowLayout1, 2, 0, 2, 2);
  layout->addLayout(rowLayout2, 3, 0, 2, 2);

  layout->setAlignment(Qt::AlignBottom);

  layout->setRowMinimumHeight(2, buttons[0]->sizeHint().height());
  layout->setRowMinimumHeight(3, buttons[4]->sizeHint().height());

}

MainWindow::~MainWindow() = default;
