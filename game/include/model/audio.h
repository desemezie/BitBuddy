//
// Created by Daniel Esemezie on 2024-03-11.
//

#ifndef BITBUDDY_AUDIO_H
#define BITBUDDY_AUDIO_H


#include <QApplication>
#include <QMediaPlayer>
#include <QString>


/**
 * @namespace Audio
 * @brief Provides functionalities for audio playback and control within the application.
 *
 * The Audio namespace encapsulates methods for playing sound effects, initializing the audio system,
 * muting/unmuting sound effects, and adjusting the overall volume. It's designed to offer a simple interface
 * for managing sound effects within the application, leveraging Qt's multimedia capabilities.
 */
namespace Audio {
    /**
    * @brief Play a sound of the specified type.
    *
    * This function looks up and plays a sound corresponding to the given type identifier.
    * The type could specify different sound effects within the application.
    *
    * @param type A QString identifier for the type of sound to play
    */
    void playSound(const QString &type);

    /**
    * @brief Initializes the audio system for the application.
    *
    * Sets up necessary components and configurations for audio playback.
    */
    void initializeAudioSystem();

    /**
    * @brief Mutes or unmutes all sound effects in the application.
    *
    * @param mute A boolean flag indicating whether to mute (true) or unmute (false) the sound.
    */
    void muteSound(bool mute);

    /**
    * @brief Sets the global volume for sound playback.
    *
    * Adjusts the volume at which all sound effects are played back in the application.
    *
    * @param volume An integer specifying the volume level, typically in a range (e.g., 0-100).
    */
    void setVolume(int volume);


}


#endif //BITBUDDY_AUDIO_H
