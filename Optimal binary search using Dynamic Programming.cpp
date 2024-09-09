#include <stdio.h>
#include <limits.h>

int main() {
    int n = 4;
    int keys[] = {10, 12, 20, 35}; // Example keys
    int freq[] = {34, 8, 50, 21};  // Example frequencies
    int cost[n][n];

    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i]; // cost for single key

    for (int L = 2; L <= n; L++) { // L is the chain length
        for (int i = 0; i <= n - L + 1; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;
            int sum = 0;

            for (int k = i; k <= j; k++)
                sum += freq[k];

            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) + ((r < j) ? cost[r + 1][j] : 0) + sum;
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }

    printf("Optimal cost of the binary search tree is: %d\n", cost[0][n - 1]);
    return 0;
}
