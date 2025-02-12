/*
 * CSC-301
 * project1.cpp
 * Spring 2025
 *
 * Partner 1:
 * Partner 2:
 * Date:
 */

#include "project1.hpp"

using namespace std;

/*
 * selectionSort
 */
void selectionSort(vector<double> &arrayToSort) {
    int n = arrayToSort.size(); // Get the size of the array

    // Iterate over each position in the array (except for the last one)
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;   // Assume the current element is the smallest

        // Find the smallest element in the remaining unsorted portion
        for (int j = i + 1; j < n; ++j) {
            if (arrayToSort[j] < arrayToSort[minIndex]) {
                minIndex = j;   // Update minIndex if a smaller element is found
            }
        }

        // Swap the minimum element with the first unsorted element
        if (minIndex != i) {
            std::swap(arrayToSort[i], arrayToSort[minIndex]);
       }
    }
}

/*
 * insertionSort
 */
void insertionSort(vector<double> &arrayToSort) {
    int n = arrayToSort.size(); // Get the size of the array

    // Iterate through the elements in the array (starting from the second element)
    for (int i = 1; i < n; ++i) {
        double key = arrayToSort[i];    // Current element to be sorted
        int j = i - 1;

        // Move elements that are greater than key one position ahead
        while (j >= 0 && arrayToSort[j] > key) {
            arrayToSort[j + 1] = arrayToSort[j];
            --j;
        }

        // Insert the key into its correct position
        arrayToSort[j + 1] = key;
    }
}

/*
 * bubbleSort
 */
void bubbleSort(vector<double> &arrayToSort) {
    return;
}

/*
 * mergeSort
 */
void mergeSort(vector<double> &arrayToSort) {
    return;
}

/*
 * quickSortHelper
 * 
 * Note that i is inclusive (i.e., is the first element of subarray).
 * Note that j is not inclusive (i.e., off the end of the subarray).
 * 
 */
void quickSortHelper(vector<double> &arrayToSort, int i, int j) {
    if (i < j - 1) {    // Base Case: only proceed if more than one element in the partition
        // Choose the pivot (last element of the partition)
        double pivot = arrayToSort[j - 1];
        int left = i;   // Pointer for elements smaller than the pivot

        // Partition the array
        for (int k = i; k < j; ++k) {
            if (arrayToSort[k] < pivot) {
                std::swap(arrayToSort[k], arrayToSort[left]);
                ++left;
            }
        }

        // Place the pivot in its correct position
        std::swap(arrayToSort[left], arrayToSort[j - 1]);

        // Recursively apply Quick Sort to left and right partitions
        quickSortHelper(arrayToSort, i, left);      // Left partition
        quickSortHelper(arrayToSort, left + 1, j);  // Right partition
    }
}

/*
 * quickSort
 */
void quickSort(vector<double> &arrayToSort) {
    quickSortHelper(arrayToSort, 0, arrayToSort.size());
}
