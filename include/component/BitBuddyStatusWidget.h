//
// Created by Ryan Hecht  on 2024-03-04.
//

#ifndef BITBUDDY_SRC_BITBUDDYSTATUSWIDGET_H_
#define BITBUDDY_SRC_BITBUDDYSTATUSWIDGET_H_

#include "model/BitBuddyAttributeName.h"
#include "model/DeprecatedEventListener.h"
#include "model/BitBuddyAttribute.h"
#include "BitBuddyWidget.h"

#include <QWidget>
#include <QProgressBar>
#include <QMap>
#include <QLabel>
#include <QPair>

/***
 * Widget that displays the status of the BitBuddyWidget's attributes.
 */
class BitBuddyStatusWidget : public QWidget {
 Q_OBJECT

 public:
  /***
   * Constructor for the BitBuddyStatusWidget
   * @param parent The parent widget of the BitBuddyStatusWidget, typically the MainWindow.
   */
  explicit BitBuddyStatusWidget(BitBuddyWidget *bitBuddyWidgetInstance, QWidget *parent = nullptr);

 public slots:
  /**
   * Updates the progress bar for the updated attribute
   *
   * @param attribute The attribute that was updated
   */
  void onAttributeUpdated(const BitBuddyAttribute &attribute);

 private:
  /**
   * Sets the level of the attribute's progress bar
   *
   * @param attributeName The attributeName to set the level for
   * @param level The level to set the attributeName to
   */
  void setAttributeLevel(BitBuddyAttributeName::UniqueName attributeName, int level);

  QMap<BitBuddyAttributeName::UniqueName, QProgressBar *> attributeBars;
};

#endif //BITBUDDY_SRC_BITBUDDYSTATUSWIDGET_H_
