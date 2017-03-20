#include "Sound.h"


void Sound::playMenuSound(){
//    engine->play2D("E:/Vincent/4thYear/CMSC178/WhiteGhost/sound/bg.wav", false);
    menuSound = PlaySound(TEXT("./sound/bg.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

void Sound::playFlySound(){
    engine->play2D("./sound/fly.wav", false);
//    flySound = PlaySound(TEXT("E:/Vincent/4thYear/CMSC178/WhiteGhost/sound/fly.wav"), NULL, SND_ASYNC|SND_FILENAME);
}

void Sound::playHitSound(){
    engine->play2D("./sound/hit.wav", false);
    hitSound = true;
//    hitSound = PlaySound(TEXT("E:/Vincent/4thYear/CMSC178/WhiteGhost/sound/hit.wav"), NULL, SND_ASYNC|SND_FILENAME);
}

void Sound::playSelectSound(){
    engine->play2D("./sound/select.wav", false);
//    selectSound = PlaySound(TEXT("E:/Vincent/4thYear/CMSC178/WhiteGhost/sound/select.wav"), NULL, SND_ASYNC|SND_FILENAME);
}
