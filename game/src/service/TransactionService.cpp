//
// Created by Ryan Hecht  on 2024-03-24.
//

#include "service/TransactionService.h"
#include "service/UserBankAccountService.h"

TransactionService &TransactionService::getInstance() {
  static TransactionService instance;
  return instance;
}

void TransactionService::payUserBitBucks(int bitBucks) {
  try {
    UserBankAccountService::getUserBankAccount().deposit(bitBucks);
  } catch (std::runtime_error &error) {
    qWarning() << "Could not pay user BitBucks:" << error.what();
  }
}
