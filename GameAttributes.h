#ifndef GAMEATTRIBUTES_H
#define GAMEATTRIBUTES_H

#include "GameChar.h"
#include "Fence.h"
#include <stdlib.h>
#include <string>
#include <vector>


using namespace std;

class GameAttributes
{
    public:
        GameChar gameChar;

        bool startSelected = true;
        bool start = false;
        bool info = false;
        bool gameStart = false;
        bool gameOver = false;

        int prevX = -111;
        int prevY = -111;
        int i = 0;

        GLfloat text_red = 1.0f;
        GLfloat text_green = 0.96078431372f;
        GLfloat text_blue = 0.76470588235f;
        GLfloat text_redOutline = 0.0f;
        GLfloat text_greenOutline = 0.0f;
        GLfloat text_blueOutline = 0.0f;

        GLfloat bg2_red = 0.31372549019f;
        GLfloat bg2_green = 0.31372549019f;
        GLfloat bg2_blue = 0.31372549019f;

        GLfloat bg_red = 0.60784313725f;
        GLfloat bg_green = 0.8431372549f;
        GLfloat bg_blue = 0.83529411764f;

        GLfloat bg3_red = 1.0f;
        GLfloat bg3_green = 0.44705882352f;
        GLfloat bg3_blue = 0.37647058823f;

        GLfloat stBg_red = 0.0f;
        GLfloat stBg_green = 0.73333333333f;
        GLfloat stBg_blue = 0.83921568627f;

        GLfloat moonIn_red = 0.98039215686f;
        GLfloat moonIn_green = 0.94901960784f;
        GLfloat moonIn_blue = 0.63137254902f;

        GLfloat moonOut_red = 0.0f;
        GLfloat moonOut_green = 0.0f;
        GLfloat moonOut_blue = 0.0f;

        GLfloat moonMid_red = 0.90196078431f;
        GLfloat moonMid_green = 0.58431372549f;
        GLfloat moonMid_blue = 0.18039215686f;

        GLfloat star_red = 1.0f;
        GLfloat star_green = 0.87451f;
        GLfloat star_blue = 0.0f;

        GLfloat star2_red = 1.0f;
        GLfloat star2_green = 1.0f;
        GLfloat star2_blue = 1.0f;

        GLfloat cloud1_red = 0.0f;
        GLfloat cloud1_green = 0.0f;
        GLfloat cloud1_blue = 0.0f;

        GLfloat cloud2_red = 1.0f;
        GLfloat cloud2_green = 1.0f;
        GLfloat cloud2_blue = 1.0f;

        GLfloat cloud3_red = 0.50196078431f;
        GLfloat cloud3_green = 0.50196078431f;
        GLfloat cloud3_blue = 0.50196078431f;

        GLfloat cloud1_x = 1.0f;
        GLfloat cloud1_y = 1.0f;

        GLfloat cloud2_x = 1.0f;
        GLfloat cloud2_y = 1.0f;

        GLfloat cloud3_x = 1.0f;
        GLfloat cloud3_y = 1.0f;

        GLfloat cloud_inc = 0.015f;

        bool clicked = false;

        vector<Fence> fences;

        int score = 0;

        GLfloat speed = 0.5f;
        GLfloat ghostSpeed = 0.05f;
        GLfloat fenceSpeed = 0.3f;

        int high_score = 0;

        int ghost_menu_speed = 25;
        GLfloat x_ghostly = -1;
        GLfloat y_ghostly = -1;
        GLfloat ghostly_increment = 0.04f;

        GLfloat old_time_start = 0.0f;
        GLfloat delta_time = 0.0f;
        GLfloat ctr_clicked = 0.0f;
        GLfloat game_factor = 100.0f;

        string cheat_code = "";

    protected:

    private:
};

#endif // GAMEATTRIBUTES_H
