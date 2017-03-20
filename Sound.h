#ifndef SOUND_H
#define SOUND_H

#include <windows.h>
#include <mmsystem.h>
#include <irrKlang.h>

using namespace irrklang;
class Sound
{
    public:
        ISoundEngine* engine = createIrrKlangDevice();
        bool menuSound = false;
        bool flySound = false;
        bool hitSound = false;
        bool selectSound = false;
        void playSelectSound();
        void playMenuSound();
        void playFlySound();
        void playHitSound();

    protected:

    private:
};

#endif // SOUND_H
