//chmod 700 Grade
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// struct to hold the result of subbary caclution
struct SubarrayResult {
    int low, high, sum; // initilaize low and high indicies sum is max sum
};


// funciton to find max subarray crossing the midpoint
SubarrayResult findMaxCrossingSubarray(const vector<int>& A, int low, int mid, int high) {
    // fins maximum subarray on left side of midpoint
    int left_sum = INT_MIN;
    int sum = 0;
    int max_left = mid;

    // Iterate from mid to low, finding the maximum sum on the left side
    for (int i = mid; i >= low; i--) {
        sum += A[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }

    // Find max subarray on right side of midpoint
    int right_sum = INT_MIN;
    sum = 0;
    int max_right = mid + 1;

    // Iterate from mid+1 to high, finding the maximum sum on the right side
    for (int i = mid + 1; i <= high; i++) {
        sum += A[i];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = i;
        }
    }

    // Return the combined result of left and right subarrays
    return {max_left, max_right, left_sum + right_sum};
}

// Recursive function to find the maximum subarray
SubarrayResult findMaxSubarray(const vector<int>& A, int low, int high) {
    // Base case: if there's only one element
    if (low == high) {
        return {low, high, A[low]};
    }

    // Calculate the middle point
    int mid = (low + high) / 2;

    // Recursively find max subarray in left half
    SubarrayResult left = findMaxSubarray(A, low, mid);

    // Recursively find max subarray in right half
    SubarrayResult right = findMaxSubarray(A, mid + 1, high);

    // Find max subarray that crosses the midpoint
    SubarrayResult crossing = findMaxCrossingSubarray(A, low, mid, high);

    // Return the subarray with the maximum sum among left, right, and crossing
    if (left.sum >= right.sum && left.sum >= crossing.sum) {
        return left;
    } else if (right.sum >= left.sum && right.sum >= crossing.sum) {
        return right;
    } else {
        return crossing;
    }
}

int main() {
    int n;
    cin >> n;  // Read the number of elements in the array

    vector<int> A(n);
    // Read n integers into the vector A
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Find the maximum subarray in the entire array
    SubarrayResult result = findMaxSubarray(A, 0, n - 1);

    // Output the sum of the maximum subarray
    cout << result.sum;  // Removed endl to eliminate newline
    return 0;
}
