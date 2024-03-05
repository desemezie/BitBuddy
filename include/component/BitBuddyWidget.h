//
// Created by Ryan Hecht  on 2024-03-04.
//

#ifndef BITBUDDY_SRC_COMPONENT_BITBUDDY_H_
#define BITBUDDY_SRC_COMPONENT_BITBUDDY_H_

#include <QObject>
#include <QWidget>
#include <map>
#include "model/BitBuddyAttribute.h"
#include "model/Event.h"

/***
 * The main Bit Buddy Widget!
 */
class BitBuddyWidget : public QWidget {
 Q_OBJECT

 public:
  /***
   * Constructor for the BitBuddyWidget. Initializes the attribute maps.
   *
   * @param name The name of the BitBuddyWidget
   * @param parent The parent widget of the BitBuddyWidget, typically the MainWindow.
   */
  explicit BitBuddyWidget(std::string name, QWidget *parent = nullptr);

  /**
   * Destructor for the BitBuddyWidget
   */
  ~BitBuddyWidget() override;

  BitBuddyWidget(const BitBuddyWidget &) = delete;

  BitBuddyWidget &operator=(const BitBuddyWidget &) = delete;

  BitBuddyWidget(BitBuddyWidget &&) = delete;

  BitBuddyWidget &operator=(BitBuddyWidget &&) = delete;

  /***
   * Increments the value of the attribute with the given value
   *
   * @param attribute
   * @param value
   */
  void incrementAttribute(BitBuddyAttributeName::UniqueName attribute, int value);

 signals:
  /***
   * Signal emitted when an attribute is updated
   *
   * @param attribute The attribute that was updated
   */
  void attributeUpdated(const BitBuddyAttribute &attribute);

 public slots:
  /***
   * Slot that listens for Events from the event dispatch service and updates the BitBuddyWidget's attributes.
   *
   * @param event The event to process
   */
  void onEvent(const Event &event);

 private:
  std::map<BitBuddyAttributeName::UniqueName, BitBuddyAttribute> attributes;
  std::chrono::system_clock::time_point creationTime;
  std::string name;

};

#endif //BITBUDDY_SRC_COMPONENT_BITBUDDY_H_
