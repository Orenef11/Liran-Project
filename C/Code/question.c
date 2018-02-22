//
// Created by ubuntu on 06/02/18.
//
#include "../Headers/question.h"

const char* operNames[] = {"Plus", "Minus", "Multiplication", "Division"};


Question* createQuestion(Question *q, int argc, ...){
//    if(q == NULL){
//        printf("MemoryError: Cann't create new question, memory is over!\n");
//        exit(1);
//    }
    q->num1 = (random() / (double)RAND_MAX) * 1000;
    q->num2 = (random() / (double)RAND_MAX) * 1000;
    q->op = (Oper) (random() % (sizeof(Oper)));
    q->isFull = true;
    va_list args;
    argc = argc > 3 ? 3 : argc;
    va_start(args, argc);
    switch(argc) {
        case 0:

            break;
        case 1:
            q->num1 = va_arg(args, int);
            break;
        case 2:
            q->num1 = va_arg(args, int);
            q->num2 = va_arg(args, int);
            break;
        case 3:
            q->num1 = va_arg(args, int);
            q->num2 = va_arg(args, int);
            q->op = va_arg(args, Oper);
            break;

        default:
            fprintf(stderr, "CreateQuestionWaring: Please select a number between 0-3 as the number of parameters "
                    "in the function\n");
    }
    return q;
}

void solveQuestion(Question *q){
    printf("Solved the question:\n");
    questionToString(q);
    switch(q->op){
        case PLUS:
            printf("The result is %lf\n", q->num1 + q->num2);
            break;
        case MIN:
            printf("The result is %lf\n", q->num1 - q->num2);
            break;
        case MUL:
            printf("The result is %lf\n", q->num1 * q->num2);
            break;
        case DIV:
            printf("The result is %lf\n", q->num1 / q->num2);
            break;
        default:
            fprintf(stderr, "OperatorError: The operator does not exists\n");
            exit(1);
    }
}

void questionToString(Question *q){
    printf("Question variables:\n");
    printf("First number is %lf\nSecond number is %lf\nOperator is %s\n", q->num1, q->num2, operNames[q->op]);
}

void arrQuestionToString(Question* questionArr, int questionArrSize){
    printf("%s[%d]Print all question in shared memory\n", getFileName(__FILE__), __LINE__);
    for(int i = 0; i < questionArrSize; i++){
        if(questionArr[i].isFull) {
            questionToString(&questionArr[i]);
        }
        else{
            printf("%s[%d]Idx %i is empty\n", getFileName(__FILE__), __LINE__, i);

        }
    }
}