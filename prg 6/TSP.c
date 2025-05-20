#include <stdio.h>
#include <stdlib.h>

#define N 4
int dist[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int minCost = 9999;
int bestPath[N + 1];

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void calculateCost(int path[]) {
    int cost = 0;
    for (int i = 0; i < N - 1; i++)
        cost += dist[path[i]][path[i + 1]];
    cost += dist[path[N - 1]][path[0]];

    if (cost < minCost) {
        minCost = cost;
        for (int i = 0; i < N; i++)
            bestPath[i] = path[i];
        bestPath[N] = path[0];
    }
}

void generatePermutations(int path[], int l, int r) {
    if (l == r)
        calculateCost(path);
    else {
        for (int i = l; i <= r; i++) {
            swap(&path[l], &path[i]);
            generatePermutations(path, l + 1, r);
            swap(&path[l], &path[i]);
        }
    }
}

void main() {
    int path[N] = {0, 1, 2, 3};
    generatePermutations(path + 1, 0, N - 2);

    printf("Minimum cost: %d\n", minCost);
    printf("Best path: ");
    for (int i = 0; i <= N; i++)
        printf("%d ", bestPath[i]);
    printf("\n");
}
