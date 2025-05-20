#include <stdio.h>

int n, a[10][10], res[10], s[10], top = 0;

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    dfs_top(n, a);

    printf("Topological Ordering of the vertices:\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}

void dfs_top(int n, int a[][10]) {
    for (int i = 0; i < n; i++) {
        s[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == 0) {
            dfs(i, n, a);
        }
    }
}

void dfs(int j, int n, int a[][10]) {
    s[j] = 1;
    for (int i = 0; i < n; i++) {
        if (a[j][i] == 1 && s[i] == 0) {
            dfs(i, n, a);
        }
    }
    res[top++] = j;
}
