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
 */
class TransactionService : public QObject {
 Q_OBJECT

 public:
  static TransactionService &getInstance();

  TransactionService(const TransactionService &) = delete;
  TransactionService &operator=(const TransactionService &) = delete;
  TransactionService(TransactionService &&) = delete;
  TransactionService &operator=(TransactionService &&) = delete;

 public slots:
  void payUserBitBucks(int bitBucks);

 private:
  TransactionService() = default;
  ~TransactionService() override = default;

};

#endif //BITBUDDY_GAME_SRC_SERVICE_TRANSACTIONSERVICE_H_
