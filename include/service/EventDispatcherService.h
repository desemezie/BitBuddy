//
// Created by Ryan Hecht  on 2024-03-04.
//

#ifndef BITBUDDY_EVENTDISPATCHERSERVICE_H
#define BITBUDDY_EVENTDISPATCHERSERVICE_H

#include "model/Event.h"
#include <QObject>

/***
 * Service that dispatches events to listeners
 */
class EventDispatcherService : public QObject {
 Q_OBJECT

 public:
/***
 * Singleton instance getter
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
  void eventDispatched(const Event &event);

 public slots:
  void dispatchEvent(const Event *event);

 private:
  EventDispatcherService() = default;

  ~EventDispatcherService() = default;

};

#endif //BITBUDDY_EVENTDISPATCHERSERVICE_H
