//
// Created by Ryan Hecht  on 2024-03-04.
//

#ifndef BITBUDDY_GAMESERVICE_H
#define BITBUDDY_GAMESERVICE_H

#include "service/EventGeneratorService.h"

/***
 * Service that manages all core game logic and starts and stops other services
 */
class GameService {

 public:
  /***
   * Singleton instance getter
   * @return the instance
   */
  static GameService &getInstance();

  GameService(const GameService &) = delete;

  GameService &operator=(const GameService &) = delete;

  GameService(GameService &&) = delete;

  GameService &operator=(GameService &&) = delete;

  /***
   * Starts the game service and all other services
   */
  static void startService();

  /***
   * Stops the game service and all other services
   */
  static void stopService();

 private:
  GameService() = default;

  ~GameService() = default;

  static EventGeneratorService &eventGeneratorService;
};

#endif //BITBUDDY_GAMESERVICE_H
