#include<iostream>
#include<vector>
using namespace std;

//Function to merge two sorted subarrays 
void merging(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; //Size of left subarray 
    int n2 = right - mid;  //Size of right one 


    //Create temporary arrays
    vector<int> L(n1), R(n2);

    // Copy elements from the left half of the original array to temporary array L
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];  // Copy from index 'left' to 'mid' of original array

    // Copy elements from the right half of the original array to temporary array R
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];  // Copy from index 'mid+1' to 'right' of original array

    int i = 0, j = 0, k = left;


    //Merge two subbarrays Left and R back into orinal array 
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

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        //Calculate middle point to divide the array into two halves
        int mid = left + (right - left) / 2;

        //Rescursively sort left half 
        mergeSort(arr, left, mid);
        //Recusively sort right half
        mergeSort(arr, mid + 1, right);

        //Merge the two sorted halves
        merging(arr, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> elements(n);

    for (int i = 0; i < n; i++) {
        cin >> elements[i];
    }

    mergeSort(elements, 0, n - 1);

    //output loop
    for (int i = 0; i < n; i++) {
        cout << elements[i];
        cout << ";";  // Always print a semicolon after each element
    }

    return 0;
}


