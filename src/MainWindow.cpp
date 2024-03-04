//
// Created by Ryan Hecht  on 2024-02-25.
//

#include <QApplication>
#include <QGridLayout>
#include "MainWindow.h"
#include "component/BitBuddyStatusWidget.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  auto *centralWidget = new QWidget(this);
  setCentralWidget(centralWidget);
  resize(1280, 720);

  // Grid layout for the central widget
  auto *layout = new QGridLayout(centralWidget);
  centralWidget->setLayout(layout);

  auto *statusWidget = new BitBuddyStatusWidget(this);

  // Create spacers to push the status widget to the top-left corner
  auto *verticalSpacer = new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

  layout->addWidget(statusWidget, 0, 0, Qt::AlignTop | Qt::AlignLeft);
  layout->addItem(verticalSpacer, 1, 0, 1, 2);
}

MainWindow::~MainWindow() = default;
