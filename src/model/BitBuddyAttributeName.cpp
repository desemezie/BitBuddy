//
// Created by Ryan Hecht  on 2024-03-04.
//

#include "model/BitBuddyAttributeName.h"
#include <string>
std::string BitBuddyAttributeName::toString(UniqueName attribute) {
  switch (attribute) {
    case HUNGER: return "Hunger";
    case HAPPINESS: return "Happiness";
    case THIRST: return "Thirst";
    case HEALTH: return "Health";
    case TIREDNESS: return "Tiredness";
    case BOREDOM: return "Boredom";
    case HYGIENE: return "Hygiene";
    default: return "Unknown";
  }
}