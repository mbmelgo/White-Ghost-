#ifndef MYOBJECTS_H
#define MYOBJECTS_H

#include "MyPolygon.h"
#include "GameAttributes.h"
#include "GameChar.h"

class Background
{
    public:
        GameAttributes gameAttributes;
        MyPolygon poly;
        GameChar gameChar;
        void drawBackgroundMenu(GameAttributes);
        void drawBackgroundStart(GameAttributes);

    protected:
    private:
        void drawMoon();
        void drawStar(GLfloat, GLfloat,bool);
        void drawCloud(GLfloat, GLfloat,GLfloat);
};

#endif // MYOBJECTS_H
