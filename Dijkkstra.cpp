#include "Dijkkstra.h"

void Dijkstra(int G[N][N], int s, int f)
{
    cout << "\t\tDIJKSTRA\n";
    int visited[N] = {};

    int shortest[N] = {};
    int pred[N];

    for (int i = 0; i < N; i++)
    {
        shortest[i] = INT_MAX;
        pred[i] = -1;
    }
    shortest[s] = 0;

    int min = INT_MAX;
    int min_index;
    for (int i = 0; i < N; i++)
    {
        min = INT_MAX;
        for (int j = 0; j < N; j++)
        {
            if (visited[j] == 0 && shortest[j] < min)
            {
                min = shortest[j];
                min_index = j;
            }
        }
        for (int j = 0; j < N; j++)
        {
            if (G[min_index][j] != -1 && shortest[j] > shortest[min_index] + G[min_index][j]) {
                shortest[j] = shortest[min_index] + G[min_index][j];
                pred[j] = min_index;
            }
        }
        visited[min_index] = 1;
    }

    cout << "starting point:\t" << s << endl;
    PrintShortest(shortest);
    PrintPred(pred);

    if (f >= 0)
    {
        int cur = f;
        list *head = new list;
        head->number = cur;
        while (cur != s && pred[cur] != -1)
        {
            cur = pred[cur];
            list *temp = new list;
            temp->number = cur;
            temp->next = head;
            head = temp;
        }
        cout << "\nPath from " << s << " to " << f << ": ";
        if (pred[cur] == -1 && cur != s) cout << "the path is missing";
        else
        {
            cout << s;
            list *p = head->next;
            while (p != nullptr)
            {
                cout << " -> " << p->number;
                p = p->next;
            }
        }
    }
    cout << endl << endl;
}