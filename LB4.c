#include <stdio.h>

int countDuplicates(int arr[], int size) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                break;  
            }
        }
    }
    return count;
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 5, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Total number of duplicate elements: %d\n", countDuplicates(arr, size));

    return 0;
}
