//
// Created by Ryan Hecht  on 2024-03-04.
//

#ifndef BITBUDDY_GAMESERVICE_H
#define BITBUDDY_GAMESERVICE_H

#include "service/EventGeneratorService.h"

/**
 * @class GameService
 * @brief The GameService is responsible for starting and stopping the EventGeneratorService and MusicService.
 * @author Ryan Hecht
 *
 * This service was originally meant to be a control paoint for every single service in the game. However, it now only
 * controls the EventGeneratorService and MusicService. Refactoring is needed to make this class and its usage more
 * sensible.
 */
class GameService final {
 public:
  /**
   * @brief Singleton instance getter
   *
   * @return the instance
   */
  static GameService &getInstance();

  GameService(const GameService &) = delete;
  GameService &operator=(const GameService &) = delete;
  GameService(GameService &&) = delete;
  GameService &operator=(GameService &&) = delete;

  /**
   * @brief Starts the game service and all other services
   */
  static void startService();

  /**
   * @brief Stops the game service and all other services
   */
  static void stopService();

 private:
  GameService() = default;
  ~GameService();
};

#endif  // BITBUDDY_GAMESERVICE_H
