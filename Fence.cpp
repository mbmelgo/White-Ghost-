#include "Fence.h"

void Fence::drawFence(GLfloat x, GLfloat y){
    drawFenceUp(x,y-fenceDistance_y);
    drawFenceDown(x,y+fenceDistance_y);
}

void Fence::drawFenceUp(GLfloat x, GLfloat y){

    poly.drawPixel(x,y,(4*inc),(0*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(11*inc),(0*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(18*inc),(0*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);

    poly.drawPixel(x,y,(3*inc),(-1*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(5*inc),(-1*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(10*inc),(-1*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(12*inc),(-1*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(17*inc),(-1*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(19*inc),(-1*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(4*inc),(-1*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(11*inc),(-1*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(18*inc),(-1*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);


    poly.drawPixel(x,y,(2*inc),(-2*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(6*inc),(-2*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(9*inc),(-2*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(13*inc),(-2*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(16*inc),(-2*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(20*inc),(-2*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(4*inc),(-2*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(11*inc),(-2*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(18*inc),(-2*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(5*inc),(-2*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(12*inc),(-2*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(19*inc),(-2*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(3*inc),(-2*inc),inc,fenceIn_red,fenceIn_green,fenceIn_blue);
    poly.drawPixel(x,y,(10*inc),(-2*inc),inc,fenceIn_red,fenceIn_green,fenceIn_blue);
    poly.drawPixel(x,y,(17*inc),(-2*inc),inc,fenceIn_red,fenceIn_green,fenceIn_blue);

    drawFenceBody(x,y,inc,-3,-6);

    for(int i=1;i<22;i++){
        poly.drawPixel(x,y,(i*inc),(-7*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    }

    poly.drawPixel(x,y,(1*inc),(-8*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(21*inc),(-8*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    for(int i=2;i<21;i++){
        poly.drawPixel(x,y,(i*inc),(-8*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    }
    poly.drawPixel(x,y,(1*inc),(-9*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(21*inc),(-9*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(2*inc),(-9*inc),inc,fenceIn_red,fenceIn_green,fenceIn_blue);
    poly.drawPixel(x,y,(3*inc),(-9*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(4*inc),(-9*inc),inc,0.0f,0.0f,0.0f);
    poly.drawPixel(x,y,(16*inc),(-9*inc),inc,fenceIn_red,fenceIn_green,fenceIn_blue);
    poly.drawPixel(x,y,(17*inc),(-9*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(18*inc),(-9*inc),inc,0.0f,0.0f,0.0f);
    poly.drawPixel(x,y,(19*inc),(-9*inc),inc,fenceIn_red,fenceIn_green,fenceIn_blue);
    poly.drawPixel(x,y,(20*inc),(-9*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    for(int i = 5;i<16;i++){
        poly.drawPixel(x,y,(i*inc),(-9*inc),inc,fenceIn_red,fenceIn_green,fenceIn_blue);
    }
    poly.drawPixel(x,y,(1*inc),(-10*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(21*inc),(-10*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    for(int i = 2;i<21;i++){
        poly.drawPixel(x,y,(i*inc),(-10*inc),inc,fenceIn_red,fenceIn_green,fenceIn_blue);
    }
    poly.drawPixel(x,y,(4*inc),(-10*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(18*inc),(-10*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(20*inc),(-10*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    for(int i=1;i<22;i++){
        poly.drawPixel(x,y,(i*inc),(-11*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    }
    poly.drawPixel(x,y,(2*inc),(-12*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(6*inc),(-12*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(9*inc),(-12*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(13*inc),(-12*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(16*inc),(-12*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(20*inc),(-12*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(3*inc),(-12*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(4*inc),(-12*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(5*inc),(-12*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(10*inc),(-12*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(11*inc),(-12*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(12*inc),(-12*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(17*inc),(-12*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(18*inc),(-12*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(19*inc),(-12*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    drawFenceBody(x,y,inc,-13,-500);
}

void Fence::drawFenceDown(GLfloat x, GLfloat y){

    poly.drawPixel(x,y,(4*inc),(-12*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(11*inc),(-12*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(18*inc),(-12*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);

    poly.drawPixel(x,y,(3*inc),(-11*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(5*inc),(-11*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(10*inc),(-11*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(12*inc),(-11*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(17*inc),(-11*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(19*inc),(-11*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(4*inc),(-11*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(11*inc),(-11*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(18*inc),(-11*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);


    poly.drawPixel(x,y,(2*inc),(-10*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(6*inc),(-10*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(9*inc),(-10*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(13*inc),(-10*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(16*inc),(-10*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(20*inc),(-10*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(4*inc),(-10*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(11*inc),(-10*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(18*inc),(-10*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(5*inc),(-10*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(12*inc),(-10*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(19*inc),(-10*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(3*inc),(-10*inc),inc,fenceIn_red,fenceIn_green,fenceIn_blue);
    poly.drawPixel(x,y,(10*inc),(-10*inc),inc,fenceIn_red,fenceIn_green,fenceIn_blue);
    poly.drawPixel(x,y,(17*inc),(-10*inc),inc,fenceIn_red,fenceIn_green,fenceIn_blue);

    drawFenceBody(x,y,inc,-6,-9);

    for(int i=1;i<22;i++){
        poly.drawPixel(x,y,(i*inc),(-5*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    }

    poly.drawPixel(x,y,(1*inc),(-4*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(21*inc),(-4*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    for(int i=2;i<21;i++){
        poly.drawPixel(x,y,(i*inc),(-4*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    }
    poly.drawPixel(x,y,(1*inc),(-3*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(21*inc),(-3*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(2*inc),(-3*inc),inc,fenceIn_red,fenceIn_green,fenceIn_blue);
    poly.drawPixel(x,y,(3*inc),(-3*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(4*inc),(-3*inc),inc,0.0f,0.0f,0.0f);
    poly.drawPixel(x,y,(16*inc),(-3*inc),inc,fenceIn_red,fenceIn_green,fenceIn_blue);
    poly.drawPixel(x,y,(17*inc),(-3*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(18*inc),(-3*inc),inc,0.0f,0.0f,0.0f);
    poly.drawPixel(x,y,(19*inc),(-3*inc),inc,fenceIn_red,fenceIn_green,fenceIn_blue);
    poly.drawPixel(x,y,(20*inc),(-3*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    for(int i = 5;i<16;i++){
        poly.drawPixel(x,y,(i*inc),(-3*inc),inc,fenceIn_red,fenceIn_green,fenceIn_blue);
    }
    poly.drawPixel(x,y,(1*inc),(-2*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(21*inc),(-2*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    for(int i = 2;i<21;i++){
        poly.drawPixel(x,y,(i*inc),(-2*inc),inc,fenceIn_red,fenceIn_green,fenceIn_blue);
    }
    poly.drawPixel(x,y,(4*inc),(-2*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(18*inc),(-2*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(20*inc),(-2*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    for(int i=1;i<22;i++){
        poly.drawPixel(x,y,(i*inc),(-2*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    }
    poly.drawPixel(x,y,(2*inc),(-1*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(6*inc),(-1*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(9*inc),(-1*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(13*inc),(-1*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(16*inc),(-1*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(20*inc),(-1*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
    poly.drawPixel(x,y,(3*inc),(-1*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(4*inc),(-1*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(5*inc),(-1*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(10*inc),(-1*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(11*inc),(-1*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(12*inc),(-1*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(17*inc),(-1*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(18*inc),(-1*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    poly.drawPixel(x,y,(19*inc),(-1*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    drawFenceBody(x,y,inc,500,0);
}

void Fence::drawFenceBody(GLfloat x, GLfloat y, GLfloat inc, int down, int top){
    for(int i = down;i>=top;i--){
        poly.drawPixel(x,y,(2*inc),(i*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
        poly.drawPixel(x,y,(6*inc),(i*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
        poly.drawPixel(x,y,(9*inc),(i*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
        poly.drawPixel(x,y,(13*inc),(i*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
        poly.drawPixel(x,y,(16*inc),(i*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
        poly.drawPixel(x,y,(20*inc),(i*inc),inc,fenceOut_red,fenceOut_green,fenceOut_blue);
        poly.drawPixel(x,y,(3*inc),(i*inc),inc,fenceIn_red,fenceIn_green,fenceIn_blue);
        poly.drawPixel(x,y,(4*inc),(i*inc),inc,fenceIn_red,fenceIn_green,fenceIn_blue);
        poly.drawPixel(x,y,(5*inc),(i*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
        poly.drawPixel(x,y,(10*inc),(i*inc),inc,fenceIn_red,fenceIn_green,fenceIn_blue);
        poly.drawPixel(x,y,(11*inc),(i*inc),inc,fenceIn_red,fenceIn_green,fenceIn_blue);
        poly.drawPixel(x,y,(12*inc),(i*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
        poly.drawPixel(x,y,(17*inc),(i*inc),inc,fenceIn_red,fenceIn_green,fenceIn_blue);
        poly.drawPixel(x,y,(18*inc),(i*inc),inc,fenceIn_red,fenceIn_green,fenceIn_blue);
        poly.drawPixel(x,y,(19*inc),(i*inc),inc,fenceMid_red,fenceMid_green,fenceMid_blue);
    }

}
