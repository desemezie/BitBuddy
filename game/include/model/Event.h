//
// Created by Ryan Hecht  on 2024-03-04.
//

#ifndef BITBUDDY_EVENT_H
#define BITBUDDY_EVENT_H

#include <ctime>
#include <chrono>
#include <string>

/**
 * Represents an event with a description and a timestamp.
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

  virtual ~Event() = default; // virtual to force Event to be polymorphic

  Event(const Event &) = default;

  Event &operator=(const Event &) = default;

  Event(Event &&) = delete;

  Event &operator=(Event &&) = delete;

  /**
   * Returns the creation time of the event.
   *
   * @return The creation time as a std::chrono::system_clock::time_point.
   */
  [[nodiscard]] std::chrono::system_clock::time_point getCreationTime() const;

  /**
   * Returns the description of the event.
   *
   * @return The description as a std::string.
   */
  [[nodiscard]] std::string getDescription() const;

  /**
   * Returns the probability of the event.
   *
   * @return The probability as a double.
   */
  [[nodiscard]] double getProbability() const {
    return probability;
  }

 protected:
  std::chrono::system_clock::time_point creationTime;
  std::string description;
  double probability;
};

#endif //BITBUDDY_EVENT_H
