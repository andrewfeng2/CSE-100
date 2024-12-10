#include <iostream>
#include <vector>

using namespace std;

// Function to print the first k elements of an array
void printArray(const vector<int>& arr, int k) {
    for (int i = 0; i < k; i++) {
        cout << arr[i] << ";";
    }
    cout << endl;
}

// Implementation of Insertion Sort algorithm
void insertionSort(vector<int>& arr) {
    // Iterate through the array starting from the second element
    for (int i = 1; i < arr.size(); i++) {
        // Store the current element to be inserted
        int current = arr[i];
        // Start comparing with the previous element
        int j = i - 1;
        
        // Move elements greater than current to one position ahead
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }
        // Insert the current element in its correct position
        arr[j + 1] = current;
          
        // Print the partially sorted array after each iteration
        printArray(arr, i + 1);
    }
}

int main() {
    // Read the size of the array
    int size;
    cin >> size;
    
    // Create a vector to store the input numbers
    vector<int> numbers(size);
    // Read the input numbers
    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
    }

    // Sort the array using Insertion Sort
    insertionSort(numbers);
    
    return 0;
}
