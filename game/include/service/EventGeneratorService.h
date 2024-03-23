//
// Created by Ryan Hecht  on 2024-03-04.
//

#ifndef BITBUDDY_EVENTGENERATORSERVICE_H
#define BITBUDDY_EVENTGENERATORSERVICE_H

#include "service/EventDispatcherService.h"

#include <thread>
#include <atomic>

/***
 * Service that generates events on its own thread
 */
class EventGeneratorService {
 public:
  /***
   * Singleton instance getter
   * @return the instance
   */
  static EventGeneratorService &getInstance();

  EventGeneratorService(const EventGeneratorService &) = delete;

  EventGeneratorService &operator=(const EventGeneratorService &) = delete;

  EventGeneratorService(EventGeneratorService &&) = delete;

  EventGeneratorService &operator=(EventGeneratorService &&) = delete;

  /***
   * Starts the event generation service which generates events on its own thread at normally distributed random time
   * intervals
   */
  void startService();

  /***
   * Stops (pauses) the event generation service
   */
  void stopService();

 private:
  EventGeneratorService() = default;

  ~EventGeneratorService();

  /***
   * Resumes the event generation service if it's already been started and is currently paused
   */
  void resumeService();

  /***
   * Generates a random event from the PREDEFINED_EVENTS list and passes it to the EventDispatcherService to be dispatched
   */
  static void generateEvent();

  std::thread eventGeneratorServiceThread;
  std::atomic<bool> running{false};
  std::atomic<bool> paused{false};
  std::mutex pauseMutex;
  std::condition_variable pauseCondition;
};

#endif //BITBUDDY_EVENTGENERATORSERVICE_H
