//
// Created by Ryan Hecht  on 2024-03-04.
//

#ifndef BITBUDDY_EVENTLISTENER_H
#define BITBUDDY_EVENTLISTENER_H

#include "model/Event.h"

/***
 * Interface for classes that want to listen to events
 */
class EventListener {

 public:
  virtual ~EventListener() = default;

  /***
   * Called when an event is dispatched. Implement this method to handle the event.
   * @param event the event
   */
  virtual void onEvent(const Event &event) = 0;

};

#endif //BITBUDDY_EVENTLISTENER_H
