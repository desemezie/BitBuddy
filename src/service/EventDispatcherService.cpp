//
// Created by Ryan Hecht  on 2024-03-04.
//

#include "service/EventDispatcherService.h"

#include <iostream>

EventDispatcherService &EventDispatcherService::getInstance() {
  static EventDispatcherService instance;
  return instance;
}

void EventDispatcherService::registerListener(EventListener *listener) {
  listeners.push_back(listener);
}

void EventDispatcherService::unregisterListener(EventListener *listener) {
  listeners.erase(std::remove(listeners.begin(), listeners.end(), listener), listeners.end());
}

void EventDispatcherService::dispatchEvent(const Event &event) {
  std::cout << "Dispatching event: " << event.getDescription() << std::endl;
  for (auto listener : listeners) {
    listener->onEvent(event);
  }
}
