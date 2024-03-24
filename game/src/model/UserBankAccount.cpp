//
// Created by Ryan Hecht  on 2024-03-24.
//

#include "model/UserBankAccount.h"

#include <stdexcept>

UserBankAccount::UserBankAccount(int balance) {
  if (balance < MIN_USER_ACCOUNT_BALANCE || balance > MAX_USER_ACCOUNT_BALANCE) {
    throw std::invalid_argument("Balance is outside of the minimum and maximum range.");
  }

  this->balance = balance;
}

void UserBankAccount::deposit(int amount) {
  if (amount < 0) {
    throw std::invalid_argument("Amount must be positive.");
  }
  if (balance + amount > MAX_USER_ACCOUNT_BALANCE) {
    throw std::invalid_argument("Cannot deposit more than the maximum balance of.");
  }

  balance += amount;

  emit bankAccountUpdated(balance);
}

void UserBankAccount::withdraw(int amount) {
  if (amount < 0) {
    throw std::invalid_argument("Amount must be positive.");
  }
  if (balance - amount < MIN_USER_ACCOUNT_BALANCE) {
    throw std::invalid_argument("Cannot withdraw more than the current balance.");
  }

  balance -= amount;

  emit bankAccountUpdated(balance);
}

int UserBankAccount::getBalance() const {
  return balance;
}

QJsonObject UserBankAccount::toJson() const {
  QJsonObject userBankAccountObject;
  userBankAccountObject["balance"] = balance;
  return userBankAccountObject;
}

UserBankAccount *UserBankAccount::fromJson(const QJsonObject &userBankAccountJson) {
  try {
    return new UserBankAccount(userBankAccountJson["balance"].toInt());
  } catch (std::exception &error) {
    qWarning() << "Could not create UserBankAccount from JSON:" << error.what();

    return new UserBankAccount(MIN_USER_ACCOUNT_BALANCE);
  }
}