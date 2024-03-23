//
// Created by Ryan Hecht  on 2024-03-04.
//

#ifndef BITBUDDY_SRC_BITBUDDYATTRIBUTE_H_
#define BITBUDDY_SRC_BITBUDDYATTRIBUTE_H_

#include "model/BitBuddyAttributeName.h"

#include <QJsonObject>

inline constexpr int MAX_ATTRIBUTE_VALUE = 10;

class BitBuddyAttribute {
 public:
  /***
   * Constructor for the BitBuddyAttribute
   *
   * @param attributeName The name of the attribute
   * @param value The value of the attribute between 0 and MAX_ATTRIBUTE_VALUE
   */
  explicit BitBuddyAttribute(BitBuddyAttributeName::UniqueName attributeName, int value = MAX_ATTRIBUTE_VALUE);
  ~BitBuddyAttribute() = default;

  /***
   * Converts the BitBuddyAttribute to a JSON object
   *
   * @return The JSON object representation of the BitBuddyAttribute
   */
  QJsonObject toJson() const;

  /***
   * Converts a JSON object to a BitBuddyAttribute
   *
   * @param json The JSON object to convert
   * @return The BitBuddyAttribute created from the JSON object
   */
  static BitBuddyAttribute fromJson(const QJsonObject &json);

  BitBuddyAttribute(const BitBuddyAttribute &);
  BitBuddyAttribute &operator=(const BitBuddyAttribute &);
  BitBuddyAttribute(BitBuddyAttribute &&) noexcept;
  BitBuddyAttribute &operator=(BitBuddyAttribute &&) noexcept;

  [[nodiscard]] BitBuddyAttributeName::UniqueName getAttributeName() const;

  void setAttributeName(BitBuddyAttributeName::UniqueName attribute_name);

  [[nodiscard]] int getValue() const;

  void incrementValue(int value);

 private:
  BitBuddyAttributeName::UniqueName attributeName;
  int value;
};

#endif //BITBUDDY_SRC_BITBUDDYATTRIBUTE_H_
