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

  static void saveBitBuddy(const BitBuddy &bitBuddy);

  static BitBuddy *loadBitBuddy(std::string fallBackName);

 private:
  FileStorageService();
  ~FileStorageService() = default;
};

#endif //BITBUDDY_SRC_SERVICE_FILESTORAGESERVICE_H_
