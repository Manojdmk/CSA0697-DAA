#include <stdio.h>

int main() {
    int n = 5, k = 2; // Example values
    int C[n+1][k+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= (i < k ? i : k); j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }

    printf("Binomial Coefficient C(%d, %d) is: %d\n", n, k, C[n][k]);
    return 0;
}
