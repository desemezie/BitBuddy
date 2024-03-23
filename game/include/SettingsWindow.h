//
// Created by Shaylan Pratt on 2024-03-19.
//

#ifndef BITBUDDY_INCLUDE_SETTINGSWINDOW_H_
#define BITBUDDY_INCLUDE_SETTINGSWINDOW_H_

#include <QWidget>
#include <QPushButton>
#include <QDialog>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QSlider>
#include <QLabel>
#include <QLineEdit>
#include <QLabel>

class SettingsWindow : public QDialog{
 Q_OBJECT

 public:
  explicit SettingsWindow(QWidget *parent = nullptr);
 ~SettingsWindow();

 private slots:
  void saveSettings();
  void cancelSettings();
  void soundEffectsVolume(int);
  void musicVolume(int);
  void disableSoundEffects(bool);
  void disableMusic(bool);

 private:
  QPushButton *save;
  QPushButton *cancel;
  QVBoxLayout *layout;
  QSlider *soundEffectsSlider;
  QSlider *musicSlider;
  QCheckBox *disableSoundEffectsCheckBox;
  QCheckBox *disableMusicCheckBox;

  void setup();




};

#endif //BITBUDDY_INCLUDE_SETTINGSWINDOW_H_
