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

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  auto *centralWidget = new QWidget(this);
  setCentralWidget(centralWidget);
  resize(1280, 720);

  // Grid layout for the central widget
  auto *layout = new QGridLayout(centralWidget);
  centralWidget->setLayout(layout);

  auto *bitBuddyWidget = new BitBuddy("BitBuddy", this);

  auto *statusWidget = new BitBuddyStatusWidget(bitBuddyWidget, this);

  // Create spacers to push the status widget to the top-left corner
  auto *verticalSpacer = new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

  layout->addWidget(statusWidget, 0, 0, Qt::AlignTop | Qt::AlignLeft);
  layout->addItem(verticalSpacer, 1, 0, 1, 2);

  // Setting button icon
  QIcon buttonIcon("./thumb.png");

  QHBoxLayout *rowLayout1 = new QHBoxLayout;
  QHBoxLayout *rowLayout2 = new QHBoxLayout;

  std::string buttonNames[8] = {"feed", "clean", "discipline", "play", "blah", "blah", "blah", "blah "};
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

  layout->addLayout(rowLayout1, 2, 0, 2, 2);
  layout->addLayout(rowLayout2, 3, 0, 2, 2);

  layout->setAlignment(Qt::AlignBottom);

}

MainWindow::~MainWindow() = default;
