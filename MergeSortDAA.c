#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Merge function to combine two sorted halves
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Function to generate random numbers and sort them
void runExperiment() {
    int sizes[] = {5000, 10000, 20000, 40000, 80000, 160000};
    double times[6];

    for (int i = 0; i < 6; i++) {
        int n = sizes[i];
        int *arr = (int *)malloc(n * sizeof(int));

        // Generate random numbers
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % 1000000;
        }

        // Measure execution time
        clock_t start = clock();
        mergeSort(arr, 0, n - 1);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        times[i] = time_taken;
        printf("Sorted %d elements in %.5f seconds\n", n, time_taken);

        free(arr);
    }

    // Save results to file for Python plotting
    FILE *file = fopen("merge_sort_times.txt", "w");
    for (int i = 0; i < 6; i++) {
        fprintf(file, "%d %.5f\n", sizes[i], times[i]);
    }
    fclose(file);
}

int main() {
    srand(time(0));
    runExperiment();
    printf("Sorting times recorded");
    return 0;
}
