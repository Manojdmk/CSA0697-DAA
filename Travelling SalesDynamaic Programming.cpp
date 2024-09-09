#include <stdio.h>
#define INF 99999

int n = 4;
int dist[4][4] = { {0, 10, 15, 20},
                   {10, 0, 35, 25},
                   {15, 35, 0, 30},
                   {20, 25, 30, 0} };
int memo[16][4];

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1)
        return dist[pos][0];

    if (memo[mask][pos] != -1)
        return memo[mask][pos];

    int ans = INF;

    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            if (newAns < ans)
                ans = newAns;
        }
    }

    return memo[mask][pos] = ans;
}

int main() {
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++)
            memo[i][j] = -1;

    printf("Minimum cost: %d\n", tsp(1, 0));
    return 0;
}
