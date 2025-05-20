#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 5000

void quicksort(int[], int, int);
int partition(int[], int, int);

void main() {
    int i, n, a[MAX], ch = 1;
    clock_t start, end;

    while (ch) {
        printf("\nEnter the number of elements\n");
        scanf("%d", &n);

        for (i = 0; i < n; i++)
            a[i] = rand() % 200;

        printf("The random generated array is\n");
        for (i = 0; i < n; i++)
            printf(" %d", a[i]);

        start = clock();
        quicksort(a, 0, n - 1);
        end = clock();

        printf("\n\nThe sorted array elements are\n\n");
        for (i = 0; i < n; i++)
            printf("%d\n", a[i]);

        printf("Time taken = %f", (double)(end - start) / CLOCKS_PER_SEC);

        printf("\n\nDo you wish to continue (0/1)?\n");
        scanf("%d", &ch);
    }
}

void quicksort(int a[], int low, int high) {
    int mid;

    if (low < high) {
        mid = partition(a, low, high);
        quicksort(a, low, mid - 1);
        quicksort(a, mid + 1, high);
    }
}

int partition(int a[], int low, int high) {
    int key, i, j, temp;

    key = a[low];
    i = low + 1;
    j = high;

    while (i <= j) {
        while (i <= high && a[i] <= key)
            i++;

        while (a[j] > key)
            j--;

        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[j];
    a[j] = a[low];
    a[low] = temp;

    return j;
}
