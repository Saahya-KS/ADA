#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n], value[n];

    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &weight[i]);
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &value[i]);
    }

    printf("Enter maximum capacity of knapsack: ");
    scanf("%d", &W);

    int maxVal = 0;
    int totalComb = 1 << n;
    int bestSet = 0;

    for (int i = 0; i < totalComb; i++) {
        int totalWeight = 0, totalValue = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                totalWeight += weight[j];
                totalValue += value[j];
            }
        }
        if (totalWeight <= W && totalValue > maxVal) {
            maxVal = totalValue;
            bestSet = i;
        }
    }

    printf("\nBest subset of items:\n");
    for (int j = 0; j < n; j++) {
        if (bestSet & (1 << j)) {
            printf("Item %d (Weight: %d, Value: %d)\n", j + 1, weight[j], value[j]);
        }
    }

    printf("Maximum value: %d\n", maxVal);
}
