#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j;          // Outer, Inner loop counters
    int minIndex;      // Smallest element index
    int temp;          // Swap variable

    // Outer loop: up to second-last element
    for (i = 0; i < n - 1; i++) {
        minIndex = i;  // Start with current index
        
        // Inner loop: find smallest in unsorted part
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;  // Update smallest index
            }
        }
        
        // Swap
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int arr[] = {17, 34, 25, 49, 9};   // Initial array
    int n = sizeof(arr) / sizeof(arr[0]);  // Array length

    // Display original array
    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    selectionSort(arr, n);  // Sort the array

    // Display sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
