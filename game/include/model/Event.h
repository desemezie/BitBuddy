//
// Created by Ryan Hecht  on 2024-03-04.
//

#ifndef BITBUDDY_EVENT_H
#define BITBUDDY_EVENT_H

#include <chrono>
#include <ctime>
#include <string>

/**
 * @class Event
 * @brief The Event class represents an event that can be dispatched to listeners
 * @author Ryan Hecht
 *
 * The Event class represents an event that can be dispatched to listeners. Each event has a description and a creation
 * time. Events are generally not meant to be constructed themselves as they do not provide much use. Instead,
 * subclasses of Event are usually used.
 */
class Event {
 public:
  /**
   * Constructs an Event with the given description.
   * The creation time is set to the current system time.
   *
   * @param description The event's description.
   * @param probability The event's probability.
   */
  explicit Event(std::string description = "", double probability = 1.0);

  /**
   * @brief Destructor for the Event
   * @details The destructor is made virtual to force Event to be polymorphic
   */
  virtual ~Event() = default;

  /**
   * @brief Copy constructor for the Event.
   * @details the default copy constructor is used because our explicit definition would be the same.
   *
   * @param event The Event to copy
   */
  Event(const Event &) = default;
  Event &operator=(const Event &) = default;
  Event(Event &&) = delete;
  Event &operator=(Event &&) = delete;

  /**
   * @brief Returns the creation time of the event.
   *
   * @return The creation time as a std::chrono::system_clock::time_point.
   */
  [[nodiscard]] std::chrono::system_clock::time_point getCreationTime() const;

  /**
   * @brief Returns the description of the event.
   *
   * @return The description as a std::string.
   */
  [[nodiscard]] std::string getDescription() const;

  /**
   * @brief Returns the probability of the event.
   *
   * @return The probability as a double.
   */
  [[nodiscard]] double getProbability() const { return probability; }

 protected:
  std::chrono::system_clock::time_point creationTime;
  std::string description;
  double probability;
};

#endif  // BITBUDDY_EVENT_H
