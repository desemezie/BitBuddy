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
std::string BitBuddyAttributeName::imageURL(UniqueName attribute) {
  switch (attribute) {
    case HUNGER: return ":/assets/angry_bitbuddy.png";
    case HAPPINESS: return ":/assets/sad_bitbuddy.png";
    case THIRST: return ":/assets/sad_bitbuddy.png";
    case HEALTH: return ":/assets/sick_bitbuddy.png";
    case TIREDNESS: return ":/assets/mad_bitbuddy.png";
    case BOREDOM: return ":/assets/sad_bitbuddy.png";
    case HYGIENE: return ":/assets/angry_bitbuddy.png";
    default: return ":/assets/happy_bitbuddy.png";
  }
}
int BitBuddyAttributeName::valueWhereChange(UniqueName attribute){
  switch (attribute) {
    case HUNGER: return 7;
    case HAPPINESS: return 6;
    case THIRST: return 5;
    case HEALTH: return 8;
    case TIREDNESS: return 6;
    case BOREDOM: return 6;
    case HYGIENE: return 4;
    default: return 0;
  }
}