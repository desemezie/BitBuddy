//
// Created by Ryan Hecht  on 2024-03-24.
//

#ifndef BITBUDDY_GAME_SRC_SERVICE_TRANSACTIONSERVICE_H_
#define BITBUDDY_GAME_SRC_SERVICE_TRANSACTIONSERVICE_H_

#include <QObject>

/**
 * @class TransactionService
 * @brief Service that handles all transactions in the game
 * @author Ryan Hecht
 *
 * This service is a singleton responsible for handling transactions between the user and the game. The approach with
 * this service is questionable: events were originally supposed to be dispatched via the EventDispatcherService and
 * nothing else, but this service causes some tighter coupling since transactions require confirmation by both parties
 * to occur. If a refactor occurs, this service deserves to be scrutinized.
 */
class TransactionService final : public QObject {
  Q_OBJECT

 public:
  /**
   * @brief Singleton instance getter
   *
   * @return The instance of the TransactionService
   */
  static TransactionService &getInstance();

  TransactionService(const TransactionService &) = delete;
  TransactionService &operator=(const TransactionService &) = delete;
  TransactionService(TransactionService &&) = delete;
  TransactionService &operator=(TransactionService &&) = delete;

 public slots:
  /**
   * @brief Pays the user the given amount of BitBucks
   *
   * @param bitBucks The amount of BitBucks to pay the user
   */
  void payUserBitBucks(int bitBucks);

 private:
  TransactionService() = default;
  ~TransactionService() override = default;
};

#endif  // BITBUDDY_GAME_SRC_SERVICE_TRANSACTIONSERVICE_H_
