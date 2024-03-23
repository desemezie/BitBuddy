//
// Created by Ryan Hecht on 2024-02-24
//

#include <QApplication>
#include "MainWindow.h"
#include "service/GameService.h"
#include "LauncherWindow.h"
#include "model/audio.h"
#include "QtMultimedia"
#include <QMediaPlayer>
#include "model/audio.h"
#include <QMediaPlayer>
#include <QAudioOutput>
#include "QAmbientSound"
#include "QAudio"
#include <QAudioEngine>



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

  LauncherWindow start;
  start.show();


  return QApplication::exec();

}
