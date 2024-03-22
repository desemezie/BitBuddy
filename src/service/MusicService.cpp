//
// Created by Ryan Hecht  on 2024-03-22.
//

#include "service/MusicService.h"
#include <QMediaPlayer>
#include <QAudioOutput>

const QString MUSIC_SOURCE = "qrc:/assets/yay.mp3";

MusicService &MusicService::getInstance() {
  static MusicService instance;
  return instance;
}

void MusicService::startMusic() {
  if (musicPlayer) {
    running = true;
    musicPlayer->play(); // Start playing music
  }
}

void MusicService::stopMusic() {
  if (musicPlayer) {
    running = false;
    musicPlayer->stop(); // Stop playing music
  }
}

MusicService::MusicService() {
  musicPlayer = new QMediaPlayer;
  auto *audioOutput = new QAudioOutput;
  musicPlayer->setAudioOutput(audioOutput);
  musicPlayer->setSource(QUrl(MUSIC_SOURCE));

  connect(musicPlayer, &QMediaPlayer::mediaStatusChanged, this, &MusicService::onMediaStatusChanged);
}

MusicService::~MusicService() {
  delete musicPlayer;
}

void MusicService::onMediaStatusChanged(QMediaPlayer::MediaStatus status) {
  if (!running) {
    return;
  }

  if (status == QMediaPlayer::EndOfMedia) {
    musicPlayer->setPosition(0); // Reset the position to the start of the music
    musicPlayer->play();
  }
}

