//
// Created by Ryan Hecht  on 2024-03-24.
//

#include "service/UserBankAccountService.h"

UserBankAccount *UserBankAccountService::userBankAccount = nullptr;

UserBankAccountService &UserBankAccountService::getInstance() {
  static UserBankAccountService instance;
  return instance;
}

void UserBankAccountService::registerUserBankAccount(UserBankAccount *userBankAccount) {
  UserBankAccountService::userBankAccount = userBankAccount;
}

UserBankAccount &UserBankAccountService::getUserBankAccount() {
  if (userBankAccount == nullptr) {
    throw std::runtime_error("There is no UserBankAccount registered with the UserBankAccountService.");
  }

  return *userBankAccount;
}

UserBankAccountService::~UserBankAccountService() {
  UserBankAccountService::userBankAccount = nullptr;
}