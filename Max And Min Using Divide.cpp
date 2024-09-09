#include <iostream>
#include <climits>
using namespace std;

pair<int, int> findMaxMin(int arr[], int low, int high) {
    if (low == high) {
        return {arr[low], arr[low]};
    }
    if (high == low + 1) {
        return {max(arr[low], arr[high]), min(arr[low], arr[high])};
    }

    int mid = (low + high) / 2;
    pair<int, int> left = findMaxMin(arr, low, mid);
    pair<int, int> right = findMaxMin(arr, mid + 1, high);

    return {max(left.first, right.first), min(left.second, right.second)};
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    pair<int, int> result = findMaxMin(arr, 0, n - 1);
    cout << "Maximum: " << result.first << ", Minimum: " << result.second;
    return 0;
}
