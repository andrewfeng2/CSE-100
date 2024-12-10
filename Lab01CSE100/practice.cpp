#include <iostream>
#include<vector>
using namespace std; 

void printArray(const vector<int>&arr,int k){
    for (int i=0; i<k; i++){
        cout<arr[i]<<";";
    }
    cout<<endl;
}


void insertionSort(vector<int>&arr){
    for(int i=1; i<arr.size(); i++){
        int current = arr[i];
        int j=i-1;

        while (j>=0&&arr[j]>current){
            arr[j+1]=arr[j]
            j--;
        }
        arr[j+1]=current;

        printArray(arr,i+1);

    }
}


int main(){
    int size;
    cin>>size;

    vector<int>numbers(size);
    for(int i=0; i<size; i++){
        cin>>numbers[i]
    }
    insetionSort(numbers);
    return 0; 
}