#include <stdio.h>

int n, colors[20], graph[20][20], m;

int isSafe(int v, int c) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && c == colors[i]) {
            return 0;
        }
    }
    return 1;
}

int graphColoring(int v) {
    if (v == n) {
        return 1;
    }
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            colors[v] = c;
            if (graphColoring(v + 1)) {
                return 1;
            }
            colors[v] = 0;
        }
    }
    return 0;
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    if (graphColoring(0)) {
        printf("Solution exists: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", colors[i]);
        }
    } else {
        printf("No solution exists.");
    }

    return 0;
}
