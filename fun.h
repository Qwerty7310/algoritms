#ifndef INC_3TERM_ALG_LABA1_FUN_H
#define INC_3TERM_ALG_LABA1_FUN_H
#include <iostream>
#include <climits>


using namespace std;

const int N = 6;

struct list
{
    int number = -1;
    list *next = nullptr;
};

struct way{
    way* next=nullptr;
    int i;
    int j;
};
void PrintShortest(int*);
void PrintPred(int*);
void PrintMas(int* name,int size);

#endif //INC_3TERM_ALG_LABA1_FUN_H
