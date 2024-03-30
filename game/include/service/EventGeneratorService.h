//
// Created by Ryan Hecht  on 2024-03-04.
//

#ifndef BITBUDDY_EVENTGENERATORSERVICE_H
#define BITBUDDY_EVENTGENERATORSERVICE_H

#include <atomic>
#include <thread>

#include "service/EventDispatcherService.h"

/**
 * @class EventGeneratorService
 * @brief The EventGeneratorService is responsible for generating events at random time intervals.
 * @author Ryan Hecht
 *
 * The EventGeneratorService is a singleton service that generates events at random time intervals and sends them to the
 * EventDispatcherService to be dispatched to BitBuddy and throughout the entire application.
 */
class EventGeneratorService final {
 public:
  /**
   * @brief Singleton instance getter
   *
   * @return the instance
   */
  static EventGeneratorService &getInstance();

  EventGeneratorService(const EventGeneratorService &) = delete;
  EventGeneratorService &operator=(const EventGeneratorService &) = delete;
  EventGeneratorService(EventGeneratorService &&) = delete;
  EventGeneratorService &operator=(EventGeneratorService &&) = delete;

  /**
   * @brief Starts the event generation service
   *
   * @details Starts the event generation service which generates events on its own thread at normally distributed
   * random time intervals
   */
  void startService();

  /**
   * @brief Stops (pauses) the event generation service
   */
  void stopService();

 private:
  /**
   * @brief EventGeneratorService constructor
   */
  EventGeneratorService() = default;

  /**
   * @brief EventGeneratorService destructor
   */
  ~EventGeneratorService();

  /**
   * @brief Resumes the event generation service if it's already been started and is currently paused
   */
  void resumeService();

  /**
   * @brief Generates a random event from the PREDEFINED_EVENTS list and passes it to the EventDispatcherService to be
   * dispatched
   * @details Generates random events at normally distributed random time intervals using mt19937 random number
   * generators
   */
  static void generateEvent();

  std::thread eventGeneratorServiceThread;
  std::atomic<bool> running{false};
  std::atomic<bool> paused{false};
  std::mutex pauseMutex;
  std::condition_variable pauseCondition;
};

#endif  // BITBUDDY_EVENTGENERATORSERVICE_H
