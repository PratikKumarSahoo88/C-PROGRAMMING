
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to generate random numbers
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
}

// Function to measure execution time
void measureTime(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    generateRandomArray(arr, n);
    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();
    printf("n = %d, Time taken = %f seconds\n", n, ((double)(end - start)) / CLOCKS_PER_SEC);
    free(arr);
}

int main() {
    srand(time(0)); // Seed random number generator
    int sizes[] = {5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    
    printf("Quick Sort Performance Analysis:\n");
    for (int i = 0; i < num_sizes; i++) {
        measureTime(sizes[i]);
    }
    return 0;
}
