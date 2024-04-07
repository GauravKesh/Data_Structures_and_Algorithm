//
// Created by Gaurav Kesh Roushan on 05/02/24.
//
#include <iostream>
#include <vector>

using namespace std;

// brute force
void shiftZeroes(vector<int> &arr, int n) {
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            temp.push_back(arr[i]);
        }
    }
    for (int i = 0; i < temp.size(); i++) {
        arr[i] = temp[i];
    }
    for (int i = temp.size(); i < n; i++) {
        arr[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";

    }
}

void shiftZeroesOptimal(vector<int> &arr, int n) {
    /// checking if number is zero or not
    int j = -1;
    for (int i = 1; i < n; i++) {
        if (arr[i]==0){
            j=i;
        }
    }
    // swapping non-zero
    for(int i =j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[j],arr[i]);
        }
        j++;
    }
    // printing array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";

    }
}

int main() {
//    vector<int> arr = {1,0,69,0,0,0,7,8,9,4,0,0,5,6,};
    vector<int> arr = {4, 0, 3, 2, 5};
    int n = arr.size();
//    shiftZeroes(arr, n);
    shiftZeroesOptimal(arr,n);
}