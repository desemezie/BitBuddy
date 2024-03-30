//
// Created by Daniel Esemezie on 2024-03-11.
//

#include "model/audio.h"
#include <QMediaPlayer>
#include <QAudioOutput>


namespace Audio {

    QMediaPlayer* media = nullptr;
    QAudioOutput* audioOutput = nullptr;

    void initializeAudioSystem() {
      if (!media) {
        media = new QMediaPlayer;
      }
      if (!audioOutput) {
        audioOutput = new QAudioOutput;
        media->setAudioOutput(audioOutput); // Connect player to audio output
      }
    }

    void playSound(const QString &type) {
      initializeAudioSystem();

        if (type == "Hunger") {
            media->setSource(QUrl("qrc:assets/munchin.mp3"));
        }
        else if (type == "Happiness"){
            media->setSource(QUrl("qrc:/assets/yay.mp3"));
        }
        else if (type == "Thirst"){
            media->setSource(QUrl("qrc:/assets/drink.mp3"));
        }
        else if (type == "Health"){
            //media->setSource(QUrl("qrc:/assets/.mps"));
        }
        else if (type == "Tiredness"){
            media->setSource(QUrl("qrc:/assets/snore.mp3"));
        }
        else if (type == "Boredom"){
            media->setSource(QUrl("qrc:/assets/snore.mps"));
        }
        else {//Hygiene
            //Q_ASSERT(type == "snore.mp3");
            media->setSource(QUrl("qrc:/assets/bubbles.mp3"));
        }

        media->play();
    }

    void muteSound(bool mute) {
      if (audioOutput) {
        audioOutput->setMuted(mute);
      }
    }

    void setVolume(int volume) {
      if (audioOutput) {
        audioOutput->setVolume(volume / 100.0); // Assuming volume is from 0 to 100
      }
    }

}