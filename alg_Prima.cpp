
#include "alg_Prima.h"



void alg_Prima(int G[N][N])
{
    int min = INT_MAX;
    int min_index;
    int i_index;
    int s;
    for (int i=0;i<N;++i){//цикл поиска минимального ребра и стартового значения
        for (int j=0;j<N;++j){
            if (G[i][j]!=-1 && G[i][j]<min){//если ребро существует и вес ребра меньше минимального значения
                min=G[i][j];// меняем минимальное значение
                s=i;//определяем стартовое значение
            }
        }
    }
    int visited[N]{0};
    visited[s]=1;//ставим для начального значения начение visited 1
    int size_mas=1;// начальный размер массива U
    int* U = new int[size_mas]{ s };
    int* new_U;//новый массив с помощью которого будем добавлять эл-ты в конец массива U
    int min_stoimost=0;//минимальная стоимость
    way *head = new way;//структура way для вывода связей,на которых строится остовное дерево

    while (size_mas !=N)//пока размер массива U не равен кол-ву звеньев
    {
        min = INT_MAX;
        way* temp=new way;
        for (int i = 0; i < size_mas; ++i)//цикл для прохода по массиву U
        {
            for (int j=0;j<N;++j){//цикл для нахождения в графе G минимального ребра
                if (visited[j]==0 && G[(U[i])%N][j]!=-1 && G[(U[i])%N][j]<min){//если звено не посещали и ребра между звеньями сущ-т и оно минимально
                    min=G[(U[i])%N][j]; //минимальный вес
                    min_index=j;//минимальный индекс по i
                    i_index=(U[i])%N; //минимальный индекс по j
//                    cout<<i_index<<"\n";
//                    cout<<min_index<<"\n";
                }
            }
        }
        cout<<"min: "<<min<<"\n";
        cout<<"i_index: "<<i_index<<"\n";
        cout<<"min_index: "<<min_index<<"\n";
        head->i=i_index;//записываем звенья, между которыми минимальная связь в параметры i и j
        head->j=min_index;
        temp->next=head;
        head=temp;//присваиваем head'у temp
        min_stoimost+=min;
        cout<<"min_stoimost: "<<min_stoimost<<"\n";
        visited[min_index]=1;
        new_U = new int[size_mas+1];//добавляем в конец массива новый эл-т
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
    for (int i=0;i<size_mas;++i){//вывод полученногор массива для  минимальной стоимости остовного дерева
        cout<<U[i]<<"("<<i<<")  ";
    }
    delete U;
    cout<<"\nМинимальная стоимость: "<<min_stoimost<<"\n";
    way *p = head->next;
    cout<<"Рёбра остовного дерева:\n";
    while (p != nullptr)
    {
        cout <<p->i <<" -> " << p->j<<" ";
        p = p->next;
    }
    cout<<"\n";
}