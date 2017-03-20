#include "Collision.h"

#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

bool Collision::checkCollision(Fence fence, GameChar gameChar){
    GLfloat char_x_top_left = gameChar.char_x + 0.04f;
    GLfloat char_y_top_left = gameChar.char_y - 0.04f;

    GLfloat char_x_top_right = gameChar.char_x + (gameChar.x_size * gameChar.inc) - 0.03f;
    GLfloat char_y_top_right = gameChar.char_y - 0.04f;

    GLfloat char_x_bottom_left = gameChar.char_x + 0.055f;
    GLfloat char_y_bottom_left = gameChar.char_y - (gameChar.y_size * gameChar.inc) + 0.05f;

    GLfloat char_x_bottom_right = gameChar.char_x + (gameChar.x_size * gameChar.inc) - 0.03f;
    GLfloat char_y_bottom_right = gameChar.char_y - (gameChar.y_size * gameChar.inc) + 0.05f ;

    GLfloat fence_x_top_left = fence.fence1_x;
    GLfloat fence_y_top_left = fence.fence1_y + fence.fenceDistance_y - 0.15f ;

    GLfloat fence_x_top_right = fence.fence1_x + (fence.x_size * fence.inc);
    GLfloat fence_y_top_right = fence.fence1_y + fence.fenceDistance_y  - 0.15f;

    GLfloat fence_x_bottom_left = fence.fence1_x;
    GLfloat fence_y_bottom_left = fence.fence1_y - fence.fenceDistance_y + 0.020f;

    GLfloat fence_x_bottom_right = fence.fence1_x + (fence.x_size * fence.inc);
    GLfloat fence_y_bottom_right = fence.fence1_y - fence.fenceDistance_y + 0.020f;


//    glBegin(GL_TRIANGLES);          // Each set of 3 vertices form a triangle
//       glColor3f(1.0f,0.0f,0.0f);
//       glVertex2f(char_x_top_left, char_y_top_left);
//       glVertex2f(char_x_top_right, char_y_top_right);
//       glVertex2f(char_x_bottom_left, char_y_bottom_left);
//    glEnd();
//    glBegin(GL_TRIANGLES);          // Each set of 3 vertices form a triangle
//       glColor3f(1.0f,0.0f,0.0f);
//       glVertex2f(char_x_bottom_right, char_y_bottom_right);
//       glVertex2f(char_x_top_right, char_y_top_right);
//       glVertex2f(char_x_bottom_left, char_y_bottom_left);
//    glEnd();
//    glBegin(GL_TRIANGLES);          // Each set of 3 vertices form a triangle
//       glColor3f(1.0f,1.0f,1.0f);
//       glVertex2f(fence_x_top_left, fence_y_top_left);
//       glVertex2f(fence_x_top_right, fence_y_top_right);
//       glVertex2f(fence_x_bottom_left, fence_y_bottom_left);
//    glEnd();
//    glBegin(GL_TRIANGLES);          // Each set of 3 vertices form a triangle
//       glColor3f(1.0f,1.0f,1.0f);
//       glVertex2f(fence_x_bottom_right, fence_y_bottom_right);
//       glVertex2f(fence_x_top_right, fence_y_top_right);
//       glVertex2f(fence_x_bottom_left, fence_y_bottom_left);
//    glEnd();


    if(char_x_top_right >=  fence_x_top_left && char_x_top_left <= fence_x_top_right){
        if(char_y_top_right < fence_y_top_left && char_y_bottom_left > fence_y_bottom_left){
            return false;
        }
        return true;
    }
    return false;
}
