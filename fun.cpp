#include "fun.h"

void PrintShortest(int *shortest)
{
    cout << "shortest[]:\t";
    for (int i = 0; i < N; i++)
        if (shortest[i] == INT_MAX) cout << "inf(" << i <<") ";
        else cout << shortest[i] << '(' << i << ") ";
}

void PrintPred(int *pred)
{
    cout << "\npred[]:\t\t";
    for (int i = 0; i < N; i++)
        cout << pred[i] << '(' << i << ") ";
}

void PrintMas(int* name,int size)
{
    for (int i=0;i<size;++i){
        cout<<name[i]<< '(' << i << ") ";
    }
    cout<<"\n";
}
