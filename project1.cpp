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
    return;
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
    return;
}

/*
 * quickSort
 */
void quickSort(vector<double> &arrayToSort) {
    quickSortHelper(arrayToSort, 0, arrayToSort.size());
    return;
}
