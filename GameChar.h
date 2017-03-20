#ifndef GAMECHAR_H
#define GAMECHAR_H

#include "MyPolygon.h"

class GameChar
{
    public:
        GLfloat char1_red = 0.0f;
        GLfloat char1_green = 0.0f;
        GLfloat char1_blue = 0.0f;

        GLfloat char2_red = 1.0f;
        GLfloat char2_green = 1.0f;
        GLfloat char2_blue = 1.0f;

        GLfloat char3_red = 1.0f;
        GLfloat char3_green = 0.0f;
        GLfloat char3_blue = 0.0f;

        GLfloat char4_red = 0.6902f;
        GLfloat char4_green = 0.6902f;
        GLfloat char4_blue = 0.6902f;

        GLfloat char_x = -0.7f;
        GLfloat char_y = 0.0f;

        GLfloat inc = 0.0125f;

        int x_size = 16;
        int y_size = 15;
        MyPolygon poly;
        void drawGhost(GLfloat,GLfloat,GLfloat);
        void drawGhost1(GLfloat,GLfloat,GLfloat);
    protected:

    private:
};

#endif // GAMECHAR_H
