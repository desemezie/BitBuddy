//
// Created by Shaylan Pratt on 2024-03-19.
//

#include "SettingsWindow.h"
#include "service/MusicService.h"

SettingsWindow::SettingsWindow(QWidget *parent) : QDialog(parent) {
  setup();
}

SettingsWindow::~SettingsWindow() {}

void SettingsWindow::setup() {
  QSettings settings("Group17", "BitBuddy");

  setWindowTitle(tr("Settings"));
  setFixedSize(400, 300);

  QVBoxLayout *layout = new QVBoxLayout(this);

  // Sound effects slider
  layout->addWidget(new QLabel("Sound Effects Volume:"));
  soundEffectsSlider = new QSlider(Qt::Horizontal, this);
  soundEffectsSlider->setRange(0, 100); // Assuming volume range is 0-100
  soundEffectsSlider->setValue(50);
  layout->addWidget(soundEffectsSlider);

  // Checkbox to disable sound effects
  disableSoundEffectsCheckBox = new QCheckBox("Disable Sound Effects", this);
  layout->addWidget(disableSoundEffectsCheckBox);

  // Music volume slider
  layout->addWidget(new QLabel("Music Volume:"));
  musicSlider = new QSlider(Qt::Horizontal, this);
  musicSlider->setRange(0, 100); // Assuming volume range is 0-100
  int musicVolume = settings.value("musicVolume", 50).toInt(); // Default to 50 if not set
  musicSlider->setValue(musicVolume);
  layout->addWidget(musicSlider);

  // Checkbox to disable music
  disableMusicCheckBox = new QCheckBox("Disable Music", this);
  bool disableMusic = settings.value("disableMusic", false).toBool();
  disableMusicCheckBox->setChecked(disableMusic);
  musicSlider->setEnabled(!disableMusic);
  layout->addWidget(disableMusicCheckBox);

  // Save or cancel
  save = new QPushButton(tr("Save"), this);
  layout->addWidget(save);


  // Apply the settings
  MusicService &musicService = MusicService::getInstance();
  musicService.setVolume(musicVolume / 100.0f); // Adjust volume if needed
  if (disableMusic) {
    musicService.stopMusic();
  } else {
    musicService.startMusic();
  }

  connect(soundEffectsSlider, &QSlider::valueChanged, this, &SettingsWindow::soundEffectsVolume);
  connect(musicSlider, &QSlider::valueChanged, this, &SettingsWindow::musicVolume);
  connect(disableSoundEffectsCheckBox, &QCheckBox::toggled, this, &SettingsWindow::disableSoundEffects);
  connect(disableMusicCheckBox, &QCheckBox::toggled, this, &SettingsWindow::disableMusic);
  connect(save, &QPushButton::clicked, this, &SettingsWindow::saveSettings);
}

void SettingsWindow::saveSettings() {
  QSettings settings("Group17", "BitBuddy");
  // Save music volume setting
  settings.setValue("musicVolume", musicSlider->value());
  // Save sound effects volume setting
  settings.setValue("soundEffectsVolume", soundEffectsSlider->value());
  // Save whether sound effects are disabled
  settings.setValue("disableSoundEffects", disableSoundEffectsCheckBox->isChecked());
  // Save whether music is disabled
  settings.setValue("disableMusic", disableMusicCheckBox->isChecked());

  accept(); // Close dialog
}

void SettingsWindow::soundEffectsVolume(int value) {

}

void SettingsWindow::musicVolume(int value) {
  MusicService &musicService = MusicService::getInstance();
  float sliderVolume = value / 100.0f;
  musicService.setVolume(sliderVolume);

}

void SettingsWindow::disableSoundEffects(bool checked) {
  soundEffectsSlider->setEnabled(!checked); // Disable slider if sound effects are disabled
}

void SettingsWindow::disableMusic(bool checked) {
  MusicService &musicService = MusicService::getInstance();
  if (checked) {
    musicService.stopMusic();
  } else {
    musicService.startMusic();
  }
  musicSlider->setEnabled(!checked); // Disable slider if music is disabled
}
