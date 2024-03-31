//
// Created by Ryan Hecht  on 2024-03-04.
//

#ifndef BITBUDDY_BITBUDDYATTRIBUTE_H
#define BITBUDDY_BITBUDDYATTRIBUTE_H

#include <string>

inline constexpr int NUMBER_OF_ATTRIBUTES = 7;

/**
 * @class BitBuddyAttributeName
 * @brief Container class that holds data surrounding the name of a BitBuddy attribute
 * @authors Ryan Hecht, Annabel Irani
 *
 * Contains a UniqueName enum that represents the unique names of the BitBuddy attributes. Also features static methods
 * to transform these names into string representations and to retrieve their corresponding images.
 */
class BitBuddyAttributeName final {
 public:
  /**
   * @enum UniqueName
   * @brief Enum that represents the unique names of the BitBuddy attributes
   */
  enum UniqueName { FIRST = 0, HUNGER = FIRST, HAPPINESS, THIRST, HEALTH, TIREDNESS, BOREDOM, HYGIENE, LAST = HYGIENE };

  /**
   * @brief Converts an attribute to a string
   *
   * @param attribute the attribute to convert
   * @return the string representation of the attribute
   */
  static std::string toString(UniqueName attribute);

  /**
   * @brief Gets the image URL for the attribute
   *
   * @param attribute the attribute to get the image URL for
   * @return the image URL for the attribute
   */
  static std::string imageURL(UniqueName attribute);

  static int valueWhereChange(UniqueName attribute);
};

#endif  // BITBUDDY_BITBUDDYATTRIBUTE_H
