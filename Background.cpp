#include "Background.h"
#include <stdio.h>

//            |    |<--gameAttributes.pipeDistance_x-->|    |
//            |    |                                   |    |
//           _|____|_                                 _|____|_
//          |________|                               |________|
//              ▲
//              |
// gameAttributes.pipeDistance_y
//              |
//              ▼
//           ________
//          |________|
//            |    |
//            |    |
//            |    |
//RANDOMIZE THE Y COORDINATE TO SIMULATE RANDOM PIPES AND BASE FROM THAT COORDINATE GENERATE
//THE UPPER AND LOWER PIPE BY USING THE "gameAttributes.pipeDistance_y"
//THEN GENERATE THE NEXT SET OF PIPE IF THE "gameAttributes.pipeIncrement" FOR "gameAttributes.pipeDistance_x"
//IS ALREADY ACQUIRED AND SET THE "gameAttributes.pipeIncrement" TO ZERO AGAIN


void Background::drawBackgroundMenu(GameAttributes gameAtt){
    drawBackgroundStart(gameAtt);
    gameChar.drawGhost(gameAtt.x_ghostly,gameAtt.y_ghostly,gameAtt.ghostly_increment);
    drawCloud(gameAtt.cloud1_x,gameAtt.cloud1_y,gameAtt.cloud_inc);
    drawCloud(gameAtt.cloud2_x,gameAtt.cloud2_y,gameAtt.cloud_inc);
    drawCloud(gameAtt.cloud3_x,gameAtt.cloud3_y,gameAtt.cloud_inc);
}

void Background::drawBackgroundStart(GameAttributes gameAtt){
    for(GLfloat i = 0.0f,color = 0.0f;i<=4.0f;i = i + 0.02f){
        for(GLfloat j = 0.0f;j<=4.0f;j = j + 0.02f){
            poly.drawSquare(-1.0f+j,-1.0f+i,0.02f,gameAtt.stBg_red-color,gameAtt.stBg_green-color,gameAtt.stBg_blue-color);
        }
        color = color + 0.01f;
    }

    GLfloat HI = 1.0f;
    GLfloat LO = -1.0f;
    for(int i=0;i<15;i++){
        GLfloat x = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
        GLfloat y = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
        drawStar(x,y,false);
    }
    drawMoon();
    drawCloud(gameAtt.cloud1_x,gameAtt.cloud1_y,gameAtt.cloud_inc);
    drawCloud(gameAtt.cloud2_x,gameAtt.cloud2_y,gameAtt.cloud_inc);
    drawCloud(gameAtt.cloud3_x,gameAtt.cloud3_y,gameAtt.cloud_inc);
}

void Background::drawStar(GLfloat x, GLfloat y, bool menu){
    GLfloat inc = 0.002f;
    if (menu){
        inc = 0.003f;
        poly.drawPixel(x,y,(0*inc),(0*inc),inc,gameAttributes.star2_red,gameAttributes.star2_green,gameAttributes.star2_blue);
        poly.drawPixel(x,y,(-1*inc),(0*inc),inc,gameAttributes.star2_red,gameAttributes.star2_green,gameAttributes.star2_blue);
        poly.drawPixel(x,y,(1*inc),(0*inc),inc,gameAttributes.star2_red,gameAttributes.star2_green,gameAttributes.star2_blue);
        poly.drawPixel(x,y,(0*inc),(-1*inc),inc,gameAttributes.star2_red,gameAttributes.star2_green,gameAttributes.star2_blue);
        poly.drawPixel(x,y,(0*inc),(1*inc),inc,gameAttributes.star2_red,gameAttributes.star2_green,gameAttributes.star2_blue);

    } else {
        poly.drawPixel(x,y,(0*inc),(0*inc),inc,gameAttributes.star_red,gameAttributes.star_green,gameAttributes.star_blue);
        poly.drawPixel(x,y,(-1*inc),(0*inc),inc,gameAttributes.star_red,gameAttributes.star_green,gameAttributes.star_blue);
        poly.drawPixel(x,y,(1*inc),(0*inc),inc,gameAttributes.star_red,gameAttributes.star_green,gameAttributes.star_blue);
        poly.drawPixel(x,y,(0*inc),(-1*inc),inc,gameAttributes.star_red,gameAttributes.star_green,gameAttributes.star_blue);
        poly.drawPixel(x,y,(0*inc),(1*inc),inc,gameAttributes.star_red,gameAttributes.star_green,gameAttributes.star_blue);
    }
}

void Background::drawMoon(){
    GLfloat x = 0.65f;
    GLfloat y = 0.9f;
    GLfloat inc = 0.01f;
    poly.drawPixel(x,y,(10*inc),(0*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(11*inc),(0*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(12*inc),(0*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(13*inc),(0*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(14*inc),(0*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(15*inc),(0*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(8*inc),(-1*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(9*inc),(-1*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(10*inc),(-1*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(11*inc),(-1*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(12*inc),(-1*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(13*inc),(-1*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(14*inc),(-1*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(15*inc),(-1*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(16*inc),(-1*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(6*inc),(-2*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(7*inc),(-2*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(8*inc),(-2*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(9*inc),(-2*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(10*inc),(-2*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(11*inc),(-2*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(12*inc),(-2*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(13*inc),(-2*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(14*inc),(-2*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(15*inc),(-2*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(16*inc),(-2*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(5*inc),(-3*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(6*inc),(-3*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(7*inc),(-3*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(8*inc),(-3*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(9*inc),(-3*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(10*inc),(-3*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(11*inc),(-3*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(12*inc),(-3*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(13*inc),(-3*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(14*inc),(-3*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(4*inc),(-4*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(5*inc),(-4*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(6*inc),(-4*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(7*inc),(-4*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(8*inc),(-4*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(9*inc),(-4*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(10*inc),(-4*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(11*inc),(-4*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(12*inc),(-4*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(13*inc),(-4*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(3*inc),(-5*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(4*inc),(-5*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(5*inc),(-5*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(6*inc),(-5*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(7*inc),(-5*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(8*inc),(-5*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(9*inc),(-5*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(10*inc),(-5*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(11*inc),(-5*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(12*inc),(-5*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(3*inc),(-6*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(4*inc),(-6*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(5*inc),(-6*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(6*inc),(-6*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(7*inc),(-6*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(8*inc),(-6*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(9*inc),(-6*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(10*inc),(-6*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(2*inc),(-7*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(3*inc),(-7*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(4*inc),(-7*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(5*inc),(-7*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(6*inc),(-7*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(7*inc),(-7*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(8*inc),(-7*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(9*inc),(-7*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(10*inc),(-7*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(2*inc),(-8*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(3*inc),(-8*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(4*inc),(-8*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(5*inc),(-8*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(6*inc),(-8*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(7*inc),(-8*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(8*inc),(-8*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(9*inc),(-8*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(1*inc),(-9*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(2*inc),(-9*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(3*inc),(-9*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(4*inc),(-9*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(5*inc),(-9*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(6*inc),(-9*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(7*inc),(-9*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(8*inc),(-9*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(9*inc),(-9*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(1*inc),(-10*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(2*inc),(-10*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(3*inc),(-10*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(4*inc),(-10*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(5*inc),(-10*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(6*inc),(-10*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(7*inc),(-10*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(8*inc),(-10*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(9*inc),(-10*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(1*inc),(-11*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(2*inc),(-11*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(3*inc),(-11*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(4*inc),(-11*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(5*inc),(-11*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(6*inc),(-11*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(7*inc),(-11*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(8*inc),(-11*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(9*inc),(-11*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);

    poly.drawPixel(x,y,(10*inc),(-23*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(11*inc),(-23*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(12*inc),(-23*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(13*inc),(-23*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(14*inc),(-23*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(15*inc),(-23*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(8*inc),(-22*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(9*inc),(-22*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(10*inc),(-22*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(11*inc),(-22*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(12*inc),(-22*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(13*inc),(-22*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(14*inc),(-22*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(15*inc),(-22*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(16*inc),(-22*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(6*inc),(-21*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(7*inc),(-21*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(8*inc),(-21*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(9*inc),(-21*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(10*inc),(-21*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(11*inc),(-21*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(12*inc),(-21*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(13*inc),(-21*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(14*inc),(-21*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(15*inc),(-21*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(16*inc),(-21*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(5*inc),(-20*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(6*inc),(-20*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(7*inc),(-20*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(8*inc),(-20*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(9*inc),(-20*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(10*inc),(-20*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(11*inc),(-20*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(12*inc),(-20*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(13*inc),(-20*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(14*inc),(-20*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(4*inc),(-19*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(5*inc),(-19*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(6*inc),(-19*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(7*inc),(-19*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(8*inc),(-19*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(9*inc),(-19*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(10*inc),(-19*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(11*inc),(-19*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(12*inc),(-19*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(13*inc),(-19*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(3*inc),(-18*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(4*inc),(-18*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(5*inc),(-18*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(6*inc),(-18*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(7*inc),(-18*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(8*inc),(-18*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(9*inc),(-18*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(10*inc),(-18*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(11*inc),(-18*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(12*inc),(-18*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(3*inc),(-17*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(4*inc),(-17*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(5*inc),(-17*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(6*inc),(-17*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(7*inc),(-17*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(8*inc),(-17*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(9*inc),(-17*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(10*inc),(-17*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(2*inc),(-16*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(3*inc),(-16*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(4*inc),(-16*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(5*inc),(-16*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(6*inc),(-16*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(7*inc),(-16*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(8*inc),(-16*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(9*inc),(-16*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(10*inc),(-16*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(2*inc),(-15*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(3*inc),(-15*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(4*inc),(-15*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(5*inc),(-15*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(6*inc),(-15*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(7*inc),(-15*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(8*inc),(-15*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(9*inc),(-15*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(1*inc),(-14*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(2*inc),(-14*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(3*inc),(-14*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(4*inc),(-14*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(5*inc),(-14*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(6*inc),(-14*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(7*inc),(-14*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(8*inc),(-14*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(9*inc),(-14*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(1*inc),(-13*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(2*inc),(-13*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(3*inc),(-13*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(4*inc),(-13*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(5*inc),(-13*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(6*inc),(-13*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(7*inc),(-13*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(8*inc),(-13*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(9*inc),(-13*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(1*inc),(-12*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);
    poly.drawPixel(x,y,(2*inc),(-12*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(3*inc),(-12*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(4*inc),(-12*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(5*inc),(-12*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(6*inc),(-12*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(7*inc),(-12*inc),inc,gameAttributes.moonIn_red,gameAttributes.moonIn_green,gameAttributes.moonIn_blue);
    poly.drawPixel(x,y,(8*inc),(-12*inc),inc,gameAttributes.moonMid_red,gameAttributes.moonMid_green,gameAttributes.moonMid_blue);
    poly.drawPixel(x,y,(9*inc),(-12*inc),inc,gameAttributes.moonOut_red,gameAttributes.moonOut_green,gameAttributes.moonOut_blue);

}

void Background::drawCloud(GLfloat x, GLfloat y, GLfloat inc){
    poly.drawPixel(x,y,(7*inc),(0*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(8*inc),(0*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(9*inc),(0*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(13*inc),(0*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(14*inc),(0*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(15*inc),(0*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);

    poly.drawPixel(x,y,(6*inc),(-1*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(10*inc),(-1*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(12*inc),(-1*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(15*inc),(-1*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(16*inc),(-1*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(19*inc),(-1*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(20*inc),(-1*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(21*inc),(-1*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(22*inc),(-1*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(23*inc),(-1*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(7*inc),(-1*inc),inc,gameAttributes.cloud3_red,gameAttributes.cloud3_green,gameAttributes.cloud3_blue);
    poly.drawPixel(x,y,(8*inc),(-1*inc),inc,gameAttributes.cloud3_red,gameAttributes.cloud3_green,gameAttributes.cloud3_blue);
    poly.drawPixel(x,y,(9*inc),(-1*inc),inc,gameAttributes.cloud3_red,gameAttributes.cloud3_green,gameAttributes.cloud3_blue);
    poly.drawPixel(x,y,(13*inc),(-1*inc),inc,gameAttributes.cloud3_red,gameAttributes.cloud3_green,gameAttributes.cloud3_blue);
    poly.drawPixel(x,y,(14*inc),(-1*inc),inc,gameAttributes.cloud3_red,gameAttributes.cloud3_green,gameAttributes.cloud3_blue);

    poly.drawPixel(x,y,(5*inc),(-2*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(11*inc),(-2*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(16*inc),(-2*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(18*inc),(-2*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(19*inc),(-2*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(23*inc),(-2*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(6*inc),(-2*inc),inc,gameAttributes.cloud2_red,gameAttributes.cloud2_green,gameAttributes.cloud2_blue);
    poly.drawPixel(x,y,(7*inc),(-2*inc),inc,gameAttributes.cloud2_red,gameAttributes.cloud2_green,gameAttributes.cloud2_blue);
    poly.drawPixel(x,y,(8*inc),(-2*inc),inc,gameAttributes.cloud2_red,gameAttributes.cloud2_green,gameAttributes.cloud2_blue);
    poly.drawPixel(x,y,(9*inc),(-2*inc),inc,gameAttributes.cloud2_red,gameAttributes.cloud2_green,gameAttributes.cloud2_blue);
    poly.drawPixel(x,y,(13*inc),(-2*inc),inc,gameAttributes.cloud2_red,gameAttributes.cloud2_green,gameAttributes.cloud2_blue);
    poly.drawPixel(x,y,(14*inc),(-2*inc),inc,gameAttributes.cloud2_red,gameAttributes.cloud2_green,gameAttributes.cloud2_blue);
    poly.drawPixel(x,y,(10*inc),(-2*inc),inc,gameAttributes.cloud3_red,gameAttributes.cloud3_green,gameAttributes.cloud3_blue);
    poly.drawPixel(x,y,(12*inc),(-2*inc),inc,gameAttributes.cloud3_red,gameAttributes.cloud3_green,gameAttributes.cloud3_blue);
    poly.drawPixel(x,y,(15*inc),(-2*inc),inc,gameAttributes.cloud3_red,gameAttributes.cloud3_green,gameAttributes.cloud3_blue);
    poly.drawPixel(x,y,(20*inc),(-2*inc),inc,gameAttributes.cloud3_red,gameAttributes.cloud3_green,gameAttributes.cloud3_blue);
    poly.drawPixel(x,y,(21*inc),(-2*inc),inc,gameAttributes.cloud3_red,gameAttributes.cloud3_green,gameAttributes.cloud3_blue);
    poly.drawPixel(x,y,(22*inc),(-2*inc),inc,gameAttributes.cloud3_red,gameAttributes.cloud3_green,gameAttributes.cloud3_blue);


    poly.drawPixel(x,y,(5*inc),(-3*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(17*inc),(-3*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(24*inc),(-3*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(25*inc),(-3*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(11*inc),(-3*inc),inc,gameAttributes.cloud3_red,gameAttributes.cloud3_green,gameAttributes.cloud3_blue);
    poly.drawPixel(x,y,(16*inc),(-3*inc),inc,gameAttributes.cloud3_red,gameAttributes.cloud3_green,gameAttributes.cloud3_blue);
    poly.drawPixel(x,y,(18*inc),(-3*inc),inc,gameAttributes.cloud3_red,gameAttributes.cloud3_green,gameAttributes.cloud3_blue);
    poly.drawPixel(x,y,(19*inc),(-3*inc),inc,gameAttributes.cloud3_red,gameAttributes.cloud3_green,gameAttributes.cloud3_blue);
    poly.drawPixel(x,y,(23*inc),(-3*inc),inc,gameAttributes.cloud3_red,gameAttributes.cloud3_green,gameAttributes.cloud3_blue);
    poly.drawPixel(x,y,(6*inc),(-3*inc),inc,gameAttributes.cloud2_red,gameAttributes.cloud2_green,gameAttributes.cloud2_blue);
    poly.drawPixel(x,y,(7*inc),(-3*inc),inc,gameAttributes.cloud2_red,gameAttributes.cloud2_green,gameAttributes.cloud2_blue);
    poly.drawPixel(x,y,(8*inc),(-3*inc),inc,gameAttributes.cloud2_red,gameAttributes.cloud2_green,gameAttributes.cloud2_blue);
    poly.drawPixel(x,y,(9*inc),(-3*inc),inc,gameAttributes.cloud2_red,gameAttributes.cloud2_green,gameAttributes.cloud2_blue);
    poly.drawPixel(x,y,(10*inc),(-3*inc),inc,gameAttributes.cloud2_red,gameAttributes.cloud2_green,gameAttributes.cloud2_blue);
    poly.drawPixel(x,y,(12*inc),(-3*inc),inc,gameAttributes.cloud2_red,gameAttributes.cloud2_green,gameAttributes.cloud2_blue);
    poly.drawPixel(x,y,(13*inc),(-3*inc),inc,gameAttributes.cloud2_red,gameAttributes.cloud2_green,gameAttributes.cloud2_blue);
    poly.drawPixel(x,y,(14*inc),(-3*inc),inc,gameAttributes.cloud2_red,gameAttributes.cloud2_green,gameAttributes.cloud2_blue);
    poly.drawPixel(x,y,(15*inc),(-3*inc),inc,gameAttributes.cloud2_red,gameAttributes.cloud2_green,gameAttributes.cloud2_blue);
    poly.drawPixel(x,y,(20*inc),(-3*inc),inc,gameAttributes.cloud2_red,gameAttributes.cloud2_green,gameAttributes.cloud2_blue);
    poly.drawPixel(x,y,(21*inc),(-3*inc),inc,gameAttributes.cloud2_red,gameAttributes.cloud2_green,gameAttributes.cloud2_blue);
    poly.drawPixel(x,y,(22*inc),(-3*inc),inc,gameAttributes.cloud2_red,gameAttributes.cloud2_green,gameAttributes.cloud2_blue);


    for(int i = 5;i<24;i++){
        poly.drawPixel(x,y,(i*inc),(-4*inc),inc,gameAttributes.cloud2_red,gameAttributes.cloud2_green,gameAttributes.cloud2_blue);
    }
    poly.drawPixel(x,y,(5*inc),(-4*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(25*inc),(-4*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(17*inc),(-4*inc),inc,gameAttributes.cloud3_red,gameAttributes.cloud3_green,gameAttributes.cloud3_blue);
    poly.drawPixel(x,y,(24*inc),(-4*inc),inc,gameAttributes.cloud3_red,gameAttributes.cloud3_green,gameAttributes.cloud3_blue);

    for(int i = 7;i<25;i++){
        poly.drawPixel(x,y,(i*inc),(-5*inc),inc,gameAttributes.cloud2_red,gameAttributes.cloud2_green,gameAttributes.cloud2_blue);
    }
    poly.drawPixel(x,y,(6*inc),(-5*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(26*inc),(-5*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(25*inc),(-5*inc),inc,gameAttributes.cloud3_red,gameAttributes.cloud3_green,gameAttributes.cloud3_blue);

    for(int i = 8;i<25;i++){
        poly.drawPixel(x,y,(i*inc),(-6*inc),inc,gameAttributes.cloud2_red,gameAttributes.cloud2_green,gameAttributes.cloud2_blue);
    }
    poly.drawPixel(x,y,(5*inc),(-6*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(4*inc),(-6*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(3*inc),(-6*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(7*inc),(-6*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(26*inc),(-6*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(25*inc),(-6*inc),inc,gameAttributes.cloud3_red,gameAttributes.cloud3_green,gameAttributes.cloud3_blue);

    for(int i = 3;i<25;i++){
        poly.drawPixel(x,y,(i*inc),(-7*inc),inc,gameAttributes.cloud2_red,gameAttributes.cloud2_green,gameAttributes.cloud2_blue);
    }
    poly.drawPixel(x,y,(2*inc),(-7*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(6*inc),(-7*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(26*inc),(-7*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(25*inc),(-7*inc),inc,gameAttributes.cloud3_red,gameAttributes.cloud3_green,gameAttributes.cloud3_blue);

    for(int i = 2;i<25;i++){
        poly.drawPixel(x,y,(i*inc),(-8*inc),inc,gameAttributes.cloud2_red,gameAttributes.cloud2_green,gameAttributes.cloud2_blue);
    }
    poly.drawPixel(x,y,(1*inc),(-8*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(25*inc),(-8*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(24*inc),(-8*inc),inc,gameAttributes.cloud3_red,gameAttributes.cloud3_green,gameAttributes.cloud3_blue);

    for(int i = 2;i<24;i++){
        poly.drawPixel(x,y,(i*inc),(-9*inc),inc,gameAttributes.cloud2_red,gameAttributes.cloud2_green,gameAttributes.cloud2_blue);
    }
    poly.drawPixel(x,y,(1*inc),(-9*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(24*inc),(-9*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(23*inc),(-9*inc),inc,gameAttributes.cloud3_red,gameAttributes.cloud3_green,gameAttributes.cloud3_blue);

    for(int i = 2;i<23;i++){
        poly.drawPixel(x,y,(i*inc),(-10*inc),inc,gameAttributes.cloud2_red,gameAttributes.cloud2_green,gameAttributes.cloud2_blue);
    }
    poly.drawPixel(x,y,(1*inc),(-10*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(23*inc),(-10*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(25*inc),(-10*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(26*inc),(-10*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(22*inc),(-10*inc),inc,gameAttributes.cloud3_red,gameAttributes.cloud3_green,gameAttributes.cloud3_blue);

    for(int i = 3;i<24;i++){
        poly.drawPixel(x,y,(i*inc),(-11*inc),inc,gameAttributes.cloud2_red,gameAttributes.cloud2_green,gameAttributes.cloud2_blue);
    }
    poly.drawPixel(x,y,(2*inc),(-11*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(24*inc),(-11*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(23*inc),(-11*inc),inc,gameAttributes.cloud3_red,gameAttributes.cloud3_green,gameAttributes.cloud3_blue);
    poly.drawPixel(x,y,(25*inc),(-11*inc),inc,gameAttributes.cloud3_red,gameAttributes.cloud3_green,gameAttributes.cloud3_blue);
    poly.drawPixel(x,y,(26*inc),(-11*inc),inc,gameAttributes.cloud3_red,gameAttributes.cloud3_green,gameAttributes.cloud3_blue);
    poly.drawPixel(x,y,(27*inc),(-11*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);

    for(int i = 4;i<26;i++){
        poly.drawPixel(x,y,(i*inc),(-12*inc),inc,gameAttributes.cloud2_red,gameAttributes.cloud2_green,gameAttributes.cloud2_blue);
    }
    poly.drawPixel(x,y,(3*inc),(-12*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(27*inc),(-12*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    poly.drawPixel(x,y,(26*inc),(-12*inc),inc,gameAttributes.cloud3_red,gameAttributes.cloud3_green,gameAttributes.cloud3_blue);

    for(int i = 4;i<28;i++){
        poly.drawPixel(x,y,(i*inc),(-13*inc),inc,gameAttributes.cloud1_red,gameAttributes.cloud1_green,gameAttributes.cloud1_blue);
    }
}


