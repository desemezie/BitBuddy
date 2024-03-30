//
// Created by Ryan Hecht  on 2024-03-04.
//

#ifndef BITBUDDY_SRC_BITBUDDYSTATUSWIDGET_H_
#define BITBUDDY_SRC_BITBUDDYSTATUSWIDGET_H_

#include <QLabel>
#include <QMap>
#include <QProgressBar>

#include "model/BitBuddy.h"
#include "model/BitBuddyAttribute.h"
#include "model/BitBuddyAttributeName.h"

/**
 * @class BitBuddyStatusWidget
 * @brief The BitBuddyStatusWidget class is a widget that displays the status of the BitBuddy
 * @author Ryan Hecht
 *
 * The BitBuddyStatusWidget class is a widget that displays the status of the BitBuddy. Specifically, it displays the
 * attributes of the BitBuddy along with their current values represented by how much each progress bar associated with
 * the value is filled. For example, an attribute with a value of 2 out of 10 will have 20% of the progress bar filled
 * and an attribute that's completely filled will have a comnpletely filled progress bar.
 */
class BitBuddyStatusWidget final : public QWidget {
  Q_OBJECT

 public:
  /**
   * @brief Constructor for the BitBuddyStatusWidget
   *
   * @param BitBuddyInstance The BitBuddy instance to display the status of
   * @param parent The parent widget of the BitBuddyStatusWidget, typically the MainWindow.
   */
  explicit BitBuddyStatusWidget(const BitBuddy *BitBuddyInstance, QWidget *parent = nullptr);

 public slots:
  /**
   * @brief Updates the progress bar for the updated attribute
   *
   * @param attribute The attribute that was updated
   */
  void onAttributeUpdated(const BitBuddyAttribute &attribute);

  /**
   * @brief Updates the dark mode of the widget
   *
   * @param isDarkMode The dark mode to set the widget to
   */
  void updateDarkMode(bool isDarkMode);

 private:
  /**
   * @brief Sets the level of the attribute's progress bar
   *
   * @param attributeName The attributeName to set the level for
   * @param level The level to set the attributeName to
   */
  void setAttributeLevel(BitBuddyAttributeName::UniqueName attributeName, int level);

  QMap<BitBuddyAttributeName::UniqueName, QProgressBar *> attributeBars;
};

#endif  // BITBUDDY_SRC_BITBUDDYSTATUSWIDGET_H_