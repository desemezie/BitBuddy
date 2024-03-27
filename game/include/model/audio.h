//
// Created by Daniel Esemezie on 2024-03-11.
//

#ifndef BITBUDDY_AUDIO_H
#define BITBUDDY_AUDIO_H


#include <QApplication>
#include <QMediaPlayer>
#include <QString>


namespace Audio {
    void playSound(const QString &type);
    void initializeAudioSystem();
    void muteSound(bool mute);
    void setVolume(int volume);






}


#endif //BITBUDDY_AUDIO_H
