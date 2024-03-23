//
// Created by Ryan Hecht  on 2024-03-04.
//

#ifndef BITBUDDY_EVENTLISTENER_H
#define BITBUDDY_EVENTLISTENER_H

#include "model/Event.h"

/***
 * @deprecated Use QT's signal/slot pattern instead as it is thread safe with QT.
 * Interface for classes that want to listen to events
 */
class DeprecatedEventListener {

 public:
  [[deprecated]]
  virtual ~DeprecatedEventListener() = default;

  /***
   * Called when an event is dispatched. Implement this method to handle the event.
   * @param event the event
   */
  [[deprecated]]
  virtual void onEvent(const Event &event) = 0;

};

#endif //BITBUDDY_EVENTLISTENER_H
