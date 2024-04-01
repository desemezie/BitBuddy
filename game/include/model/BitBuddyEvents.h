//
// Created by Ryan Hecht  on 2024-03-04.
//

#ifndef BITBUDDY_SRC_BITBUDDYEVENTS_H_
#define BITBUDDY_SRC_BITBUDDYEVENTS_H_

#include <vector>

#include "model/SingleAttributeEvent.h"

/**
 * @brief The predefined events that the BitBuddy can experience
 */
extern const std::vector<SingleAttributeEvent> PREDEFINED_EVENTS;

/**
 * @class BitBuddyEvents
 * @brief The BitBuddyEvents class is a utility class that provides predefined events that the BitBuddy can experience
 * @author Ryan Hecht
 *
 * This class should never be instantiated. Its sole purpose is to expose a constant that provides a list of predefined
 * events that the BitBuddy can experience.
 */
class BitBuddyEvents final {
 public:
  BitBuddyEvents() = delete;
  ~BitBuddyEvents() = default;
  BitBuddyEvents(const BitBuddyEvents &) = delete;
  BitBuddyEvents &operator=(const BitBuddyEvents &) = delete;
  BitBuddyEvents(BitBuddyEvents &&) = delete;
  BitBuddyEvents &operator=(BitBuddyEvents &&) = delete;
};

#endif  // BITBUDDY_SRC_BITBUDDYEVENTS_H_
