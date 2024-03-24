//
// Created by Ryan Hecht  on 2024-03-23.
//

#ifndef BITBUDDY_SRC_SERVICE_FILESTORAGESERVICE_H_
#define BITBUDDY_SRC_SERVICE_FILESTORAGESERVICE_H_

#include <QString>
#include "model/BitBuddy.h"
#include "model/UserBankAccount.h"

const QString SAVE_DIRECTORY_NAME = "bitbuddySaveFiles";
const QString BITBUDDY_FILE_NAME = "bitBuddy.json";
const QString USER_BANK_ACCOUNT_FILE_NAME = "userBankAccount.json";

/**
 * @class FileStorageService
 * @brief Provides functionality to save and load BitBuddy instances to and from files.
 * @author Ryan Hecht
 *
 * FileStorageService is implemented as a singleton to ensure only one instance manages file storage operations.
 */
class FileStorageService {
 public:
  /**
   * @brief Gets the singleton instance of the FileStorageService.
   *
   * @return The instance of the FileStorageService.
   */
  static FileStorageService &getInstance();

  // Deleted copy/move constructors and assignment operators.
  FileStorageService(const FileStorageService &) = delete;
  FileStorageService &operator=(const FileStorageService &) = delete;
  FileStorageService(FileStorageService &&) = delete;
  FileStorageService &operator=(FileStorageService &&) = delete;

  /**
   * @brief Saves the BitBuddy to a file.
   *
   * @param bitBuddy The BitBuddy instance to save.
   */
  static void saveBitBuddy(const BitBuddy &bitBuddy);

  /**
   * @brief Loads the BitBuddy from a file.
   *
   * If the BitBuddy cannot be loaded, a new BitBuddy is created using the provided fallback name.
   *
   * @param fallBackName The name to use for the creation of a new BitBuddy if loading fails.
   * @return A pointer to the loaded or newly created BitBuddy instance.
   */
  static BitBuddy *loadBitBuddy(std::string fallBackName);

  static void saveUserBankAccount(const UserBankAccount &userBankAccount);

  static UserBankAccount &loadUserBankAccount();

 private:
  FileStorageService();
  ~FileStorageService() = default;
};

#endif //BITBUDDY_SRC_SERVICE_FILESTORAGESERVICE_H_
