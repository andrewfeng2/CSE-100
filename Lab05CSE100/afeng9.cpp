//Radixsort
//chmod 700 Grade

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// Function to perform RadixSort on a vector of vectors
void radixSort(vector<vector<int>>& arr) {
    const int DIGITS = 10;  // Number of digits in each vector
    const int BASE = 4;     // Base of the number system (0, 1, 2, 3)

    // Iterate through each digit, starting from the least significant (rightmost)
    for (int digit = DIGITS - 1; digit >= 0; digit--) {
        vector<queue<vector<int>>> buckets(BASE);

        // Distribute vectors into buckets based on the current digit
        for (const auto& vec : arr) {
            int index = vec[digit];  // Get the value of the current digit
            buckets[index].push(vec);  // Place the vector in the corresponding bucket
        }

        // Collect vectors from buckets in order, effectively sorting by the current digit
        arr.clear();
        for (int i = 0; i < BASE; i++) {
            while (!buckets[i].empty()) {
                arr.push_back(buckets[i].front());
                buckets[i].pop();
            }
        }
    }
}

int main() {
    int n;
    cin >> n;  // Read the number of vectors

    vector<vector<int>> vectors(n, vector<int>(10));  // Create a 2D vector to store input

    // Read input vectors
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> vectors[i][j];  // Read each element of the vector
        }
    }

    // Perform RadixSort on the vectors
    radixSort(vectors);

    // Print sorted vectors
    for (const auto& vec : vectors) {
        for (int i = 0; i < 10; i++) {
            cout << vec[i];
            if (i < 9) cout << ";";  // Add semicolon between elements, except for the last one
        }
        cout << ";" << endl;  // Add semicolon and newline after each vector
    }

    return 0;
}
