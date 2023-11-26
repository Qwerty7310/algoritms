#ifndef INC_3TERM_ALG_LABA1_FUN_H
#define INC_3TERM_ALG_LABA1_FUN_H
#include <iostream>


using namespace std;

const int N = 6;

struct list
{
    int number = -1;
    list *next = nullptr;
};

void PrintShortest(int*);
void PrintPred(int*);

#endif //INC_3TERM_ALG_LABA1_FUN_H
