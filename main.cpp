/*
 * GL02Primitive.cpp: Vertex, Primitive and Color
 * Draw Simple 2D colored Shapes: quad, triangle and polygon.
 */
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <stdio.h>
#include <string>
#include <iostream>     // std::cout
#include <sstream>
#include <fstream>
using namespace std;

#include "MyPolygon.h"
#include "Alphabets.h"
#include "MyText.h"
#include "GameAttributes.h"
#include "Background.h"
#include "GameChar.h"
#include "Fence.h"
#include "Collision.h"
#include "Sound.h"

GameAttributes gameAttributes;
Sound sound;

void fileRead(){
    string line;
    ifstream loadFile;
    loadFile.open ("highscores.data", ifstream::in);
    while ( getline (loadFile,line) ){
        int i = atoi(line.c_str());
        gameAttributes.high_score = i;
    }
    loadFile.close();

}

void fileWrite(){
    ofstream saveFile ("highscores.data");
    saveFile << gameAttributes.high_score << endl;
    saveFile.close();
}

/* Initialize OpenGL Graphics */
void initGL() {
   // Set "clearing" or background color
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

void writeFile(){
    if(gameAttributes.high_score < gameAttributes.score){
        gameAttributes.high_score = gameAttributes.score;
    }
    fileWrite();
}

void initFences(){
    gameAttributes.fences.clear();
    for(int i=0;i<3;i++){
        Fence fence;
        gameAttributes.fences.push_back(fence);
    }
}

void clouds(GLfloat decrement){
    int HI = 1;
    int LO = 0;
    int random = LO + (rand()) /((RAND_MAX/(HI-LO)));
    gameAttributes.cloud_inc = 0.015f;
    HI = 1.0f;
    LO = 0.0f;
    if(random == 0){
        gameAttributes.cloud_inc = 0.008;
    }
    if(gameAttributes.cloud1_x >= -1.0f - (gameAttributes.cloud_inc*28) ){
        gameAttributes.cloud1_x = gameAttributes.cloud1_x - decrement;
    } else {
        gameAttributes.cloud1_x = 1.0f;
        gameAttributes.cloud1_y = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
    }

    if(gameAttributes.cloud2_x >= -1.0f - (gameAttributes.cloud_inc*28) && gameAttributes.cloud2_x!= 1.0f){
        gameAttributes.cloud2_x = gameAttributes.cloud2_x - decrement;
    } else {
        gameAttributes.cloud2_x = 1.0f;
        gameAttributes.cloud2_y = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
    }

    if(gameAttributes.cloud3_x >= -1.0f - (gameAttributes.cloud_inc*28) && gameAttributes.cloud3_x!= 1.0f){
        gameAttributes.cloud3_x = gameAttributes.cloud3_x - decrement;
    } else {
        gameAttributes.cloud3_x = 1.0f;
        gameAttributes.cloud3_y = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
    }

    if(gameAttributes.cloud1_x <= 0.0f && gameAttributes.cloud2_x==1.0f){
        gameAttributes.cloud2_x = 0.9f;
    }

    if(gameAttributes.cloud2_x <= 0.0f && gameAttributes.cloud3_x==1.0f){
        gameAttributes.cloud3_x = 0.9f;
    }
}

void drawFences(){
    Fence fence;
    Collision collision;
    if(gameAttributes.gameOver){
        for(int i=0;i<gameAttributes.fences.size();i++){
            if(gameAttributes.fences[i].created){
                fence.drawFence(gameAttributes.fences[i].fence1_x,gameAttributes.fences[i].fence1_y);
            }
        }
    }else{
        for(int i=0;i<gameAttributes.fences.size();i++){
            int j = i -1 ;
            if(i == 0 && !gameAttributes.fences[i].created){
                j = gameAttributes.fences.size() - 1;
                if(gameAttributes.fences[j].fence1_x <= (1.0f-fence.fenceDistance_x) && gameAttributes.fences[j].created){
                    GLfloat HI = 0.5f;
                    GLfloat LO = -0.5f;
                    gameAttributes.fences[i].fence1_y = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
                    gameAttributes.fences[i].created = true;
                    gameAttributes.fences[i].passed = false;
                }else if (!gameAttributes.fences[j].created){
                    GLfloat HI = 0.5f;
                    GLfloat LO = -0.5f;
                    gameAttributes.fences[i].fence1_y = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
                    gameAttributes.fences[i].created = true;
                    gameAttributes.fences[i].passed = false;
                }
            }
            if(gameAttributes.fences[j].fence1_x <= (1.0f-fence.fenceDistance_x) && gameAttributes.fences[i].fence1_x == 1.0f ){
                GLfloat HI = 0.5f;
                GLfloat LO = -0.5f;
                gameAttributes.fences[i].fence1_y = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
                gameAttributes.fences[i].created = true;
                gameAttributes.fences[i].passed = false;
            }

            if(gameAttributes.fences[i].created){
                fence.drawFence(gameAttributes.fences[i].fence1_x,gameAttributes.fences[i].fence1_y);
                if(gameAttributes.fences[i].fence1_x <= -1.3f){
                    gameAttributes.fences[i].fence1_x = 1.0f;
                    gameAttributes.fences[i].created = false;
                    gameAttributes.fences[i].passed = false;
                } else {
                    gameAttributes.fences[i].fence1_x = gameAttributes.fences[i].fence1_x - (gameAttributes.fenceSpeed * gameAttributes.delta_time );
                }
            }
            bool collided = collision.checkCollision(gameAttributes.fences[i],gameAttributes.gameChar);
            if(collided){
                gameAttributes.gameOver = true;
            } else if(gameAttributes.gameChar.char_x > (gameAttributes.fences[i].fence1_x + (gameAttributes.fences[i].x_size * gameAttributes.fences[i].inc))
                      && !gameAttributes.fences[i].passed){
                gameAttributes.score++;
                if(gameAttributes.score % 10 == 0 && gameAttributes.score != 0){
                    gameAttributes.speed = gameAttributes.speed + 0.1f;
                    gameAttributes.ghostSpeed = gameAttributes.ghostSpeed + 0.01f;
                    gameAttributes.fenceSpeed = gameAttributes.fenceSpeed + 0.1f;
                }
                gameAttributes.fences[i].passed = true;
            }
        }
    }
}

void menuPage(){
    Background background;
    background.drawBackgroundMenu(gameAttributes);
    if (gameAttributes.ghost_menu_speed >= 15){
        clouds(0.1f);
        GLfloat HI = 1.0f;
        GLfloat LO = -1.0f;
        gameAttributes.x_ghostly = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
        gameAttributes.y_ghostly = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
        HI = 0.04f;
        LO = 0.009f;
        gameAttributes.ghostly_increment = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
        gameAttributes.ghost_menu_speed = 0;
    } else {
        gameAttributes.ghost_menu_speed++;
    }
    string start = " START";
    string info = " INFO";
    if(gameAttributes.startSelected){
        start = ">START";
    } else {
        info = ">INFO";
    }
    MyText Text;
    Text.writeALine("WHITE",-0.64f, 0.6f, 0.04f, gameAttributes.text_red, gameAttributes.text_green, gameAttributes.text_blue,
                   gameAttributes.text_redOutline,gameAttributes.text_greenOutline,gameAttributes.text_blueOutline);
    Text.writeALine("GHOST",-0.64f, 0.25f, 0.04f, gameAttributes.text_red, gameAttributes.text_green, gameAttributes.text_blue,
                   gameAttributes.text_redOutline,gameAttributes.text_greenOutline,gameAttributes.text_blueOutline);
    Text.writeALine(start,-0.48f, -0.2f, 0.025f, gameAttributes.text_red, gameAttributes.text_green, gameAttributes.text_blue,
                   gameAttributes.text_redOutline,gameAttributes.text_greenOutline,gameAttributes.text_blueOutline);
    Text.writeALine(info,-0.48f, -0.45f, 0.025f, gameAttributes.text_red, gameAttributes.text_green, gameAttributes.text_blue,
                   gameAttributes.text_redOutline,gameAttributes.text_greenOutline,gameAttributes.text_blueOutline);
}

void startPage(){
    Background background;
    clouds(0.02f);
    background.drawBackgroundStart(gameAttributes);
    MyText Text;
    gameAttributes.gameChar.drawGhost(gameAttributes.gameChar.char_x,gameAttributes.gameChar.char_y,gameAttributes.gameChar.inc);
    if(!gameAttributes.gameStart){
        Text.writeALine("TAP TO START",-0.4f, 0.0f, 0.010f,
                   gameAttributes.text_red, gameAttributes.text_green, gameAttributes.text_blue,
                   gameAttributes.text_redOutline,gameAttributes.text_greenOutline,gameAttributes.text_blueOutline);
    } else {
            if (gameAttributes.clicked &&  gameAttributes.delta_time > gameAttributes.ctr_clicked){
//                if(gameAttributes.gameChar.char_y < 1.0f){
                    gameAttributes.gameChar.drawGhost1(gameAttributes.gameChar.char_x,gameAttributes.gameChar.char_y,gameAttributes.gameChar.inc);
                    gameAttributes.gameChar.char_y = gameAttributes.gameChar.char_y + (gameAttributes.speed * gameAttributes.delta_time);
                    gameAttributes.ctr_clicked = gameAttributes.ctr_clicked + (gameAttributes.ghostSpeed * gameAttributes.delta_time);
//                } else {
                    if (gameAttributes.ctr_clicked >= gameAttributes.delta_time){
                        gameAttributes.ctr_clicked = 0.0f;
                        gameAttributes.clicked = false;
                    }
//                }
            } else {
                gameAttributes.gameChar.char_y = gameAttributes.gameChar.char_y - (gameAttributes.speed * gameAttributes.delta_time );
            }
        if(gameAttributes.gameChar.char_y <= -0.85f){
            gameAttributes.gameChar.char_y = -0.85f;
            gameAttributes.gameOver = true;
        }
        drawFences();
        stringstream convert;
        convert << gameAttributes.score;
        string result = "" + convert.str();
        char *score = new char[result.length() + 1];
        strcpy(score, result.c_str());
        Text.writeALine(score,0.0f,0.8f,0.01f,
                    gameAttributes.text_red, gameAttributes.text_green, gameAttributes.text_blue,
                    gameAttributes.text_redOutline,gameAttributes.text_greenOutline,gameAttributes.text_blueOutline);
    }

}

void gameOverPage(){
    if(!sound.hitSound){
        sound.playHitSound();
    }
    Background background;
    clouds(0.001f);
    GameChar gameChar;
    background.drawBackgroundStart(gameAttributes);
    MyText Text;
    gameAttributes.gameChar.drawGhost(gameAttributes.gameChar.char_x,gameAttributes.gameChar.char_y,gameAttributes.gameChar.inc);
    drawFences();
    Text.writeALine("GAME",-0.4f, 0.25f, 0.035f,
               gameAttributes.text_red, gameAttributes.text_green, gameAttributes.text_blue,
               gameAttributes.text_redOutline,gameAttributes.text_greenOutline,gameAttributes.text_blueOutline);
    Text.writeALine("OVER",-0.4f, (0.25f*-0.5f), 0.035f,
               gameAttributes.text_red, gameAttributes.text_green, gameAttributes.text_blue,
               gameAttributes.text_redOutline,gameAttributes.text_greenOutline,gameAttributes.text_blueOutline);
    Text.writeALine("BACK",-0.07f, -0.55f, 0.010f,
                   gameAttributes.text_red, gameAttributes.text_green, gameAttributes.text_blue,
                   gameAttributes.text_redOutline,gameAttributes.text_greenOutline,gameAttributes.text_blueOutline);
}

void infoPage(){
    Background background;
    background.drawBackgroundMenu(gameAttributes);
    if (gameAttributes.ghost_menu_speed >= 15){
        clouds(0.1f);
        GLfloat HI = 1.0f;
        GLfloat LO = -1.0f;
        gameAttributes.x_ghostly = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
        gameAttributes.y_ghostly = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
        HI = 0.04f;
        LO = 0.009f;
        gameAttributes.ghostly_increment = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
        gameAttributes.ghost_menu_speed = 0;
    } else {
        gameAttributes.ghost_menu_speed++;
    }
    MyText Text;
    Text.writeALine("INSTRUCTIONS",-0.44f, 0.80f, 0.010f,
                   gameAttributes.text_red, gameAttributes.text_green, gameAttributes.text_blue,
                   gameAttributes.text_redOutline,gameAttributes.text_greenOutline,gameAttributes.text_blueOutline);
    Text.writeALine("THE SUN IS ABOUT TO SHINE AND GHOSTS CAPABILITIES",-0.95f, 0.6f, 0.0055f,
                   gameAttributes.text_red, gameAttributes.text_green, gameAttributes.text_blue,
                   gameAttributes.text_redOutline,gameAttributes.text_greenOutline,gameAttributes.text_blueOutline);
    Text.writeALine("DECREASES HELP WHITE THE GHOST FLY HOME BY",-0.95f, 0.5f, 0.0055f,
                   gameAttributes.text_red, gameAttributes.text_green, gameAttributes.text_blue,
                   gameAttributes.text_redOutline,gameAttributes.text_greenOutline,gameAttributes.text_blueOutline);
    Text.writeALine("AVOIDING THOSE FENCE TAP THE SCREEN TO FLY",-0.95f, 0.4f, 0.0055f,
                   gameAttributes.text_red, gameAttributes.text_green, gameAttributes.text_blue,
                   gameAttributes.text_redOutline,gameAttributes.text_greenOutline,gameAttributes.text_blueOutline);
    Text.writeALine("HIGHSCORE",-0.30f, 0.2f, 0.010f,
                   gameAttributes.text_red, gameAttributes.text_green, gameAttributes.text_blue,
                   gameAttributes.text_redOutline,gameAttributes.text_greenOutline,gameAttributes.text_blueOutline);
    stringstream convert;
    convert << gameAttributes.high_score;
    string result = "" + convert.str();
    char *score = new char[result.length() + 1];
    strcpy(score, result.c_str());
    float i = -0.08f;
    if(gameAttributes.high_score>99){
        i = -0.45f;
    } else if(gameAttributes.high_score>9){
        i = -0.25f;
    }
    Text.writeALine(score,i, -0.1f, 0.05f,
                   gameAttributes.text_red, gameAttributes.text_green, gameAttributes.text_blue,
                   gameAttributes.text_redOutline,gameAttributes.text_greenOutline,gameAttributes.text_blueOutline);

    Text.writeALine(">BACK",-0.14f, -0.55f, 0.010f,
                   gameAttributes.text_red, gameAttributes.text_green, gameAttributes.text_blue,
                   gameAttributes.text_redOutline,gameAttributes.text_greenOutline,gameAttributes.text_blueOutline);
}
/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted.
   color rgb/255 to glutFloat
   */
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(gameAttributes.gameOver){
//        printf("GAME OVER \n");
        gameOverPage();
    } else if (gameAttributes.start){
//        printf("START \n");
        startPage();
    } else if (gameAttributes.info) {
//        printf("INFO \n");
        infoPage();
    } else {
//        printf("MENU \n");
        if(!sound.menuSound){
            sound.playMenuSound();
        }
        menuPage();
    }
    glutSwapBuffers();  // Render now
}

void updateScreen(){
    GLfloat timeSinceStart =  glutGet(GLUT_ELAPSED_TIME);
    GLfloat deltaTime = timeSinceStart - gameAttributes.old_time_start;
    gameAttributes.old_time_start = timeSinceStart;
    gameAttributes.delta_time = deltaTime/1000;
    printf("%f\n",gameAttributes.delta_time);
    glutPostRedisplay();
}

void mouseClicks(int button, int state, int x, int y) {
//    printf("%i %i\n",x,y);
    if (gameAttributes.gameOver){
        if(x >= 372 && y>=491 && x<=477 && y<=516){
            writeFile();
            sound.playSelectSound();
            gameAttributes.gameChar.char_x = -0.7f;
            gameAttributes.gameChar.char_y = 0.0f;
            gameAttributes.startSelected = true;
            gameAttributes.start = false;
            gameAttributes.info = false;
            gameAttributes.gameStart = false;
            gameAttributes.gameOver = false;
            gameAttributes.prevX = -111;
            gameAttributes.prevY = -111;
            gameAttributes.i = 0;
            gameAttributes.clicked = false;
            gameAttributes.ctr_clicked = 0.0f;
            gameAttributes.score = 0;
            gameAttributes.speed = 0.5f;
            gameAttributes.ghostSpeed = 0.05f;
            gameAttributes.fenceSpeed = 0.3f;
            gameAttributes.cheat_code = "";
            gameAttributes.ghost_menu_speed = 25;
            gameAttributes.x_ghostly = -1;
            gameAttributes.y_ghostly = -1;
            gameAttributes.ghostly_increment = 0.04f;
            gameAttributes.old_time_start = 0.0f;
            gameAttributes.delta_time = 0.0f;
            gameAttributes.game_factor = 100.0f;
            initFences();
            sound.hitSound = false;
            sound.menuSound = true;
        }
    } else if(gameAttributes.start){
        sound.playSelectSound();
        bool click = false;
        if(gameAttributes.prevX != x && gameAttributes.prevY != y && !gameAttributes.gameStart && gameAttributes.i != 0){
            click = true;
        }
        gameAttributes.prevX = x;
        gameAttributes.prevY = y;
        gameAttributes.i++;
        if(gameAttributes.gameStart){
            sound.playFlySound();
//            sound.playMenuSound();
            gameAttributes.clicked = true;
            gameAttributes.ctr_clicked = 0.0f;
            if(gameAttributes.gameChar.char_y > 1.0f){
                gameAttributes.gameChar.char_y = 1.0f;
            }
        } else if(!gameAttributes.gameStart &&  click){
            gameAttributes.gameStart = true;
        }
    } else if(gameAttributes.info){
        sound.playSelectSound();
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN &&
               (x >= 372 && y>=493 && x<=475 && y<=516)) {
            gameAttributes.start = false;
            gameAttributes.info = false;
            gameAttributes.startSelected = true;
        }
    } else {
        sound.playSelectSound();
        if(gameAttributes.startSelected){
            if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN &&
               (x >= 280 && y>=373 && x<=614 && y<=438)) {
                gameAttributes.start = true;
                gameAttributes.info = false;
                gameAttributes.startSelected = true;
            } else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN &&
               (x >= 276 && y>=447 && x<=540 && y<=507)) {
                gameAttributes.start = false;
                gameAttributes.info = false;
                gameAttributes.startSelected = false;
            }
        } else {
            if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN &&
               (x >= 280 && y>=373 && x<=614 && y<=438)) {
                gameAttributes.start = false;
                gameAttributes.info = false;
                gameAttributes.startSelected = true;
            } else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN &&
               (x >= 276 && y>=447 && x<=540 && y<=507)) {
                gameAttributes.info = true;
                gameAttributes.start = false;
                gameAttributes.startSelected = false;
            }
        }
    }
}

void keyPressed (unsigned char key, int x, int y) {
    if(gameAttributes.gameOver){
        if (key == 13) {
            writeFile();
            sound.playSelectSound();
            gameAttributes.gameChar.char_x = -0.7f;
            gameAttributes.gameChar.char_y = 0.0f;
            gameAttributes.startSelected = true;
            gameAttributes.start = false;
            gameAttributes.info = false;
            gameAttributes.gameStart = false;
            gameAttributes.gameOver = false;
            gameAttributes.prevX = -111;
            gameAttributes.prevY = -111;
            gameAttributes.i = 0;
            gameAttributes.clicked = false;
            gameAttributes.ctr_clicked = 0.0f;
            gameAttributes.score = 0;
            gameAttributes.speed = 0.5f;
            gameAttributes.ghostSpeed = 0.05f;
            gameAttributes.fenceSpeed = 0.3f;
            gameAttributes.cheat_code = "";
            gameAttributes.ghost_menu_speed = 25;
            gameAttributes.x_ghostly = -1;
            gameAttributes.y_ghostly = -1;
            gameAttributes.ghostly_increment = 0.04f;
            gameAttributes.old_time_start = 0.0f;
            gameAttributes.delta_time = 0.0f;
            gameAttributes.game_factor = 100.0f;
            initFences();
            sound.hitSound = false;
            sound.menuSound = true;
        }
    } else if (gameAttributes.start){
        if (key == 13) {
            sound.playSelectSound();
            if (!gameAttributes.clicked){
                gameAttributes.clicked = true;
                gameAttributes.gameStart = true;
            } else {
                sound.playFlySound();
                gameAttributes.clicked = true;
                gameAttributes.ctr_clicked = 0.0f;
                if(gameAttributes.gameChar.char_y > 1.0f){
                    gameAttributes.gameChar.char_y = 1.0f;
                }
            }


        }
    } else if (gameAttributes.info) {
        if (key == 13) {
            sound.playSelectSound();
            gameAttributes.start = false;
            gameAttributes.info = false;
            gameAttributes.startSelected = true;
        }
    } else{
        sound.playSelectSound();
        if (key == 'a') {
            gameAttributes.cheat_code = gameAttributes.cheat_code + "a";
        } else if (key == 'b') {
            gameAttributes.cheat_code = gameAttributes.cheat_code + "b";
        } else if (key == 13) {
            if (gameAttributes.cheat_code == "UUDDLRLRba"){
                gameAttributes.score = 100;
                gameAttributes.startSelected = true;
            }
            if(gameAttributes.startSelected){
                gameAttributes.start = true;
                gameAttributes.info = false;
                gameAttributes.startSelected = true;
            } else {
                gameAttributes.start = false;
                gameAttributes.info = true;
                gameAttributes.startSelected = false;
            }
        } else {
            gameAttributes.cheat_code = "";
        }
    }
}

void SpecialInput(int key, int x, int y){
    switch(key){
        case GLUT_KEY_UP:
            gameAttributes.cheat_code = gameAttributes.cheat_code + "U";
            gameAttributes.startSelected = true;
            break;
        case GLUT_KEY_DOWN:
            gameAttributes.cheat_code = gameAttributes.cheat_code + "D";
            gameAttributes.startSelected = false;
            break;
        case GLUT_KEY_LEFT:
            gameAttributes.cheat_code = gameAttributes.cheat_code + "L";
            break;
        case GLUT_KEY_RIGHT:
            gameAttributes.cheat_code = gameAttributes.cheat_code + "R";
            break;
    }
}
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    fileRead();
    initFences();
    glutInit(&argc, argv);          // Initialize GLUT
    glutInitWindowSize(800, 640);   // Set the window's initial width & height
    glutInitWindowPosition(0, 0); // Position the window's initial top-left corner
    glutInitDisplayMode(GLUT_DOUBLE); //double buffer
    glutCreateWindow("White Ghost");  // Create window with the given title
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    glutMouseFunc(mouseClicks);
    glutKeyboardFunc(keyPressed);
    glutSpecialFunc(SpecialInput);
//    glutTimerFunc(0,updateScreen,0);
    glutIdleFunc(updateScreen);
    initGL();                       // Our own OpenGL initialization
    glutMainLoop();                 // Enter the event-processing loop
}
