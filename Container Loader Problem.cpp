#include <stdio.h>

int main() {
    int containers[100], weights[100], capacity, n;

    printf("Enter the capacity of the loader: ");
    scanf("%d", &capacity);

    printf("Enter the number of containers: ");
    scanf("%d", &n);

    printf("Enter the weights of the containers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    for (int i = 0; i < n; i++) {
        containers[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (capacity >= weights[i]) {
            containers[i] = 1;
            capacity -= weights[i];
        }
    }

    printf("Containers loaded: ");
    for (int i = 0; i < n; i++) {
        if (containers[i]) {
            printf("%d ", weights[i]);
        }
    }

    return 0;
}
