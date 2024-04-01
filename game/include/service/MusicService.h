//
// Created by Ryan Hecht  on 2024-03-22.
//

#ifndef BITBUDDY_SRC_SERVICE_MUSICSERVICE_H_
#define BITBUDDY_SRC_SERVICE_MUSICSERVICE_H_

#include <QMediaPlayer>
#include <QObject>

/**
 * @class MusicService
 * @brief The MusicService is responsible for playing and stopping the music in the game.
 * @author Ryan Hecht
 *
 * This service is a singleton that is responsible for playing and stopping the music in the game. It uses a
 * QMediaPlayer in a loop to play music. It can only play one track in its current rendition.
 */
class MusicService final : public QObject {
  Q_OBJECT

 public:
  /**
   * Singleton instance getter
   *
   * @return The instance of the MusicService
   */
  static MusicService &getInstance();

  MusicService(const MusicService &) = delete;
  MusicService &operator=(const MusicService &) = delete;
  MusicService(MusicService &&) = delete;
  MusicService &operator=(MusicService &&) = delete;

  /**
   * @brief Starts the music
   */
  void startMusic();

  /**
   * @brief Stops the music
   */
  void stopMusic();

  /**
   * @brief Sets the volume of the music
   *
   * @param volume The volume to set from 0.0f to 1.0f
   */
  void setVolume(float volume);

  /**
   * @brief Gets the volume of the music
   *
   * @return The volume of the music
   */
  [[nodiscard]] float getVolume() const;

 private:
  MusicService();
  ~MusicService() override;

  QMediaPlayer *musicPlayer;
  QAudioOutput *audioOutput;
  float currentVolume;
};

#endif  // BITBUDDY_SRC_SERVICE_MUSICSERVICE_H_
