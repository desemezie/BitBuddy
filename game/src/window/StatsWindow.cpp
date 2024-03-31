//
// Created by Shaylan Pratt on 2024-03-22.
//

#include "../../include/window/StatsWindow.h"
#include "service/BitBuddyService.h"

#include <QVBoxLayout>

StatsWindow::StatsWindow(const QString &thename, QWidget *parent) : QDialog(parent) {
  name = thename;
  setupUi();
}

StatsWindow::~StatsWindow() {
}

void StatsWindow::setupUi() {
  setWindowTitle(tr("BitBuddy Info"));
  setFixedSize(400, 300); // Adjust size as needed

  // Initialize labels
  nameLabel = new QLabel(tr("Name: ") + name, this);
  long age = BitBuddyService::getBitBuddy().getAgeInGameYears();
  ageLabel = new QLabel(tr("Age: ") + QString::number(age), this);


  // Layout to organize labels
  QVBoxLayout *layout = new QVBoxLayout(this);
  layout->addWidget(nameLabel);
  layout->addWidget(ageLabel);

  setLayout(layout);
}