#ifndef MYPOLYGON_H
#define MYPOLYGON_H
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

class MyPolygon
{
    public:
        void drawRightTriangle(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
        void drawReverseRightTriangle(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
        void drawSquare(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
        void drawPixel(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
    protected:

    private:
};

#endif // MYPOLYGON_H
