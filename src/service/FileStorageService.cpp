//
// Created by Ryan Hecht  on 2024-03-23.
//

#include <QString>
#include <QStandardPaths>
#include "service/FileStorageService.h"
#include <QDir>
#include <iostream>

FileStorageService &FileStorageService::getInstance() {
  static FileStorageService instance;
  return instance;
}

void FileStorageService::saveBitBuddyName(const QString &name) {
  // Use QDir to construct the file path
  QDir saveDir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
  QString filePath = QDir(saveDir.absoluteFilePath(SAVE_DIRECTORY_NAME)).absoluteFilePath("bitBuddyName.txt");
  QFile file(filePath);

  if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    qWarning() << "Could not save the name to" << filePath;
    return;
  }

  QTextStream out(&file);
  out << name;
  file.close();
}

QString FileStorageService::loadBitBuddyName() {
  QDir saveDir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
  QString filePath = QDir(saveDir.absoluteFilePath(SAVE_DIRECTORY_NAME)).absoluteFilePath("bitBuddyName.txt");
  QFile file(filePath);

  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qWarning() << "Could not load the name from" << filePath;
    return {}; // Return an empty string
  }

  QTextStream in(&file);
  QString name = in.readLine();
  file.close();

  std::cout << "Name: " << name.toStdString() << std::endl;
  return name;
}

FileStorageService::FileStorageService() {
  QDir saveDir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
  saveDir.mkpath(SAVE_DIRECTORY_NAME);
}