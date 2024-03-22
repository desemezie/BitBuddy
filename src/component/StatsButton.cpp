//
// Created by Shaylan Pratt on 2024-03-22.
//

#include "component/StatsButton.h"
#include "StatsWindow.h"

#include <QIcon>
#include <QApplication>

StatsButton::StatsButton(QWidget *parent) : QPushButton(parent) {
  connect(this, &QPushButton::clicked, this, &StatsButton::statsClicked);
  setImage(":/assets/info.png");
}

void StatsButton::setImage(QString imagePath) {
  QIcon buttonIcon(imagePath);
  this->setIcon(buttonIcon);
  this->setIconSize(buttonIcon.actualSize(QSize(40, 40)));
}

void StatsButton::statsClicked() {
  StatsWindow *window = new StatsWindow();
  window->setAttribute(Qt::WA_DeleteOnClose);
  window->exec();
}

