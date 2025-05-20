#include <stdio.h>

int n = 5;
int weights[10] = {10, 15, 10, 12, 8};
int values[10] = {3, 3, 2, 5, 1};
int capacity = 10;

int main() {
    int i, maxi;
    int used[10];
    int cur_w = capacity;
    float tot_v = 0.0;

    for (i = 0; i < n; ++i)
        used[i] = 0;

    while (cur_w > 0) {
        maxi = -1;
        for (i = 0; i < n; ++i) {
            if (!used[i]) {
                if (maxi == -1 || (float)values[i] / weights[i] > (float)values[maxi] / weights[maxi]) {
                    maxi = i;
                }
            }
        }

        if (maxi == -1) break;

        used[maxi] = 1;

        if (weights[maxi] <= cur_w) {
            cur_w -= weights[maxi];
            tot_v += values[maxi];
            printf("Added object %d (%d value, %d weight) completely. Space left: %d.\n",
                   maxi + 1, values[maxi], weights[maxi], cur_w);
        } else {
            float fraction = (float)cur_w / weights[maxi];
            tot_v += values[maxi] * fraction;
            printf("Added %.2f%% of object %d (%d value, %d weight).\n",
                   fraction * 100, maxi + 1, values[maxi], weights[maxi]);
            cur_w = 0;
        }
    }

    printf("Filled the bag with objects worth %.2f value.\n", tot_v);
    return 0;
}
