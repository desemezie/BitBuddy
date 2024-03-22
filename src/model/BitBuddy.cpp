//
// Created by Ryan Hecht  on 2024-03-04.
//

#include "model/BitBuddy.h"

#include "model/BitBuddyAttributeName.h"
#include "service/EventDispatcherService.h"
#include "model/SingleAttributeEvent.h"

#include <iostream>

BitBuddy::BitBuddy(std::string name)
    : name(std::move(name)), creationTime(std::chrono::system_clock::now()) {
  for (int i = 0; i < NUMBER_OF_ATTRIBUTES; i++) {
    // Constructs a map of the form {HUNGER -> <BitBuddyAttribute> with name HUNGER and value 10}
    attributes.emplace(
        std::piecewise_construct,
        std::forward_as_tuple(static_cast<BitBuddyAttributeName::UniqueName>(i)),
        std::forward_as_tuple(static_cast<BitBuddyAttributeName::UniqueName>(i))
    );
  }

  BitBuddy::connectSignals();
}

// Used for creating the bit buddy when loading from a file
BitBuddy::BitBuddy(std::string name, const std::map<BitBuddyAttributeName::UniqueName,
                                                    BitBuddyAttribute> &attributes,
                   std::chrono::system_clock::time_point creationTime)
    : name(std::move(name)), attributes(attributes), creationTime(creationTime) {
  connectSignals();
}

BitBuddy::~BitBuddy() {
  attributes.clear();
}

void BitBuddy::incrementAttribute(BitBuddyAttributeName::UniqueName attribute, int value) {
  if (!attributes.contains(attribute)) {
    std::cerr << "BitBuddy does not contain the attribute: " << BitBuddyAttributeName::toString(attribute)
              << std::endl;
    return;
  }

  BitBuddyAttribute &attributeToUpdate = attributes.at(attribute);
  attributeToUpdate.incrementValue(value);

  emit attributeUpdated(attributeToUpdate);
}

void BitBuddy::onEvent(const Event &event) {
  const auto *specificEvent = dynamic_cast<const SingleAttributeEvent *>(&event);
  std::cout << "BitBuddy received an event: " << specificEvent->getDescription() << std::endl;
  if (specificEvent) {
    BitBuddyAttributeName::UniqueName attributeKey = specificEvent->getAttribute();
    int increment = specificEvent->getIncrement();

    incrementAttribute(attributeKey, increment);
  }
}

void BitBuddy::connectSignals() const {
  connect(&EventDispatcherService::getInstance(), &EventDispatcherService::eventDispatched,
          this, &BitBuddy::onEvent);
}

int BitBuddy::getAttributeValue(BitBuddyAttributeName::UniqueName attributeName) const {

  auto it = attributes.find(attributeName);
  if (it != attributes.end()) {
    auto value = it->second.getValue();
    std::cout << "Found value: " << value << " for attribute " << BitBuddyAttributeName::toString(attributeName) << "\n";
    return value;
  }
  return -1; // Or some error value
}
