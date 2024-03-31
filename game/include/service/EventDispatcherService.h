//
// Created by Ryan Hecht  on 2024-03-04.
//

#ifndef BITBUDDY_EVENTDISPATCHERSERVICE_H
#define BITBUDDY_EVENTDISPATCHERSERVICE_H

#include <QObject>
//raz added
#include <condition_variable>
#include "model/Event.h"

/**
 * @class EventDispatcherService
 * @brief The EventDispatcherService is responsible for dispatching events to all listeners
 * @author Ryan Hecht
 *
 * The EventDispatcherService is a singleton service that dispatches events to all listeners. It is used to send events
 * to BitBuddy and any other listeners.
 */
class EventDispatcherService final : public QObject {
  Q_OBJECT

 public:
  /**
   * @brief Singleton instance getter
   *
   * @return the instance
   */
  static EventDispatcherService &getInstance();

  EventDispatcherService(const EventDispatcherService &) = delete;
  EventDispatcherService &operator=(const EventDispatcherService &) = delete;
  EventDispatcherService(EventDispatcherService &&) = delete;
  EventDispatcherService &operator=(EventDispatcherService &&) = delete;

 signals:
  /**
   * @brief Signal emitted when an event is dispatched
   *
   * @param event The event that was dispatched
   */
  void eventDispatched(const Event &event);

 public slots:
  /**
   * @brief Slot that dispatches the event passed as an argumetn to all listeners.
   *
   * @param event The event to dispatch to all listeners
   *
   * @details Use this if you want to send an event to BitBuddy and any other listeners.
   */
  void dispatchEvent(const Event *event);

 private:
  EventDispatcherService() = default;

  ~EventDispatcherService() override = default;
};

#endif  // BITBUDDY_EVENTDISPATCHERSERVICE_H
