//
// Created by Ryan Hecht  on 2024-03-04.
//

#ifndef BITBUDDY_EVENTDISPATCHERSERVICE_H
#define BITBUDDY_EVENTDISPATCHERSERVICE_H

#include "model/Event.h"
#include "model/EventListener.h"
#include <queue>

/***
 * Service that dispatches events to listeners
 */
class EventDispatcherService {

 public:
  /***
   * Singleton instance getter
   * @return the instance
   */
  static EventDispatcherService &getInstance();

  EventDispatcherService(const EventDispatcherService &) = delete;

  EventDispatcherService &operator=(const EventDispatcherService &) = delete;

  EventDispatcherService(EventDispatcherService &&) = delete;

  EventDispatcherService &operator=(EventDispatcherService &&) = delete;

  /***
   * Register a listener to receive events
   * @param listener the listener
   */
  void registerListener(EventListener *listener);

  /***
   * Unregister a listener to stop receiving events
   * @param listener the listener
   */
  void unregisterListener(EventListener *listener);

  /***
   * Dispatch an event to all listeners
   * @param event the event
   */
  void dispatchEvent(const Event &event);

 private:
  EventDispatcherService() = default;

  ~EventDispatcherService() = default;

  std::vector<EventListener *> listeners;

};

#endif //BITBUDDY_EVENTDISPATCHERSERVICE_H
