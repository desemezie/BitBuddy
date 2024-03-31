//
// Created by Ryan Hecht  on 2024-03-04.
//

#include "model/BitBuddy.h"

#include <QFile>
#include <QJsonObject>
#include <QTextStream>
#include <iostream>

#include "model/BitBuddyAttributeName.h"
#include "model/SingleAttributeEvent.h"
#include "service/EventDispatcherService.h"

BitBuddy::BitBuddy(std::string name)
    : name(std::move(name)),
      creationTime(std::chrono::system_clock::now()),
      dead(false),
      id(QUuid::createUuid()),
      bitBuckGenerator(new BitBuckGenerator()) {
  currentSprite = ":/assets/happy_bitbuddy.png";
  for (int i = 0; i < NUMBER_OF_ATTRIBUTES; i++) {
    // Constructs a map of the form {HUNGER -> <BitBuddyAttribute> with name HUNGER and value 10}
    attributes.emplace(std::piecewise_construct,
                       std::forward_as_tuple(static_cast<BitBuddyAttributeName::UniqueName>(i)),
                       std::forward_as_tuple(static_cast<BitBuddyAttributeName::UniqueName>(i)));
  }

  connectSignals();
}

BitBuddy::BitBuddy(std::string name, const std::map<BitBuddyAttributeName::UniqueName, BitBuddyAttribute> &attributes,
                   std::chrono::system_clock::time_point creationTime, bool dead, QUuid id,
                   BitBuckGenerator *bitBuckGenerator)
    : name(std::move(name)),
      attributes(attributes),
      creationTime(creationTime),
      dead(dead),
      id(id),
      bitBuckGenerator(bitBuckGenerator) {
  connectSignals();
}

BitBuddy::~BitBuddy() {
  attributes.clear();
  delete bitBuckGenerator;
  bitBuckGenerator = nullptr;
}

QJsonObject BitBuddy::toJson() const {
  QJsonObject obj;
  obj["id"] = id.toString();
  obj["name"] = QString::fromStdString(name);
  obj["creationTime"] = QString::number(creationTime.time_since_epoch().count());
  obj["dead"] = dead;

  QJsonObject attributesObj;
  for (const auto &attribute : attributes) {
    attributesObj[QString::number(attribute.first)] = attribute.second.toJson();
  }
  obj["attributes"] = attributesObj;
  obj["bitBuckGenerator"] = bitBuckGenerator->toJson();

  return obj;
}

BitBuddy *BitBuddy::fromJson(const QJsonObject &obj) {
  std::string name = obj["name"].toString().toStdString();
  auto creationTime = std::chrono::system_clock::time_point(
      std::chrono::system_clock::duration(obj["creationTime"].toString().toLongLong()));
  bool dead = obj["dead"].toBool();
  QUuid id = obj["id"].toString().isEmpty() ? QUuid::createUuid() : QUuid(obj["id"].toString());

  std::map<BitBuddyAttributeName::UniqueName, BitBuddyAttribute> attributes;
  QJsonObject attributesObj = obj["attributes"].toObject();
  for (auto it = attributesObj.begin(); it != attributesObj.end(); ++it) {
    attributes.emplace(std::piecewise_construct,
                       std::forward_as_tuple(static_cast<BitBuddyAttributeName::UniqueName>(it.key().toInt())),
                       std::forward_as_tuple(BitBuddyAttribute::fromJson(it.value().toObject())));
  }

  BitBuckGenerator *bitBuckGenerator = BitBuckGenerator::fromJson(obj["bitBuckGenerator"].toObject());

  return new BitBuddy(name, attributes, creationTime, dead, id, bitBuckGenerator);
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
    std::cerr << "BitBuddy does not contain the attribute: " << BitBuddyAttributeName::toString(attribute) << std::endl;
    return;
  }

  BitBuddyAttribute &attributeToUpdate = attributes.at(attribute);
  attributeToUpdate.incrementValue(value);

  emit attributeUpdated(attributeToUpdate);

  if (attributeToUpdate.getValue() <= 0) {
    die(attributeToUpdate);
  }
}

long BitBuddy::getAgeInGameYears() const {
  const auto currentTime = std::chrono::system_clock::now();
  const long ageInGameYearUnits = std::chrono::duration_cast<std::chrono::minutes>(currentTime - creationTime).count();
  const long ageInGameYears = ageInGameYearUnits / IN_GAME_YEAR_LENGTH_IN_MINUTES;

  return ageInGameYears;
}

std::string BitBuddy::getName() const { return name; }

void BitBuddy::setName(std::string name) { this->name = std::move(name); }

void BitBuddy::startBitBuckGenerator() const { this->bitBuckGenerator->startGeneration(); }

void BitBuddy::pauseBitBuckGenerator() const { bitBuckGenerator->pauseGeneration(); }

void BitBuddy::onEvent(const Event &event) {
  if (dead) {
    return;
  }

  const auto *specificEvent = dynamic_cast<const SingleAttributeEvent *>(&event);
  BitBuddyAttributeName::UniqueName attributeKey = specificEvent->getAttribute();
  int increment = specificEvent->getIncrement();
  incrementAttribute(attributeKey, increment);
}

void BitBuddy::connectSignals() const {
  connect(&EventDispatcherService::getInstance(), &EventDispatcherService::eventDispatched, this, &BitBuddy::onEvent);
}

void BitBuddy::die(const BitBuddyAttribute &attribute) {
  dead = true;
  std::cerr << "BitBuddy has died due to: " << BitBuddyAttributeName::toString(attribute.getAttributeName())
            << std::endl;

  emit died(attribute);
}

std::string BitBuddy::getSprite() const { return this->currentSprite; }

void BitBuddy::setCurrentSprite(std::string name) { this->currentSprite = name; }

void BitBuddy::addItemPurchased(const std::string &itemName) { thingsPurchased.push_back(itemName); }

const std::vector<std::string> &BitBuddy::getItemsPurchased() const { return thingsPurchased; }
