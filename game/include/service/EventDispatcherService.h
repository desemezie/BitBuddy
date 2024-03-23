//
// Created by Ryan Hecht  on 2024-03-04.
//

#ifndef BITBUDDY_EVENTDISPATCHERSERVICE_H
#define BITBUDDY_EVENTDISPATCHERSERVICE_H

#include "model/Event.h"
#include <QObject>

/**
 * Service that dispatches events to listeners
 */
class EventDispatcherService : public QObject {
 Q_OBJECT

 public:
/**
 * Singleton instance getter
 *
 * @return the instance
 */
  static EventDispatcherService &getInstance();

  EventDispatcherService(const EventDispatcherService &) = delete;

  EventDispatcherService &operator=(const EventDispatcherService &) = delete;

  EventDispatcherService(EventDispatcherService
                         &&) = delete;

  EventDispatcherService &operator=(EventDispatcherService &&)
  = delete;

 signals:
  /**
   * Signal emitted when an event is dispatched
   *
   * @param event The event that was dispatched
   */
  void eventDispatched(const Event &event);

 public slots:
  /**
   * Slot that dispatches the event passed as an argumetn to all listeners. Use this if you want to send an event to
   * BitBuddy and any other listeners.
   *
   * @param event The event to dispatch to all listeners
   */
  void dispatchEvent(const Event *event);

 private:
  EventDispatcherService() = default;

  ~EventDispatcherService() override = default;

};

#endif //BITBUDDY_EVENTDISPATCHERSERVICE_H
