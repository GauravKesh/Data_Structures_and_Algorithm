//
// Created by Gaurav Kesh Roushan on 29/01/24.
//
#include <iostream>
#include <algorithm>

using namespace std;

void printReversedArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
}

void reverseArray(int arr[], int k) {
    int n = k;
    int reversed_array[n];

    for (int i = n - 1; i >= 0; i--) {
        reversed_array[n - i - 1] = arr[i];
    }
    printReversedArray(reversed_array, n);

}

void spaceOptmisedReverse(int arr[], int k) {
    int n = k;
    int p1 = 0; // pointer 1;
    int p2 = n - 1; // pointer 2;
    while (p1 < p2) {
        swap(arr[p1], arr[p2]);
        p1++;
        p2--;
    }
    printReversedArray(arr, n);

}

// doubt
void recursiveReverseMethod(int arr[], int start, int end) {
    if (start < end) {
        swap(arr[start], arr[end]);
        recursiveReverseMethod(arr, start + 1, end - 1);
    }

}

void libReverseArray(int arr[],int n) {
    //Reversing elements from index 0 to n-1
    reverse(arr,arr+n);


}

int main() {
    int n = 4;
    int arr[] = {4, 3, 2, 1};
//    reverseArray(arr, n);
//    spaceOptmisedReverse(arr,n);
//    recursiveReverseMethod(arr,0,n-1);
    libReverseArray(arr, n);
    printReversedArray(arr, n);

    return 0;
}