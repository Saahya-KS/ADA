#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}

void heapsort(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}

int main() {
    int *a, n, ch = 1;
    clock_t start, end;
    double time_taken;

    while (ch) {
        printf("\nEnter the number of elements to sort: ");
        scanf("%d", &n);

        a = (int*)malloc(n * sizeof(int));
        if (a == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Enter the elements to sort:\n");
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        start = clock();
        heapsort(a, n);
        end = clock();

        printf("The sorted list of elements is:\n");
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("\nTime taken: %.6lf seconds\n", time_taken);

        printf("\nDo you want to run again? (1 = Yes / 0 = No): ");
        scanf("%d", &ch);

        free(a);
    }

    return 0;
}
