//
// Created by Ryan Hecht  on 2024-03-04.
//

#ifndef BITBUDDY_BITBUDDYATTRIBUTE_H
#define BITBUDDY_BITBUDDYATTRIBUTE_H

#include <string>

/***
 * Class that represents a BitBuddy attribute
 */
class BitBuddyAttribute {
 public:
  enum Attribute {
    HUNGER,
    HAPPINESS,
    THIRST,
    HEALTH,
    TIREDNESS,
    BOREDOM,
    HYGIENE
  };

  /***
   * Converts an attribute to a string
   * @param attribute the attribute to convert
   * @return the string representation of the attribute
   */
  static std::string toString(Attribute attribute);
};

#endif //BITBUDDY_BITBUDDYATTRIBUTE_H

