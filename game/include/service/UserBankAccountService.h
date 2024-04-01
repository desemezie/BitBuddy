//
// Created by Ryan Hecht  on 2024-03-24.
//

#ifndef BITBUDDY_GAME_SRC_SERVICE_USERBANKACCOUNTSERVICE_H_
#define BITBUDDY_GAME_SRC_SERVICE_USERBANKACCOUNTSERVICE_H_

#include "model/UserBankAccount.h"

/**
 * @class UserBankAccountService
 * @brief Singleton service that acts as a global registry for the UserBankAccount object to allow access throughout the
 * application.
 * @author Ryan Hecht
 *
 * Exposes only a reference to the UserBankAccount object.
 */
class UserBankAccountService final {
 public:
  /**
   * @brief Singleton instance getter
   *
   * @return The instance of the UserBankAccountService
   */
  static UserBankAccountService &getInstance();

  UserBankAccountService(const UserBankAccountService &) = delete;
  UserBankAccountService &operator=(const UserBankAccountService &) = delete;
  UserBankAccountService(UserBankAccountService &&) = delete;
  UserBankAccountService &operator=(UserBankAccountService &&) = delete;

  /**
   * @brief Registers the UserBankAccount object with the service
   * @details This method is used to register the UserBankAccount object with the service. A pointer to the object
   * is then stored internally in the UserBankAccountService.
   *
   * @param userBankAccount The UserBankAccount object to register
   */
  static void registerUserBankAccount(UserBankAccount *userBankAccount);

  /**
   * @brief Gets the UserBankAccount object registered with the service
   * @details This method is used to get the UserBankAccount object registered with the service. This method should
   * only be called after the UserBankAccount object has been registered with the service.
   *
   * @return The UserBankAccount object
   */
  [[nodiscard]] static UserBankAccount &getUserBankAccount();

 private:
  /**
   * @brief UserBankAccountService constructor
   */
  UserBankAccountService() = default;

  /**
   * @brief UserBankAccountService destructor
   */
  ~UserBankAccountService();

  static UserBankAccount *userBankAccount;
};

#endif  // BITBUDDY_GAME_SRC_SERVICE_USERBANKACCOUNTSERVICE_H_