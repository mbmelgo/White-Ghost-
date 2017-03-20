#ifndef MYTEXT_H
#define MYTEXT_H
#include <string>
#include "Alphabets.h"

class MyText
{
    public:
        Alphabets alphabets;
        void writeALine(std::string, GLfloat, GLfloat, GLfloat,GLfloat,GLfloat,GLfloat,GLfloat,GLfloat,GLfloat);
    protected:
    private:
};

#endif // MYTEXT_H
