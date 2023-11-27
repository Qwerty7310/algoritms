
#include "alg_Prima.h"
#include "fun.h"



void alg_Prima(int G[N][N], int s)
{
    int visited[N]{0};
    visited[s]=1;
    int size_mas=1;
    int* U = new int[size_mas]{ s };
    int* new_U;
    int min_stoimost=0;
    int min = INT_MAX;
    int min_index;
    int i_index;
    way *head = new way;

    while (size_mas !=N)
    {
        min = INT_MAX;
        if (s>5){
            cout<<"Не может быть такого стартового значения\n";
            return;
        }
        way* temp=new way;
        for (int i = 0; i < size_mas; ++i)//TODO для другого стартового значения сделать
        {
            for (int j=0;j<N;++j){
                if (visited[j]==0 && G[(U[i])%N][j]!=-1 && G[(U[i])%N][j]<min){
                    min=G[(U[i])%N][j];
                    min_index=j;
                    i_index=(U[i])%N;
                    cout<<i_index<<"\n";
                    cout<<min_index<<"\n";
                }
            }
        }
        cout<<"min: "<<min<<"\n";
        cout<<"i_index: "<<i_index<<"\n";
        cout<<"min_index: "<<min_index<<"\n";
        temp->i=i_index;
        temp->j=min_index;
        temp->next=head;
        head=temp;
//        for (int i = 0; i < size_mas; ++i)
//        {
//            for (int j=0;j<N;++j){
//                if (G[U[i]][j]!=-1 && G[U[i]][j]<min && visited[j]==0){
//                    min=G[U[i]][j];
//                    i_index=i;
//                    min_index=j;
//                }
//            }
//        }
        min_stoimost+=min;//TODO сделать оставное дерево
        cout<<"min_stoimost: "<<min_stoimost<<"\n";
        visited[min_index]=1;
        new_U = new int[size_mas+1];
        for (int i = 0; i < size_mas; ++i)
        {
            new_U[i] = U[i];
        }
        new_U[size_mas] = min_index;
        size_mas+=1;
//        cout<<"print new_U:\n";
//        PrintMas(new_U,size_mas);
        delete U;
        int* U = new int[size_mas];
        for (int i = 0; i < size_mas; ++i)
        {
            U[i] = new_U[i];
        }
        delete new_U;
        cout<<"print U:\n";
        PrintMas(U,size_mas);
    }
    for (int i=0;i<size_mas;++i){
        cout<<U[i]<<"("<<i<<")  ";
    }
    delete U;
    cout<<"\nМинимальная стоимость: "<<min_stoimost<<"\n";
    way *p = head->next;
    cout<<"Путь:\n";
    while (p != nullptr)
    {
        cout <<p->i <<" -> " << p->j<<"; ";
        p = p->next;
    }
}