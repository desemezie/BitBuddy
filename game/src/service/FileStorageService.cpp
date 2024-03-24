//
// Created by Ryan Hecht  on 2024-03-23.
//

#include "service/FileStorageService.h"
#include "model/BitBuddy.h"

#include <QString>
#include <QStandardPaths>
#include <QDir>
#include <iostream>
#include <QJsonObject>
#include <QJsonDocument>
#include <utility>

FileStorageService &FileStorageService::getInstance() {
  static FileStorageService instance;
  return instance;
}

void FileStorageService::saveBitBuddy(const BitBuddy &bitBuddy) {
  QDir saveDir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
  QString filePath = QDir(saveDir.absoluteFilePath(SAVE_DIRECTORY_NAME)).absoluteFilePath(BITBUDDY_FILE_NAME);
  QFile file(filePath);

  if (!file.open(QIODevice::WriteOnly)) {
    qWarning() << "Could not save the bit buddy to" << filePath;
    return;
  }

  QJsonObject bitBuddyObject = bitBuddy.toJson();
  QJsonDocument saveDoc(bitBuddyObject);
  file.write(saveDoc.toJson());
  file.close();
  std::cout << "Saved bit buddy to " << filePath.toStdString() << std::endl;
}

BitBuddy *FileStorageService::loadBitBuddy(std::string fallBackName) {
  QDir saveDir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
  QString filePath = QDir(saveDir.absoluteFilePath(SAVE_DIRECTORY_NAME)).absoluteFilePath(BITBUDDY_FILE_NAME);
  QFile file(filePath);

  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qWarning() << "Could not load the bit buddy from" << filePath;
    return new BitBuddy(std::move(fallBackName));
  }

  QByteArray saveData = file.readAll();
  QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
  return BitBuddy::fromJson(loadDoc.object());
}

void FileStorageService::saveUserBankAccount(const UserBankAccount &userBankAccount) {
  QDir saveDir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
  QString filePath = QDir(saveDir.absoluteFilePath(SAVE_DIRECTORY_NAME)).absoluteFilePath(USER_BANK_ACCOUNT_FILE_NAME);
  QFile file(filePath);

  if (!file.open(QIODevice::WriteOnly)) {
    qWarning() << "Could not save the user bank account to" << filePath;
    return;
  }

  QJsonObject userBankAccountObject = userBankAccount.toJson();
  QJsonDocument saveDoc(userBankAccountObject);
  file.write(saveDoc.toJson());
  file.close();
  std::cout << "Saved user bank account to " << filePath.toStdString() << std::endl;
}

UserBankAccount &FileStorageService::loadUserBankAccount() {
  QDir saveDir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
  QString filePath = QDir(saveDir.absoluteFilePath(SAVE_DIRECTORY_NAME)).absoluteFilePath(USER_BANK_ACCOUNT_FILE_NAME);
  QFile file(filePath);

  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qWarning() << "Could not load the user bank account from" << filePath;
    return *new UserBankAccount();
  }

  QByteArray saveData = file.readAll();
  QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
  return *UserBankAccount::fromJson(loadDoc.object());
}

FileStorageService::FileStorageService() {
  QDir saveDir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
  saveDir.mkpath(SAVE_DIRECTORY_NAME);
}