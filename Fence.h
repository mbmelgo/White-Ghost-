#ifndef FENCE_H
#define FENCE_H

#include "MyPolygon.h"

class Fence
{
    public:
        MyPolygon poly;
        GLfloat fenceIn_red = 0.88235294117f;
        GLfloat fenceIn_green = 0.85098039215f;
        GLfloat fenceIn_blue = 0.82352941176f;
        GLfloat fenceOut_red = 0.38823529411f;
        GLfloat fenceOut_green = 0.36078431372f;
        GLfloat fenceOut_blue = 0.33725490196f;
        GLfloat fenceMid_red = 0.61568627451f;
        GLfloat fenceMid_green = 0.58431372549f;
        GLfloat fenceMid_blue = 0.55686274509f;
        GLfloat fenceDistance_y = 0.3f;
        GLfloat fenceDistance_x = 0.9f;
        GLfloat fence1_y = 0.5f;
        GLfloat fence1_x = 1.0f;
        int x_size = 21;
        GLfloat inc = 0.012f;
        bool created = false;
        bool passed = false;
        void drawFence(GLfloat,GLfloat);
    protected:

    private:
        void drawFenceUp(GLfloat, GLfloat);
        void drawFenceDown(GLfloat, GLfloat);
        void drawFenceBody(GLfloat,GLfloat,GLfloat,int,int);
        void drawFenceBody2(GLfloat,GLfloat,GLfloat,int,int);
};

#endif // FENCE_H
