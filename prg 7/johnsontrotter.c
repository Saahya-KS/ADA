#include <stdio.h>
#include <stdlib.h>

#define LEFT -1
#define RIGHT 1

int getMobile(int perm[], int dir[], int n) {
    int mobile = 0;
    for (int i = 0; i < n; i++) {
        int next = i + dir[i];
        if (next >= 0 && next < n && perm[i] > perm[next]) {
            if (perm[i] > mobile)
                mobile = perm[i];
        }
    }
    return mobile;
}

int getIndex(int perm[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (perm[i] == value)
            return i;
    }
    return -1;
}

void printPerm(int perm[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", perm[i]);
    printf("\n");
}

void johnsonTrotter(int n) {
    int perm[n], dir[n];

    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = LEFT;
    }

    printPerm(perm, n);

    while (1) {
        int mobile = getMobile(perm, dir, n);
        if (mobile == 0)
            break;

        int pos = getIndex(perm, n, mobile);
        int swapWith = pos + dir[pos];

        int temp = perm[pos];
        perm[pos] = perm[swapWith];
        perm[swapWith] = temp;

        temp = dir[pos];
        dir[pos] = dir[swapWith];
        dir[swapWith] = temp;

        pos = swapWith;

        for (int i = 0; i < n; i++) {
            if (perm[i] > mobile)
                dir[i] = -dir[i];
        }

        printPerm(perm, n);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 10) {
        printf("Please enter a number between 1 and 10 for simplicity.\n");
        return 1;
    }

    printf("\nPermutations using Johnson–Trotter algorithm:\n");
    johnsonTrotter(n);

    return 0;
}
