//
// Created by Ryan Hecht  on 2024-03-04.
//

#include "service/EventDispatcherService.h"

EventDispatcherService &EventDispatcherService::getInstance() {
  static EventDispatcherService instance;
  return instance;
}

void EventDispatcherService::dispatchEvent(const Event *event) {
  emit eventDispatched(*event);
}