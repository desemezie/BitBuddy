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

/**
 * @class SettingsWindow
 * @brief The SettingsWindow class provides a dialog for users to adjust application settings.
 * @author Shaylan Pratt
 *
 * This class offers a GUI for adjusting sound effects volume, music volume, and toggles to enable or disable
 * sound effects and music. It interfaces with the application's settings to persist these preferences.
 */

class SettingsWindow : public QDialog {
 Q_OBJECT

 public:
  /**
    * @brief Construct a new Settings Window object.
    *
    * @param parent The parent widget of this dialog. Default is nullptr.
    */
  explicit SettingsWindow(QWidget *parent = nullptr);

  /**
    * @brief Destroy the Settings Window object.
    *
    * Ensures that resources are cleaned up properly.
    */
  ~SettingsWindow();

 private slots:
  /**
    * @brief Saves the current settings to the application's settings storage.
    */
  void saveSettings();
  /**
    * @brief Slot to handle changes in sound effects volume.
    *
    * @param volume The new volume level for sound effects.
    */
  void soundEffectsVolume(int);
  /**
    * @brief Slot to handle changes in music volume.
    *
    * @param volume The new volume level for music.
    */
  void musicVolume(int);
  /**
    * @brief Slot to handle toggling of sound effects.
    *
    * @param disable True to disable sound effects, false to enable.
    */
  void disableSoundEffects(bool);
  /**
    * @brief Slot to handle toggling of music.
    *
    * @param disable True to disable music, false to enable.
    */
  void disableMusic(bool);

 private:
  QPushButton *save; ///< Button to save the settings.
  QSlider *soundEffectsSlider; ///< Slider to adjust the sound effects volume.
  QSlider *musicSlider; ///< Slider to adjust the music volume.
  QCheckBox *disableSoundEffectsCheckBox; ///< Checkbox to enable/disable sound effects.
  QCheckBox *disableMusicCheckBox; ///< Checkbox to enable/disable music.

  /**
    * @brief Sets up the UI components and connects signals and slots.
    */
  void setup();

};

#endif //BITBUDDY_INCLUDE_SETTINGSWINDOW_H_