//
// Created by Shaylan Pratt on 2024-03-19.
//

#include "SettingsWindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) : QDialog(parent) {
  setup();
}

SettingsWindow::~SettingsWindow() {}

void SettingsWindow::setup(){
  setWindowTitle(tr("Settings"));
  setFixedSize(400, 300);

  QVBoxLayout *layout = new QVBoxLayout(this);

  // Sound effects slider
  layout->addWidget(new QLabel("Sound Effects Volume:"));
  soundEffectsSlider = new QSlider(Qt::Horizontal, this);
  soundEffectsSlider->setRange(0, 100); // Assuming volume range is 0-100
  layout->addWidget(soundEffectsSlider);

  // Checkbox to disable sound effects
  disableSoundEffectsCheckBox = new QCheckBox("Disable Sound Effects", this);
  layout->addWidget(disableSoundEffectsCheckBox);

  // Music volume slider
  layout->addWidget(new QLabel("Music Volume:"));
  musicSlider = new QSlider(Qt::Horizontal, this);
  musicSlider->setRange(0, 100); // Assuming volume range is 0-100
  layout->addWidget(musicSlider);

  // Checkbox to disable music
  disableMusicCheckBox = new QCheckBox("Disable Music", this);
  layout->addWidget(disableMusicCheckBox);

  // Save or cancel
  save = new QPushButton(tr("Save"), this);
  cancel = new QPushButton(tr("Cancel"), this);
  layout->addWidget(save);
  layout->addWidget(cancel);

  connect(soundEffectsSlider, &QSlider::valueChanged, this, &SettingsWindow::soundEffectsVolume);
  connect(musicSlider, &QSlider::valueChanged, this, &SettingsWindow::musicVolume);
  connect(disableSoundEffectsCheckBox, &QCheckBox::toggled, this, &SettingsWindow::disableSoundEffects);
  connect(disableMusicCheckBox, &QCheckBox::toggled, this, &SettingsWindow::disableMusic);
  connect(save, &QPushButton::clicked, this, &SettingsWindow::saveSettings);
  connect(cancel, &QPushButton::clicked, this, &SettingsWindow::cancelSettings);
}

void SettingsWindow::saveSettings() {
  // Implement saving of the settings
  accept(); // Close dialog
}

void SettingsWindow::cancelSettings() {
  reject(); // Close dialog without saving
}

void SettingsWindow::soundEffectsVolume(int value) {

}

void SettingsWindow::musicVolume(int value) {

}

void SettingsWindow::disableSoundEffects(bool checked) {
  soundEffectsSlider->setEnabled(!checked); // Disable slider if sound effects are disabled
}

void SettingsWindow::disableMusic(bool checked) {

  musicSlider->setEnabled(!checked); // Disable slider if music is disabled
}










