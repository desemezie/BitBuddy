//
// Created by Ryan Hecht  on 2024-03-04.
//

#ifndef BITBUDDY_SRC_BITBUDDYATTRIBUTE_H_
#define BITBUDDY_SRC_BITBUDDYATTRIBUTE_H_

#include <QJsonObject>

#include "model/BitBuddyAttributeName.h"

inline constexpr int MAX_ATTRIBUTE_VALUE = 10;

/**
 * @class BitBuddyAttribute
 * @brief The BitBuddyAttribute class represents an attribute of the BitBuddy
 * @author Ryan Hecht
 *
 * The BitBuddyAttribute class represents an attribute of the BitBuddy. Each attribute has a name of type
 * BitBuddyAttributeName::UniqueName (where UniqueName is an enum value in the BitBuddyAttributeName class) and a value
 * between 0 and MAX_ATTRIBUTE_VALUE (10 at the time of writing this comment).
 */
class BitBuddyAttribute final {
 public:
  /**
   * Constructor for the BitBuddyAttribute
   *
   * @param attributeName The name of the attribute
   * @param value The value of the attribute between 0 and MAX_ATTRIBUTE_VALUE
   */
  explicit BitBuddyAttribute(BitBuddyAttributeName::UniqueName attributeName, int value = MAX_ATTRIBUTE_VALUE);

  ~BitBuddyAttribute() = default;

  /**
   * @brief Converts the BitBuddyAttribute to a JSON object
   *
   * @return The JSON object representation of the BitBuddyAttribute
   */
  [[nodiscard]] QJsonObject toJson() const;

  /**
   * @brief Converts a JSON object to a BitBuddyAttribute
   *
   * @param json The JSON object to convert
   * @return The BitBuddyAttribute created from the JSON object
   */
  static BitBuddyAttribute fromJson(const QJsonObject &json);

  BitBuddyAttribute(const BitBuddyAttribute &);
  BitBuddyAttribute &operator=(const BitBuddyAttribute &);
  BitBuddyAttribute(BitBuddyAttribute &&) noexcept;
  BitBuddyAttribute &operator=(BitBuddyAttribute &&) noexcept;

  /**
   * @brief Gets the name of the attribute
   *
   * @return The name of the attribute as a BitBuddyAttributeName::UniqueName enum value
   */
  [[nodiscard]] BitBuddyAttributeName::UniqueName getAttributeName() const;

  /**
   * @brief Sets the name of the attribute
   *
   * @param attribute_name The name of the attribute
   */
  void setAttributeName(BitBuddyAttributeName::UniqueName attribute_name);

  /**
   * @brief Gets the value of the attribute
   *
   * @return The value of the attribute
   */
  [[nodiscard]] int getValue() const;

  /**
   * @brief Increments the current value of the attribute by the given value
   * @details Increments the current value of the attribute by the given value. For example, if the current value of the
   * attribute is 7 and the passed parameter is 5, the new value of the attribute will be 7 + 5 = 12 capped at
   * MAX_ATTRIBUTE_VALUE. If MAX_ATTRIBUTE_VALUE is 10 for instance, then the new value of the attribute will be 10.
   *
   * @param value The value to increment the attribute by
   */
  void incrementValue(int value);

 private:
  BitBuddyAttributeName::UniqueName attributeName;
  int value;
};

#endif  // BITBUDDY_SRC_BITBUDDYATTRIBUTE_H_
