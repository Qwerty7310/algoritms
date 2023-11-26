#include "FloydWarshall.h"

void FloydWarshall(int G[][N])
{
    cout << "\t\tFLOYD-WARSHALL\n";
    int shortest[N][N];
    int pred[N][N];

    for (int u = 0; u < N; u++)
        for (int v = 0; v < N; v++)
        {
            shortest[u][v] = G[u][v];
            if (G[u][v] != INT_MAX) pred[u][v] = u;
            else pred[u][v] = -1;
        }

    for (int i = 0; i < N; i++)
        shortest[i][i] = 0;

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                if (shortest[i][k] != INT_MAX && shortest[k][j] != INT_MAX && shortest[i][j] > shortest[i][k] + shortest[k][j])
                {
                    shortest[i][j] = shortest[i][k] + shortest[k][j];
                    pred[i][j] = k;
                }
            }
    cout << "shortest[]:\n";
    for (int u = 0; u < N; u++)
    {
        for (int v = 0; v < N; v++)
            if (shortest[u][v] != INT_MAX) cout << shortest[u][v] << '\t';
            else cout << "inf\t";
        cout << endl;
    }

    cout << "\npred[]:\n";
    for (int u = 0; u < N; u++)
    {
        for (int v = 0; v < N; v++)
            cout << pred[u][v] << '\t';
        cout << endl;
    }
}

/*
void FloydWarshall(int G[N][N])
{
    cout << "\t\tFLOYD-WARSHALL\n";
    int shortest[N][N][N+1];
    int pred[N][N][N+1];

    for (int u = 0; u < N; u++)
        for (int v = 0; v < N; v++)
        {
            shortest[u][v][0] = G[u][v];
            if (G[u][v] != INT_MAX) pred[u][v][0] = u;
            else pred[u][v][0] = -1;
        }

    for (int i = 0; i < N; i++)
        shortest[i][i][0] = 0;

    for (int x = 1; x <= N; x++)
        for (int u = 0; u < N; u++)
            for (int v = 0; v < N; v++)
            {
//                if (shortest[x][v][x-1] != INT_MAX && shortest[u][x][x-1] != INT_MAX && shortest[u][v][x] > shortest[u][x][x-1] + shortest[x][v][x-1])
//                {
//                    shortest[u][v][x] = shortest[u][x][x-1] + shortest[x][v][x-1];
//                    pred[u][v][x] = pred[u][v][x-1];
//                }
//                else
//                {
//                    shortest[u][v][x] = shortest[u][v][x-1];
//                    pred[u][v][x] = pred[u][v][x-1];
//                }
                if (shortest[x-1][v][x-1] != INT_MAX && shortest[u][x-1][x-1] != INT_MAX && shortest[u][v][x] > shortest[u][x-1][x-1] + shortest[x-1][v][x-1])
                {
                    shortest[u][v][x] = shortest[u][x-1][x-1] + shortest[x-1][v][x-1];
                    pred[u][v][x] = pred[u][v][x-1];
                }
                else
                {
                    shortest[u][v][x] = shortest[u][v][x-1];
                    pred[u][v][x] = pred[u][v][x-1];
                }
            }
    cout << "shortest1[]:\n";
    for (int u = 0; u < N; u++)
    {
        for (int v = 0; v < N; v++)
            if (shortest[u][v][N] != INT_MAX) cout << shortest[u][v][N] << '\t';
            else cout << "inf\t";
        cout << endl;
    }



/*
    cout << "\t\tFLOYD-WARSHALL\n";
    int shortest1[N+1][N+1][(N+1)+1] = {};
    int pred1[N+1][N+1][(N+1)+1] = {};

    for (int u = 1; u <= N; u++)
        for (int v = 1; v <= N; v++)
        {
            shortest1[u][v][0] = G[u-1][v-1];
            if (G[u-1][v-1] != INT_MAX) pred1[u][v][0] = u;
            else pred1[u][v][0] = -1;
        }
    for (int i = 1; i <= N; i++)
        shortest1[i][i][0] = 0;

    for (int x = 1; x <= N; x++)
        for (int u = 1; u <= N; u++)
            for (int v = 1; v <= N; v++)
            {
                if (shortest1[x][v][x-1] != INT_MAX && shortest1[u][x][x-1] != INT_MAX && shortest1[u][v][x] > shortest1[u][x][x-1] + shortest1[x][v][x-1])
                {
                    shortest1[u][v][x] = shortest1[u][x][x-1] + shortest1[x][v][x-1];
                    pred1[u][v][x] = pred1[u][v][x-1];
                }
                else
                {
                    shortest1[u][v][x] = shortest1[u][v][x-1];
                    pred1[u][v][x] = pred1[u][v][x-1];
                }
            }
    cout << "shortest[]:\n";
    for (int u = 1; u <= N; u++)
    {
        for (int v = 1; v <= N; v++)
            if (shortest1[u][v][N] != INT_MAX) cout << shortest1[u][v][N] << '\t';
            else cout << "inf\t";
        cout << endl;
    }
}*/