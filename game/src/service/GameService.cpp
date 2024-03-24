//
// Created by Ryan Hecht  on 2024-03-04.
//

#include "service/GameService.h"
#include "service/EventGeneratorService.h"
#include "service/MusicService.h"
#include "service/UserBankAccountService.h"

GameService &GameService::getInstance() {
  static GameService instance;
  return instance;
}

void GameService::startService() {
  EventGeneratorService::getInstance().startService();
  MusicService::getInstance().startMusic();
}

void GameService::stopService() {
  MusicService::getInstance().stopMusic();
  EventGeneratorService::getInstance().stopService();
}

GameService::~GameService() {
  stopService();
}