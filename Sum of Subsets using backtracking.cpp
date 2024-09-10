#include <stdio.h>

int arr[20], included[20], n, target;

void sumOfSubsets(int index, int currentSum, int total) {
    if (currentSum == target) {
        printf("Subset found: ");
        for (int i = 0; i < n; i++) {
            if (included[i]) {
                printf("%d ", arr[i]);
            }
        }
        printf("\n");
        return;
    }
    if (index == n || currentSum > target) {
        return;
    }
    included[index] = 1;
    sumOfSubsets(index + 1, currentSum + arr[index], total - arr[index]);
    included[index] = 0;
    sumOfSubsets(index + 1, currentSum, total - arr[index]);
}

int main() {
    int total = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        total += arr[i];
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    sumOfSubsets(0, 0, total);

    return 0;
}
