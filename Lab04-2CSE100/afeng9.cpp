#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to partition the array
int partition(vector<int>& A, int p, int r) {
    // Choose a random pivot to improve average-case performance
    int random_index = p + rand() % (r - p + 1);
    swap(A[random_index], A[r]);

    int pivot = A[r];  // Use the last element as the pivot
    int i = p - 1;  // Index of the smaller element

    // Partition the array around the pivot
    for (int j = p; j < r; j++) {
        if (A[j] <= pivot) {
            i++;  // Increment index of smaller element
            swap(A[i], A[j]);  // Swap elements
        }
    }
    swap(A[i + 1], A[r]);  // Place the pivot in its correct position
    return i + 1;  // Return the partition index
}

// Recursive Quick-sort function
void quickSort(vector<int>& A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);  // Partition the array
        quickSort(A, p, q - 1);  // Recursively sort the left subarray
        quickSort(A, q + 1, r);  // Recursively sort the right subarray
    }
}

int main() {
    // Seed the random number generator for choosing random pivots
    srand(time(0));

    int n;
    cin >> n;  // Read the number of elements

    vector<int> A(n);
    // Read n integers
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    quickSort(A, 0, n - 1);

    // Output the sorted array
    for (int i = 0; i < n; i++) {
        cout << A[i] << ";";
    }

    return 0;
}
