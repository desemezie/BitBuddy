//
// Created by Ryan Hecht  on 2024-03-04.
//

#ifndef BITBUDDY_SINGLEATTRIBUTEEVENT_H
#define BITBUDDY_SINGLEATTRIBUTEEVENT_H

#include "model/Event.h"
#include "BitBuddyAttributeName.h"

/**
 * Class that represents a single attribute event.
 */
class SingleAttributeEvent : public Event {

 public:
  /**
   * Constructor for a single attribute event.
   *
   * @param increment The increment of the event, can be positive or negative.
   * @param attribute The attribute of the event from the BitBuddyAttributeName::UniqueName enum.
   * @param probability The probability of the event occurring between 0.0 and 1.0.
   * @param description The description of the event.
   */
  SingleAttributeEvent(int increment,
                       BitBuddyAttributeName::UniqueName attribute,
                       double probability = 1.0,
                       std::string description = "Single attribute event.");

  ~SingleAttributeEvent() = default;

  SingleAttributeEvent(const SingleAttributeEvent &) = default;

  SingleAttributeEvent &operator=(const SingleAttributeEvent &) = default;

  SingleAttributeEvent(SingleAttributeEvent &&) = delete;

  SingleAttributeEvent &operator=(SingleAttributeEvent &&) = delete;

  /**
   * Returns the increment of the event.
   *
   * @return The increment as an int.
   */
  [[nodiscard]] int getIncrement() const;

  /**
   * Returns the attribute of the event.
   *
   * @return The attribute as a BitBuddyAttributeName::UniqueName.
   */
  [[nodiscard]] BitBuddyAttributeName::UniqueName getAttribute() const;

 private:
  int increment; // positive or negative
  BitBuddyAttributeName::UniqueName attribute;

};

#endif //BITBUDDY_SINGLEATTRIBUTEEVENT_H
