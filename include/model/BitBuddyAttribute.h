//
// Created by Ryan Hecht  on 2024-03-04.
//

#ifndef BITBUDDY_SRC_BITBUDDYATTRIBUTE_H_
#define BITBUDDY_SRC_BITBUDDYATTRIBUTE_H_

#include "model/BitBuddyAttributeName.h"

inline constexpr int MAX_ATTRIBUTE_VALUE = 10;

class BitBuddyAttribute {
 public:
  BitBuddyAttribute(BitBuddyAttributeName::UniqueName attributeName, int value = MAX_ATTRIBUTE_VALUE);
  ~BitBuddyAttribute();

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
