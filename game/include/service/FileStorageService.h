//
// Created by Ryan Hecht  on 2024-03-23.
//

#ifndef BITBUDDY_SRC_SERVICE_FILESTORAGESERVICE_H_
#define BITBUDDY_SRC_SERVICE_FILESTORAGESERVICE_H_

#include <QString>
#include "model/BitBuddy.h"

const QString SAVE_DIRECTORY_NAME = "bitbuddySaveFiles";
const QString BITBUDDY_FILE_NAME = "bitBuddy.json";

class FileStorageService {
 public:
  /***
   * Singleton instance getter
   *
   * @return The instance of the FileStorageService
   */
  static FileStorageService &getInstance();
  FileStorageService(const FileStorageService &) = delete;
  FileStorageService &operator=(const FileStorageService &) = delete;
  FileStorageService(FileStorageService &&) = delete;
  FileStorageService &operator=(FileStorageService &&) = delete;

  /***
   * Saves the BitBuddy to a file
   *
   * @param bitBuddy The BitBuddy to save
   */
  static void saveBitBuddy(const BitBuddy &bitBuddy);

  /***
   * Loads the BitBuddy from a file and returns a pointer to the newly created BitBuddy
   *
   * @param fallBackName The name to use for the creation of a new BitBuddy if the BitBuddy cannot be loaded
   * @return A pointer to the loaded BitBuddy
   */
  static BitBuddy *loadBitBuddy(std::string fallBackName);

 private:
  FileStorageService();
  ~FileStorageService() = default;
};

#endif //BITBUDDY_SRC_SERVICE_FILESTORAGESERVICE_H_
