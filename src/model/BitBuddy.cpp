//
// Created by Ryan Hecht  on 2024-03-04.
//

#include "model/BitBuddy.h"

#include "model/BitBuddyAttributeName.h"
#include "service/EventDispatcherService.h"
#include "model/SingleAttributeEvent.h"

#include <iostream>
#include <QFile>
#include <QTextStream>

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

QJsonObject BitBuddy::toJson() const {
  QJsonObject obj;
  obj["name"] = QString::fromStdString(name);
  obj["creationTime"] = QString::number(creationTime.time_since_epoch().count());

  QJsonObject attributesObj;
  for (const auto &attribute : attributes) {
    attributesObj[QString::number(attribute.first)] =
        attribute.second.toJson(); // You'll need to implement toJson for BitBuddyAttribute as well
  }
  obj["attributes"] = attributesObj;

  return obj;
}

BitBuddy BitBuddy::fromJson(const QJsonObject &obj) {
  std::string name = obj["name"].toString().toStdString();
  auto creationTime =
      std::chrono::system_clock::time_point(std::chrono::system_clock::duration(obj["creationTime"].toString()
                                                                                    .toLongLong()));

  std::map<BitBuddyAttributeName::UniqueName, BitBuddyAttribute> attributes;
  QJsonObject attributesObj = obj["attributes"].toObject();
  for (auto it = attributesObj.begin(); it != attributesObj.end(); ++it) {
    attributes[static_cast<BitBuddyAttributeName::UniqueName>(it.key().toInt())] =
        BitBuddyAttribute::fromJson(it.value().toObject()); // Implement fromJson for BitBuddyAttribute
  }

  return BitBuddy(name, attributes, creationTime);
}

int BitBuddy::getAttributeValue(BitBuddyAttributeName::UniqueName attributeName) const {

  auto it = attributes.find(attributeName);
  if (it == attributes.end()) {
    std::cerr << "BitBuddy does not contain the attribute: " << BitBuddyAttributeName::toString(attributeName)
              << std::endl;
    return -1;
  }

  auto value = it->second.getValue();
  return value;
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

long BitBuddy::getAgeInGameYears() const {
  auto currentTime = std::chrono::system_clock::now();
  long ageInGameYearUnits = std::chrono::duration_cast<std::chrono::minutes>(currentTime - creationTime).count();
  long ageInGameYears = ageInGameYearUnits / IN_GAME_YEAR_LENGTH_IN_MINUTES;

  return ageInGameYears;
}

void BitBuddy::onEvent(const Event &event) {
  const auto *specificEvent = dynamic_cast<const SingleAttributeEvent *>(&event);
  BitBuddyAttributeName::UniqueName attributeKey = specificEvent->getAttribute();
  int increment = specificEvent->getIncrement();
  incrementAttribute(attributeKey, increment);
}

void BitBuddy::connectSignals() const {
  connect(&EventDispatcherService::getInstance(), &EventDispatcherService::eventDispatched,
          this, &BitBuddy::onEvent);
}
