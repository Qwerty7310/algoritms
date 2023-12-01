#include "Prima.h"

//const int N = 10; // инициализируем N как константу

struct way
{
    int i;
    int j;
    way* next= nullptr;
};

void alg_Prima(int G[N][N])
{
    int s;
    int min = INT_MAX;
    for (int i = 0; i < N; ++i)
    {//цикл поиска минимального ребра и стартового значения
        for (int j = 0; j < N; ++j)
        {
            if (G[i][j] != -1 && G[i][j] < min)
            {//если ребро существует и вес ребра меньше минимального значения
                min = G[i][j];// меняем минимальное значение
                s = i;//определяем стартовое значение
            }
        }
    }
    int visited[N] = { 0 };
    visited[s] = 1;
    int size_mas = 1;
    int* U = new int[size_mas]{ s };
    int* new_U;
    int min_stoimost = 0;
    int min_index;
    int i_index;
    way* head = new way;

    while (size_mas != N)
    {
        min = std::numeric_limits<int>::max();
        way* temp = new way;
        for (int i = 0; i < size_mas; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (visited[j] == 0 && G[U[i]][j] != -1 && G[U[i]][j] < min)
                {
                    min = G[U[i]][j];
                    i_index = U[i];
                    min_index = j;
                }
            }
        }
        temp->i = i_index;
        temp->j = min_index;
        temp->next = head;
        head = temp;

        min_stoimost += min;
        std::cout << "\tmin_index: " << min_index << "\n";
        visited[min_index] = 1;
        new_U = new int[size_mas + 1];
        for (int i = 0; i < size_mas; ++i)
        {
            new_U[i] = U[i];
        }
        new_U[size_mas] = min_index;
        size_mas += 1;

        delete[] U;
        U = new int[size_mas];
        for (int i = 0; i < size_mas; ++i)
        {
            U[i] = new_U[i];
        }
        delete[] new_U;
        std::cout << "print U:\n";
        PrintMas(U, size_mas); // при условии что printMas определён 

    }
    for (int i = 0; i < size_mas; ++i)
    {
        std::cout << U[i] << "(" << i << ")  ";
    }
    delete[] U;
    std::cout << "\nМинимальная стоимость: " << min_stoimost << "\n";
    way* p = head->next;
    std::cout << "Путь:\n";
    while (p != nullptr)
    {
        std::cout << p->i << " -> " << p->j << " ";
        p = p->next;
    }
    cout<<"\n";
}