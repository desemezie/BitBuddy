//
// Created by Shaylan Pratt on 2024-03-22.
//

#include "StatsWindow.h"
#include <QVBoxLayout>

StatsWindow::StatsWindow(const QString &thename, QWidget *parent) : QDialog(parent) {
  name = thename;
  setupUi();
}

StatsWindow::~StatsWindow() {}

void StatsWindow::setupUi() {
  setWindowTitle(tr("BitBuddy Info"));
  setFixedSize(400, 300); // Adjust size as needed

  // Initialize labels
  nameLabel = new QLabel(tr("Name: ") + name, this);
  ageLabel = new QLabel(tr("Age: 1"), this);

  // Layout to organize labels
  QVBoxLayout *layout = new QVBoxLayout(this);
  layout->addWidget(nameLabel);
  layout->addWidget(ageLabel);

  setLayout(layout);
}


