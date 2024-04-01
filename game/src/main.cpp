//
// Created by Ryan Hecht on 2024-02-24
//

#include <QApplication>

#include "MainWindow.h"
#include "QtMultimedia"
#include "model/audio.h"
#include "service/BitBuddyService.h"
#include "service/FileStorageService.h"
#include "service/UserBankAccountService.h"
#include "window/LauncherWindow.h"

/**
 * @brief Entry point of the main program.
 *
 * @param argc The number of command-line arguments.
 * @param argv The command-line arguments.
 * @return The exit code of the application.
 */
int main(int argc, char *argv[]) {
  QApplication application(argc, argv);
  QCoreApplication::setApplicationName("BitBuddy");
  QCoreApplication::setApplicationVersion("1.0.0");
  BitBuddyService::registerBitBuddy(FileStorageService::loadBitBuddy("BitBuddy"));
  UserBankAccountService::registerUserBankAccount(&FileStorageService::loadUserBankAccount());

  LauncherWindow start;
  start.show();

  return QApplication::exec();
}
