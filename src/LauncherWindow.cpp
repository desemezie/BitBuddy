//
// Created by Annabel Irani on 2024-03-10.
//

#include <QVBoxLayout>
#include "LauncherWindow.h"
#include "MainWindow.h"
#include "service/GameService.h"
#include <QApplication>

LauncherWindow::LauncherWindow(QWidget *parent) : QWidget(parent) {
  auto *layout = new QVBoxLayout(this);
  auto *welcomeLabel = new QLabel("Welcome to Bit Buddy!", this);
  welcomeLabel->setAlignment(Qt::AlignCenter); // Center the welcome message
  layout->addWidget(welcomeLabel); // Add the label to the layout

  auto *playButton = new QPushButton("Play", this);
  layout->addWidget(playButton); // Add the button to the layout

  connect(playButton, &QPushButton::clicked, this, [this]() {
    this->hide();
    auto *mainWindow = new MainWindow();
    mainWindow->setAttribute(Qt::WA_DeleteOnClose);
    mainWindow->show();

    GameService::getInstance().startService();

    //return QApplication::exec();
  });
}