//
// Created by Ryan Hecht  on 2024-02-25.
//

#ifndef BITBUDDY_MAINWINDOW_H
#define BITBUDDY_MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>

#include "component/BitBuddyActionButton.h"
#include "component/BitBuddyStatusWidget.h"
#include "component/LightButton.h"
#include "model/BitBuddyAttributeName.h"
#include "service/BitBuddySpriteHandler.h"

/**
 * The main window of the application
 */
class MainWindow final : public QMainWindow {
  Q_OBJECT

 public:
  /**
   * @brief Constructor of the MainWindow.
   *
   * @param parent The parent widget of the MainWindow, typically the desktop.
   */
  explicit MainWindow(QWidget *parent = nullptr);

  ~MainWindow() override;

  MainWindow(const MainWindow &) = delete;

  MainWindow &operator=(const MainWindow &) = delete;

  MainWindow(MainWindow &&) = delete;

  MainWindow &operator=(MainWindow &&) = delete;

 private:
  QLabel *spriteLabel{};
  BitBuddySpriteHandler *spriteHandler{};
  QPushButton *settingsButton{};
  BitBuddyStatusWidget *bitBuddyStatusWidget{};
  LightButton *lightSwitch{};
  QPushButton *stats{};
  QPushButton *shop{};

  /**
   * @brief Will set up the homepage of the bitbuddy game
   *
   */
  void setupUi();
  /**
   * @brief Sets the default sprite to the happy bitbuddy
   */
  void loadDefaultSprite() const;
  /**
   * @brief resizeEvent will be called when the window is resized
   * @brief Will ensure the position of the bitbuddy and its items are in the correct places
   * @param event resize event is sent in
   */
  void resizeEvent(QResizeEvent *event) override;

 private slots:
  /**
   * @brief Opens the additional windows that are accessible through the mainWindow
   */
  void openSettings();
  void openShopWindow();
  /**
   * @brief Changes the style of the game
   * @param newStyle light or dark
   */
  void updateTheme(const QString &newStyle);

};

#endif  // BITBUDDY_MAINWINDOW_H