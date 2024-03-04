//
// Created by Ryan Hecht  on 2024-03-04.
//

#include "service/GameService.h"

#include "service/EventGeneratorService.h"

EventGeneratorService &GameService::eventGeneratorService = EventGeneratorService::getInstance();

GameService &GameService::getInstance() {
  static GameService instance;
  return instance;
}

void GameService::startService() {
  eventGeneratorService.startService();
}

void GameService::stopService() {
  eventGeneratorService.stopService();
}
