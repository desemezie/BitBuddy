//
// Created by Ryan Hecht  on 2024-03-04.
//

#include "service/GameService.h"
#include "service/EventGeneratorService.h"
#include "service/MusicService.h"
#include "service/FileStorageService.h"

EventGeneratorService &GameService::eventGeneratorService = EventGeneratorService::getInstance();

GameService &GameService::getInstance() {
  static GameService instance;
  return instance;
}

void GameService::startService() {
  eventGeneratorService.startService();
  MusicService::getInstance().startMusic();
}

void GameService::stopService() {
  MusicService::getInstance().stopMusic();
  eventGeneratorService.stopService();
}

GameService::~GameService() {
  stopService();
}