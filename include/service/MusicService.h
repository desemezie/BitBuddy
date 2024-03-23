//
// Created by Ryan Hecht  on 2024-03-22.
//

#ifndef BITBUDDY_SRC_SERVICE_MUSICSERVICE_H_
#define BITBUDDY_SRC_SERVICE_MUSICSERVICE_H_

#include <QObject>
#include <QMediaPlayer>

/***
 * Service that plays music
 */
class MusicService : public QObject {
 Q_OBJECT

 public:
  /***
   * Singleton instance getter
   *
   * @return The instance of the MusicService
   */
  static MusicService &getInstance();

  MusicService(const MusicService &) = delete;

  MusicService &operator=(const MusicService &) = delete;

  MusicService(MusicService &&) = delete;

  MusicService &operator=(MusicService &&) = delete;

  /***
   * Starts the music
   */
  void startMusic();

  /***
   * Stops the music
   */
  void stopMusic();

 public slots:

  /***
   * Sets the volume of the music
   *
   * @param volume The volume to set from 0.0f to 1.0f
   */
  void setVolume(float volume);

  /***
   * Gets the volume of the music
   *
   * @return The volume of the music
   */
  float getVolume() const;

 private:
  MusicService();

  ~MusicService() override;

  QMediaPlayer *musicPlayer;
  QAudioOutput *audioOutput;
  float currentVolume;
};

#endif //BITBUDDY_SRC_SERVICE_MUSICSERVICE_H_
