//
// Created by Ryan Hecht  on 2024-03-04.
//

#ifndef BITBUDDY_SRC_BITBUDDYSTATUSWIDGET_H_
#define BITBUDDY_SRC_BITBUDDYSTATUSWIDGET_H_

#include "model/BitBuddyAttribute.h"
#include "model/EventListener.h"

#include <QWidget>
#include <QProgressBar>
#include <QMap>
#include <QLabel>
#include <QPair>

/***
 * Widget that displays the status of the BitBuddy's attributes.
 */
class BitBuddyStatusWidget : public QWidget, public EventListener {
 Q_OBJECT

 public:
  /***
   * Constructor for the BitBuddyStatusWidget
   * @param parent The parent widget of the BitBuddyStatusWidget, typically the MainWindow.
   */
  explicit BitBuddyStatusWidget(QWidget *parent = nullptr);

  void onEvent(const Event &event) override;

 private:
  void setAttributeLevel(BitBuddyAttribute::Attribute attribute, int level);

  QMap<BitBuddyAttribute::Attribute, QProgressBar *> attributeBars;
};

#endif //BITBUDDY_SRC_BITBUDDYSTATUSWIDGET_H_
