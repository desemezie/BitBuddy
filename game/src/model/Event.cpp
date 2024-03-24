//
// Created by Ryan Hecht  on 2024-03-04.
//

#include "model/Event.h"
#include "model/BitBuddyAttributeName.h"

Event::Event(std::string description, double probability)
    : creationTime(std::chrono::system_clock::now()), description(std::move(description)), probability(probability) {
}

std::chrono::system_clock::time_point Event::getCreationTime() const {
  return creationTime;
}

std::string Event::getDescription() const {
  return description;
}
