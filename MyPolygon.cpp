#include "MyPolygon.h"
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>

void MyPolygon::drawRightTriangle(GLfloat x, GLfloat y, GLfloat inc, GLfloat red, GLfloat green, GLfloat blue){
    GLfloat x1 = x;
    GLfloat y1 = y+inc;
    GLfloat x2 = x+inc;
    GLfloat y2 = y;
    glBegin(GL_TRIANGLES);          // Each set of 3 vertices form a triangle
       glColor3f(red,green,blue);
       glVertex2f(x, y);
       glVertex2f(x1, y1);
       glVertex2f(x2, y2);
    glEnd();
}

void MyPolygon::drawReverseRightTriangle(GLfloat x, GLfloat y, GLfloat inc, GLfloat red, GLfloat green, GLfloat blue){
    GLfloat x1 = x;
    GLfloat y1 = y+inc;
    GLfloat x2 = x+inc;
    GLfloat y2 = y;
    x = x + inc;
    y = y + inc;
    glBegin(GL_TRIANGLES);          // Each set of 3 vertices form a triangle
       glColor3f(red,green,blue);
       glVertex2f(x, y);
       glVertex2f(x1, y1);
       glVertex2f(x2, y2);
    glEnd();
}

void MyPolygon::drawSquare(GLfloat x, GLfloat y, GLfloat inc, GLfloat red, GLfloat green, GLfloat blue){
    drawRightTriangle(x,y,inc,red,green,blue);
    drawReverseRightTriangle(x,y,inc,red,green,blue);
}



void MyPolygon::drawPixel(GLfloat tmpX, GLfloat tmpY,GLfloat incrementX, GLfloat incrementY, GLfloat pixelSize, GLfloat red, GLfloat green, GLfloat blue){
    drawSquare(tmpX+incrementX,tmpY+incrementY,pixelSize,red,green,blue);
}

