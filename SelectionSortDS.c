#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Selection Sort function
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted part
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Function to generate random integers and measure sorting time
void measureSortTimes() {
    int sizes[] = {5000, 10000, 15000, 20000, 25000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);
    double times[numSizes];

    for (int i = 0; i < numSizes; i++) {
        int n = sizes[i];
        int *arr = (int *)malloc(n * sizeof(int));

        // Generate random elements
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % 100000;
        }

        clock_t start = clock();
        selectionSort(arr, n);
        clock_t end = clock();

        times[i] = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Sorted %d elements in %.4f seconds.\n", n, times[i]);

        free(arr);
    }

    // Plot results using a simple text-based representation
    printf("\nSelection Sort Time Complexity Analysis\n");
    printf("Number of Elements (n) vs Time Taken (seconds)\n");
    for (int i = 0; i < numSizes; i++) {
        printf("%d elements: %.4f seconds\n", sizes[i], times[i]);
    }
}

int main() {
    srand(time(0));

    printf("Brute Force Analysis of Selection Sort:\n");
    printf("Best Case: O(n^2) - The algorithm always iterates over all elements.\n");
    printf("Worst Case: O(n^2) - The algorithm always iterates over all elements.\n");
    printf("Average Case: O(n^2) - The same number of operations as the worst case.\n\n");





    #OUTPUT IS 
    Brute Force Analysis of Selection Sort:
Best Case: O(n^2) - The algorithm always iterates over all elements.
Worst Case: O(n^2) - The algorithm always iterates over all elements.
Average Case: O(n^2) - The same number of operations as the worst case.

Sorted 5000 elements in 0.0220 seconds.
Sorted 10000 elements in 0.0840 seconds.
Sorted 15000 elements in 0.2050 seconds.
Sorted 20000 elements in 0.3650 seconds.
Sorted 25000 elements in 0.5330 seconds.

Selection Sort Time Complexity Analysis
Number of Elements (n) vs Time Taken (seconds)
5000 elements: 0.0220 seconds
10000 elements: 0.0840 seconds
15000 elements: 0.2050 seconds
20000 elements: 0.3650 seconds
25000 elements: 0.5330 seconds

    measureSortTimes();

    return 0;
}
