//
// Created by Ryan Hecht  on 2024-03-24.
//

#ifndef BITBUDDY_GAME_SRC_SERVICE_BITBUDDYSERVICE_H_
#define BITBUDDY_GAME_SRC_SERVICE_BITBUDDYSERVICE_H_

#include "model/BitBuddy.h"

/**
 * @class BitBuddyService
 * @brief Singleton service that acts as a global registry for the BitBuddy object to allow access throughout the
 * application.
 * @author Ryan Hecht
 *
 * Exposes only a reference to the BitBuddy object.
 */
class BitBuddyService final {
 public:
  /**
   * Singleton instance getter
   *
   * @return the instance
   */
  static BitBuddyService &getInstance();

  BitBuddyService(const BitBuddyService &) = delete;
  BitBuddyService &operator=(const BitBuddyService &) = delete;
  BitBuddyService(BitBuddyService &&) = delete;
  BitBuddyService &operator=(BitBuddyService &&) = delete;

  /**
   * Registers the BitBuddy object with the service
   *
   * @param bitBuddy The BitBuddy object to register
   */
  static void registerBitBuddy(BitBuddy *bitBuddy);

  /**
   * Gets the BitBuddy object registered with the service
   *
   * @return The BitBuddy object
   */
  [[nodiscard]] static BitBuddy &getBitBuddy();

 private:
  BitBuddyService() = default;
  ~BitBuddyService();

  static BitBuddy *bitBuddy;
};

#endif  // BITBUDDY_GAME_SRC_SERVICE_BITBUDDYSERVICE_H_
