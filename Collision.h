#ifndef COLLISION_H
#define COLLISION_H

#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include "Fence.h"
#include "GameChar.h"

class Collision
{
    public:
        bool checkCollision(Fence, GameChar);

    protected:

    private:
};

#endif // COLLISION_H
