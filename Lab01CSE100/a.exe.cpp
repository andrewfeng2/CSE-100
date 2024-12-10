#include <iostream>
#include <vector>
#include <limits>

void insertionSort(std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int currentValue = arr[i];
        int previousIndex = i - 1;

        while (previousIndex >= 0 && arr[previousIndex] > currentValue) {
            arr[previousIndex + 1] = arr[previousIndex];
            previousIndex--;
        }
        arr[previousIndex + 1] = currentValue;

        // Print the sorted portion of the array after each iteration
        for (int j = 0; j <= i; j++) {
            std::cout << arr[j] << ";";
        }
        std::cout << std::endl;
    }
}

int main() {
    int size;
    
    // Read the number of elements
    std::cin >> size;

    std::vector<int> array(size);

    // Read the elements
    for (int i = 0; i < size; i++) {
        std::cin >> array[i];
    }

    // Sort the array using insertion sort and print each iteration
    insertionSort(array);

    return 0;
}