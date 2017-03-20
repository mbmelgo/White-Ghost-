#include "MyText.h"

using namespace std;

void MyText::writeALine(string s, GLfloat x, GLfloat y, GLfloat inc, GLfloat red, GLfloat green, GLfloat blue,GLfloat redOutline, GLfloat greenOutline, GLfloat blueOutline){
    for(int i=0;i<s.size(); i++){
        char c = s.at(i);
        if(c == 'A'){
            alphabets.writeA(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == 'B'){
            alphabets.writeB(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == 'C'){
            alphabets.writeC(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == 'D'){
            alphabets.writeD(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == 'E'){
            alphabets.writeE(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == 'F'){
            alphabets.writeF(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == 'G'){
            alphabets.writeG(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == 'H'){
            alphabets.writeH(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == 'I'){
            alphabets.writeI(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == 'J'){
            alphabets.writeJ(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == 'K'){
            alphabets.writeK(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == 'L'){
            alphabets.writeL(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == 'M'){
            alphabets.writeM(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == 'N'){
            alphabets.writeN(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == 'O'){
            alphabets.writeO(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == 'P'){
            alphabets.writeP(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == 'Q'){
            alphabets.writeQ(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == 'R'){
            alphabets.writeR(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == 'S'){
            alphabets.writeS(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == 'T'){
            alphabets.writeT(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == 'U'){
            alphabets.writeU(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == 'V'){
            alphabets.writeV(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == 'W'){
            alphabets.writeW(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == 'X'){
            alphabets.writeX(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == 'Y'){
            alphabets.writeY(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == 'Z'){
            alphabets.writeZ(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == '0'){
            alphabets.writeZero(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == '1'){
            alphabets.writeOne(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == '2'){
            alphabets.writeTwo(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == '3'){
            alphabets.writeThree(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == '4'){
            alphabets.writeFour(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == '5'){
            alphabets.writeFive(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == '6'){
            alphabets.writeSix(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == '7'){
            alphabets.writeSeven(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == '8'){
            alphabets.writeEight(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == '9'){
            alphabets.writeNine(x,y,inc,i,red,green,blue,redOutline,greenOutline,blueOutline);
        } else if(c == '>'){
            alphabets.drawArrow(x-inc,y,inc,0,red,green,blue,redOutline,greenOutline,blueOutline);
        }
    }
}
