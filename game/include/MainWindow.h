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

  void setupUi();
  void loadDefaultSprite() const;
  void resizeEvent(QResizeEvent *event) override;

 private slots:
  void openSettings();
  void openShopWindow();
  void updateTheme(const QString &newStyle);

};

#endif  // BITBUDDY_MAINWINDOW_H