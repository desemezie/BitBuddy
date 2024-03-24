//
// Created by Shaylan Pratt on 2024-03-19.
//

#ifndef BITBUDDY_INCLUDE_SETTINGSWINDOW_H_
#define BITBUDDY_INCLUDE_SETTINGSWINDOW_H_

#include <QCheckBox>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSettings>
#include <QSlider>
#include <QVBoxLayout>
#include <QWidget>

#include "../service/MusicService.h"

class SettingsWindow : public QDialog {
 Q_OBJECT

 public:
  explicit SettingsWindow(QWidget *parent = nullptr);
  ~SettingsWindow();

 private slots:
  void saveSettings();
  void soundEffectsVolume(int);
  void musicVolume(int);
  void disableSoundEffects(bool);
  void disableMusic(bool);

 private:
  QPushButton *save;
  QSlider *soundEffectsSlider;
  QSlider *musicSlider;
  QCheckBox *disableSoundEffectsCheckBox;
  QCheckBox *disableMusicCheckBox;

  void setup();

};

#endif //BITBUDDY_INCLUDE_SETTINGSWINDOW_H_