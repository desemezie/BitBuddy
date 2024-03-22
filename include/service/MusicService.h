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

 private:
  MusicService();

  ~MusicService() override;

  QMediaPlayer *musicPlayer;

  bool running = false;

 private slots:
  /***
   * Private slot that's called when the song ends to restart the song. This is a workaround to achieve a looping
   * effect since QMediaPlaylist was removed in Qt 6.
   *
   * @param status The status of the media player
   */
  void onMediaStatusChanged(QMediaPlayer::MediaStatus status);
};

#endif //BITBUDDY_SRC_SERVICE_MUSICSERVICE_H_
