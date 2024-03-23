//
// Created by Ryan Hecht  on 2024-03-23.
//

#ifndef BITBUDDY_SRC_SERVICE_FILESTORAGESERVICE_H_
#define BITBUDDY_SRC_SERVICE_FILESTORAGESERVICE_H_

#include <QString>

const QString SAVE_DIRECTORY_NAME = "bitbuddySaveFiles";

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

  static void saveBitBuddyName(const QString &name);

  static QString loadBitBuddyName();

 private:
  FileStorageService();
  ~FileStorageService() = default;
};

#endif //BITBUDDY_SRC_SERVICE_FILESTORAGESERVICE_H_
