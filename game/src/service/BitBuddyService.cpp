//
// Created by Ryan Hecht  on 2024-03-24.
//

#include "service/BitBuddyService.h"

BitBuddy *BitBuddyService::bitBuddy = nullptr;

BitBuddyService &BitBuddyService::getInstance() {
  static BitBuddyService instance;
  return instance;
}

void BitBuddyService::registerBitBuddy(BitBuddy *bitBuddy) {
  BitBuddyService::bitBuddy = bitBuddy;
}

BitBuddy &BitBuddyService::getBitBuddy() {
  if (bitBuddy == nullptr) {
    throw std::runtime_error("There is not BitBuddy registered with the BitBuddyService.");
  }

  return *bitBuddy;
}

BitBuddyService::~BitBuddyService() {
  bitBuddy = nullptr;
}