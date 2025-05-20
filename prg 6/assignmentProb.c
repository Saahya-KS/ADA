#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

int cost[SIZE][SIZE] = {
    {9, 2, 7},
    {6, 4, 3},
    {5, 8, 1}
};

int minCost = 9999;
int best[SIZE];

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void calculateCost(int perm[]) {
    int total = 0;
    for (int i = 0; i < SIZE; i++)
        total += cost[i][perm[i]];

    if (total < minCost) {
        minCost = total;
        for (int i = 0; i < SIZE; i++)
            best[i] = perm[i];
    }
}

void generatePermutations(int perm[], int l, int r) {
    if (l == r)
        calculateCost(perm);
    else {
        for (int i = l; i <= r; i++) {
            swap(&perm[l], &perm[i]);
            generatePermutations(perm, l + 1, r);
            swap(&perm[l], &perm[i]);
        }
    }
}

void main() {
    int perm[SIZE] = {0, 1, 2};
    generatePermutations(perm, 0, SIZE - 1);

    printf("Minimum Cost: %d\n", minCost);
    printf("Best Assignment:\n");
    for (int i = 0; i < SIZE; i++)
        printf("Person %d assigned to Job %d\n", i, best[i]);
}
