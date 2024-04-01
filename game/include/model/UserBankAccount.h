//
// Created by Ryan Hecht  on 2024-03-24.
//

#ifndef BITBUDDY_GAME_SRC_MODEL_USERBANKACCOUNT_H_
#define BITBUDDY_GAME_SRC_MODEL_USERBANKACCOUNT_H_

#include <QJsonObject>

constexpr int MIN_USER_ACCOUNT_BALANCE = 0;
constexpr int MAX_USER_ACCOUNT_BALANCE = 999999999;  // 1 billion - 1

/**
 * @class UserBankAccount
 * @brief Represents a user's bank account with a balance that can be deposited to or withdrawn from.
 * @author Ryan Hecht
 *
 *
 */
class UserBankAccount final : public QObject {
  Q_OBJECT

 public:
  /**
   * @brief Constructor for the UserBankAccount
   *
   * @param balance The initial balance of the UserBankAccount
   */
  explicit UserBankAccount(int balance = MIN_USER_ACCOUNT_BALANCE);

  UserBankAccount(const UserBankAccount &) = delete;
  UserBankAccount &operator=(const UserBankAccount &) = delete;
  UserBankAccount(UserBankAccount &&) = delete;
  UserBankAccount &operator=(UserBankAccount &&) = delete;

  /**
   * @brief Deposits an amount of BitBucks into the UserBankAccount
   * @details The amount must be greater than or equal to 0 and less than or equal to the difference between the user's
   * current balance and the MAX_USER_ACCOUNT_BALANCE such that depositing money would not cause themn to exceed the
   * maximim limit. If the amount does not meet either of these conditions, an invalid_argument exception is thrown.
   *
   * @param amount The amount of BitBucks to deposit
   */
  void deposit(int amount);

  /**
   * @brief Withdraws an amount of BitBucks from the UserBankAccount
   * @details The amount must be greater than or equal to 0 and less than or equal to the user's current balance. If the
   * amount does not meet these conditions, an invalid_argument exception is thrown.
   *
   * @param amount The amount of BitBucks to withdraw
   */
  void withdraw(int amount);

  /**
   * @brief Gets the balance of the UserBankAccount
   *
   * @return The balance of the UserBankAccount
   */
  [[nodiscard]] int getBalance() const;

  /**
   * @brief Converts the UserBankAccount to a JSON object
   *
   * @return The JSON object representation of the UserBankAccount
   */
  [[nodiscard]] QJsonObject toJson() const;

  /**
   * @brief Converts a JSON object to a UserBankAccount
   * @details If the JSON object does not contain a balance key or the balance key is not an integer, a UserBankAccount
   * is created with the minimum balance and returned instead.

   * @param userBankAccountJson The JSON object to convert
   * @return The UserBankAccount created from the JSON object
   */
  static UserBankAccount *fromJson(const QJsonObject &userBankAccountJson);

 signals:
  /**
   * @brief Emitted when the UserBankAccount's balance is updated
   *
   * @param balance The new balance of the UserBankAccount
   */
  void bankAccountUpdated(int balance);

 private:
  int balance;
};

#endif  // BITBUDDY_GAME_SRC_MODEL_USERBANKACCOUNT_H_
