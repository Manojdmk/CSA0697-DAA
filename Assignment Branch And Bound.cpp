#include <stdio.h>
#include <limits.h>

#define N 4

int costMatrix[N][N] = {
    {9, 2, 7, 8},
    {6, 4, 3, 7},
    {5, 8, 1, 8},
    {7, 6, 9, 4}
};

int minCost(int job, int visited, int dp[]) {
    if (visited == (1 << N) - 1) {
        return 0;
    }

    if (dp[visited] != -1) {
        return dp[visited];
    }

    int min = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (!(visited & (1 << i))) {
            min = (min < costMatrix[job][i] + minCost(job + 1, visited | (1 << i), dp)) ? min : costMatrix[job][i] + minCost(job + 1, visited | (1 << i), dp);
        }
    }

    return dp[visited] = min;
}

int main() {
    int dp[1 << N];
    for (int i = 0; i < (1 << N); i++) {
        dp[i] = -1;
    }

    printf("Minimum cost is %d\n", minCost(0, 0, dp));

    return 0;
}
