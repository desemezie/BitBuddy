//
// Created by Ryan Hecht  on 2024-03-04.
//

#ifndef BITBUDDY_BITBUDDYATTRIBUTE_H
#define BITBUDDY_BITBUDDYATTRIBUTE_H

#include <string>

inline constexpr int NUMBER_OF_ATTRIBUTES = 7;

/***
 * Class that represents a BitBuddyWidget attribute
 */
class BitBuddyAttributeName {
 public:
  enum UniqueName {
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
  static std::string toString(UniqueName attribute);

    void changeSprite(const std::string &state);
};

#endif //BITBUDDY_BITBUDDYATTRIBUTE_H

