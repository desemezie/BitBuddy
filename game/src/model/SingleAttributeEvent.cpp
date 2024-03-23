//
// Created by Ryan Hecht  on 2024-03-04.
//

#include "model/SingleAttributeEvent.h"

SingleAttributeEvent::SingleAttributeEvent(int increment,
                                           BitBuddyAttributeName::UniqueName attribute,
                                           double probability,
                                           std::string description) :
    Event(std::move(description), probability), increment(increment), attribute(attribute) {
}

int SingleAttributeEvent::getIncrement() const {
  return increment;
}

BitBuddyAttributeName::UniqueName SingleAttributeEvent::getAttribute() const {
  return attribute;
}
