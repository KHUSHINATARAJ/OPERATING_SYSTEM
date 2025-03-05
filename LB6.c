#include <stdio.h>

int secondLargest(int arr[], int size) {
    int largest = -1, secondLargest = -1;

    for (int i = 0; i < size; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}

int main() {
    int arr[] = {10, 20, 4, 45, 99};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Second largest element is: %d\n", secondLargest(arr, size));

    return 0;
}
