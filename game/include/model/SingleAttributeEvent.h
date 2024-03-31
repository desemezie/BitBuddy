//
// Created by Ryan Hecht  on 2024-03-04.
//

#ifndef BITBUDDY_SINGLEATTRIBUTEEVENT_H
#define BITBUDDY_SINGLEATTRIBUTEEVENT_H

#include "BitBuddyAttributeName.h"
#include "model/Event.h"

/**
 * @class SingleAttributeEvent
 * @brief The SingleAttributeEvent class represents an event that modifies a single attribute of the BitBuddy
 * @author Ryan Hecht
 *
 * SingleAttributeEvent is a subclass of Event that represents an event that modifies a single attribute of the
 * BitBuddy. The event has an increment, an attribute, a probability, and a description.
 */
class SingleAttributeEvent final : public Event {
 public:
  /**
   * @brief Constructor for a single attribute event.
   *
   * @param increment The increment of the event, can be positive or negative.
   * @param attribute The attribute of the event from the BitBuddyAttributeName::UniqueName enum.
   * @param probability The probability of the event occurring between 0.0 and 1.0.
   * @param description The description of the event.
   */
  SingleAttributeEvent(int increment, BitBuddyAttributeName::UniqueName attribute, double probability = 1.0,
                       std::string description = "Single attribute event.");

  /**
   * @brief Destructor for the SingleAttributeEvent.
   */
  ~SingleAttributeEvent() override = default;

  /**
   * @brief Copy constructor for the SingleAttributeEvent.
   * @details The default copy constructor is used because our explicit definition would be the same.
   */
  SingleAttributeEvent(const SingleAttributeEvent &) = default;

  /**
   * @brief Copy assignment operator for the SingleAttributeEvent.
   * @details The default copy assignment operator is used because our explicit definition would be the same.
   */
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
  int increment;  // positive or negative
  BitBuddyAttributeName::UniqueName attribute;
};

#endif  // BITBUDDY_SINGLEATTRIBUTEEVENT_H
