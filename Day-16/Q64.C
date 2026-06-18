#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 2, 4, 5, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array after removing duplicates: ");

    for (int i = 0; i < n; i++) {
        int isDuplicate = 0;

        // Check if current element has appeared before
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = 1;
                break;
            }
        }

        // Print only if it's not a duplicate
        if (!isDuplicate) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}