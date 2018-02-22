//
// Created by ubuntu on 06/02/18.
//

#ifndef LIRANPROJECT_OREN_QUESTION_H
#define LIRANPROJECT_OREN_QUESTION_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#include "path.h"

typedef enum oper {PLUS=0, MIN, MUL, DIV} Oper;
extern const char* operNames[];

typedef struct question{
    double num1;
    double num2;
    bool isFull;
    Oper   op;
}Question;


Question* createQuestion(Question *q, int argc, ...);
void solveQuestion(Question *q);
void questionToString(Question *q);
void arrQuestionToString(Question* questionArr, int questionArrSize);

#endif //LIRANPROJECT_OREN_QUESTION_H
