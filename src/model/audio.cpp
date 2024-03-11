//
// Created by Daniel Esemezie on 2024-03-11.
//

#include "audio.h"



#include <QMediaPlayer>

namespace Audio {

    void playSound(QString type) {
        QMediaPlayer *media = new QMediaPlayer();
        if (type == "die") {
            media->setMedia(QUrl("qrc:/audio/die.mp3"));
        } else {
            Q_ASSERT(type == "success");
            media->setMedia(QUrl("qrc:/audio/success.mp3"));
        }
        media->play();
    }
}