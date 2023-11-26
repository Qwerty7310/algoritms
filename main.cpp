#include "Dijkkstra.h"
#include "BellmanFord.h"
#include "FloydWarshall.h"

int main() {
    system("chcp 65001"); //подключение русского языка
    system("cls"); //очистка консоли
    int matrixDijkstra[N][N] = {
            -1,6,8,18,-1,-1,
            -1,-1,-1,-1,11,-1,
            -1,-1,-1,9,-1,-1,
            -1,-1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,3,
            -1,-1,7,4,-1,-1,
    };

    /*int matrixDijkstra[N][N] = {
            -1,3,4,2,-1,-1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,3,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,6,-1,-1,-1,-1,
            -1,-1,-1,-1,5,2,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,-1,6,-1,12,-1,
            -1,-1,-1,-1,1,-1,8,7,-1,-1,
            -1,-1,-1,-1,-1,-1,-1,-1,-1,4,
            -1,-1,-1,-1,-1,-1,-1,-1,-1,3,
            -1,-1,-1,-1,-1,-1,-1,6,-1,11,
            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    };*/

    int matrixBF[N][N] = {
            INT_MAX,6,8,18,INT_MAX,INT_MAX,
            INT_MAX,INT_MAX,INT_MAX,INT_MAX,11,INT_MAX,
            INT_MAX,INT_MAX,INT_MAX,9,INT_MAX,INT_MAX,
            INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,
            INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,3,
            INT_MAX,INT_MAX,7,4,INT_MAX,INT_MAX,
    };

    int matrixFW[N][N] = {
            INT_MAX,6,8,18,INT_MAX,INT_MAX,
            INT_MAX,INT_MAX,INT_MAX,INT_MAX,11,INT_MAX,
            INT_MAX,INT_MAX,INT_MAX,9,INT_MAX,INT_MAX,
            INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,
            INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,3,
            INT_MAX,INT_MAX,7,4,INT_MAX,INT_MAX,
    };

    int src = 1;
    Dijkstra(matrixDijkstra, 0, 5);
//    BellmanFord(matrixBF, src);
    FloydWarshall(matrixFW);

    cout << endl;

    system("PAUSE");
    return 0;
}
