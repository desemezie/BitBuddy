//
// Created by Ryan Hecht  on 2024-03-24.
//

#ifndef BITBUDDY_GAME_SRC_MODEL_USERBANKACCOUNT_H_
#define BITBUDDY_GAME_SRC_MODEL_USERBANKACCOUNT_H_

#include <QJsonObject>

constexpr int MIN_USER_ACCOUNT_BALANCE = 0;
constexpr int MAX_USER_ACCOUNT_BALANCE = 999999999; // 1 billion - 1

/**
 * @class UserBankAccount
 * @brief Represents a user's bank account with a balance that can be deposited to or withdrawn from.
 * @author Ryan Hecht
 */
class UserBankAccount : public QObject {
 Q_OBJECT

 public:
  explicit UserBankAccount(int balance = MIN_USER_ACCOUNT_BALANCE);

  UserBankAccount(const UserBankAccount &) = delete;
  UserBankAccount &operator=(const UserBankAccount &) = delete;
  UserBankAccount(UserBankAccount &&) = delete;
  UserBankAccount &operator=(UserBankAccount &&) = delete;

  void deposit(int amount);

  void withdraw(int amount);

  [[nodiscard]] int getBalance() const;

  [[nodiscard]] QJsonObject toJson() const;

  static UserBankAccount *fromJson(const QJsonObject &userBankAccountJson);

 signals:
  void bankAccountUpdated(int balance);

 private:
  int balance;
};

#endif //BITBUDDY_GAME_SRC_MODEL_USERBANKACCOUNT_H_
