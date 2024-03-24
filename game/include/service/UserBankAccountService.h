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
class UserBankAccountService {
  public:
    static UserBankAccountService &getInstance();

    UserBankAccountService(const UserBankAccountService &) = delete;
    UserBankAccountService &operator=(const UserBankAccountService &) = delete;
    UserBankAccountService(UserBankAccountService &&) = delete;
    UserBankAccountService &operator=(UserBankAccountService &&) = delete;

    static void registerUserBankAccount(UserBankAccount *userBankAccount);

    [[nodiscard]] static UserBankAccount &getUserBankAccount();

  private:
    UserBankAccountService() = default;
    ~UserBankAccountService();

    static UserBankAccount *userBankAccount;
};

#endif //BITBUDDY_GAME_SRC_SERVICE_USERBANKACCOUNTSERVICE_H_