//
// Created by Ryan Hecht  on 2024-03-22.
//

#include "service/MusicService.h"
#include <QMediaPlayer>
#include <QAudioOutput>

const QString MUSIC_SOURCE = "qrc:/assets/music/bye_bye_brain.mp3";
const float MINIMUM_VOLUME = 0.0f;
const float MAXIMUM_VOLUME = 1.0f;

MusicService &MusicService::getInstance() {
  static MusicService instance;
  return instance;
}

void MusicService::startMusic() {
  if (!musicPlayer) {
    throw std::runtime_error("Music player is not initialized");
  }

  musicPlayer->setLoops(QMediaPlayer::Infinite);
  musicPlayer->play();
}

void MusicService::stopMusic() {
  if (!musicPlayer) {
    throw std::runtime_error("Music player is not initialized");
  }

  musicPlayer->stop();
}

void MusicService::setVolume(float volume) {
  if (!audioOutput) {
    throw std::runtime_error("Audio output is not initialized");
  }

  currentVolume = std::clamp(volume, MINIMUM_VOLUME, MAXIMUM_VOLUME);
  audioOutput->setVolume(currentVolume);
}

float MusicService::getVolume() const {
  return currentVolume;
}

MusicService::MusicService() : currentVolume(MAXIMUM_VOLUME) {
  musicPlayer = new QMediaPlayer;
  audioOutput = new QAudioOutput;
  musicPlayer->setAudioOutput(audioOutput);
  musicPlayer->setSource(QUrl(MUSIC_SOURCE));
  setVolume(currentVolume);
}

MusicService::~MusicService() {
  delete musicPlayer;
}
