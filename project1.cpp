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
    int n = sizeof(arrayToSort);
    for (int i = 0; i < n; i++) { // loop through two elements
        for (int j = 0; j < n; j++) {
            if (arrayToSort[j] > arrayToSort[j + 1]) { // compare if they are sorted already
                 swap(arrayToSort[i], arrayToSort[i+1]); // swap if they are not
        }
    }
    return;
} }

/*
 * mergeSort
 */
void mergeSort(vector<double> &arrayToSort) {
    double size = sizeof(arrayToSort);   // find array size
    if (size == 1) {
        return; // return array if size is 1
    }   
    else if (size == 2) { // if array size is 2
        if (arrayToSort[0] > arrayToSort[1]) {
            swap(arrayToSort[0], arrayToSort[1]); 
        }
        return;
    }

    int halfway = arrayToSort.size() / 2; // index for the midpoint of the array
    std::vector<double> arrayLeft(arrayToSort.begin(), arrayToSort.begin() + halfway); // split array into two
    std::vector<double> arrayRight(arrayToSort.begin() + halfway, arrayToSort.end());
    mergeSort(arrayLeft); // sort each array
    mergeSort(arrayRight);

    int i = 0, j = 0, k = 0; // indexes for iteration
    while (i < arrayLeft.size() && j < arrayRight.size()) { // iterate through both arrays
        if (arrayLeft[i] <= arrayRight[j]) { // if array element on the first array is smaller 
            arrayToSort[k++] = arrayLeft[i++]; // insert to sorted array
        } 
        else {
            arrayToSort[k++] = arrayRight[j++];
        }
    }

    while (i < arrayLeft.size()) { // copy elements from first array
        arrayToSort[k++] = arrayLeft[i++];
    }
    while (j < arrayRight.size()) { // copy elements from second array
        arrayToSort[k++] = arrayRight[j++];
    }
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
