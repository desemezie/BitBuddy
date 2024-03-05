#include <QApplication>
#include "MainWindow.h"
#include "service/GameService.h"

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

  MainWindow mainWindow;
  mainWindow.showNormal();

  GameService::getInstance().startService();

  return QApplication::exec();
}
