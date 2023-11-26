#include "BellmanFord.h"

void BellmanFord(int G[N][N], int s)
{
    cout << "\t\tBELLMAN-FORD\n";
    int shortest[N];
    int pred[N];

    for (int i = 0; i < N; i++)
    {
        shortest[i] = INT_MAX;
        pred[i] = -1;
    }
    shortest[s] = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (int u = 0; u < N; u++)
            for (int v = 0; v < N; v++)
            {
                if (G[u][v] != INT_MAX && shortest[u] != INT_MAX && shortest[v] > shortest[u] + G[u][v])
                {
                    shortest[v] = shortest[u] + G[u][v];
                    pred[v] = u;
                }
            }
    }

    bool flag = true;
    for (int u = 0; u < N; u++)
        for (int v = 0; v < N; v++)
            if (G[u][v] != INT_MAX && shortest[u] != INT_MAX && shortest[v] > shortest[u] + G[u][v])
            {
                int temp = v;
                int x = temp;
                bool visited[N];
                for (int i = 0; i < N; i++)
                    visited[i] = false;

                while (!visited[x])
                {
                    visited[x] = true;
                    x = pred[x];
                }
                temp = pred[x];

                list *head = new list;
                head->number = x;

                while (temp != x)
                {
                    list *l = new list;
                    l->number = temp;
                    l->next = head;
                    head = l;
                    temp = pred[temp];
                }

                cout << "Цикл с отрицательным весом: ";
                list *p = head;
                while (p != nullptr)
                {
                    cout << p->number << " -> ";
                    p = p->next;
                }
                flag = false;
                cout << endl;
            }
    if (flag)
    {
        cout << "starting point:\t" << s << endl;
        PrintShortest(shortest);
        PrintPred(pred);
        cout << endl << endl;
    }
}
