//
// Created by Gaurav Kesh Roushan on 31/01/24.
//

#include <iostream>

using namespace std;

/// Selection Sort
void selection_sort(int arr[], int as) {
    for (int i = 0; i <= as - 2; i++) {
        int mini = i;
        for (int j = i; j <= as - 1; j++) {
            // approach one
//            if (arr[mini] < arr[j]) {
//                swap(arr[mini],arr[j]);
//            }
            // approach 2
            if (arr[j] < arr[mini]) {
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
    for (int j = 0; j < as; j++) {
        cout << arr[j] << " ";
    }
}

/// Bubble Sort
void bubble_sort(int arr[], int as) {
    for (int i = as - 1; i >= 1; i--) {
        int didSwap = 0;
        for (int j = 0; j <= i - 1; j++) {
            int temp = arr[j];
            if (arr[j] > arr[j + 1]) {
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                didSwap++;
            }
        }
        if (didSwap == 0) {
            break;
        }
        cout << "runs\n";
    }

}

/// Insertion sort
void insertion_sort(int arr[], int as) {
    for (int i = 0; i < as; i++) {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1]) {
            int temp = arr[j-1];
            arr[j-1] =arr[j];
            arr[j] = temp;
            j--;
        }
    }
}


int main() {

    int arr[] = {5, 6, 8, 1, -1, 100, 2, 3, 55, 10};
    int arr_sort[] = {1, 2, 3, 4, 5, 6};

    int as = sizeof(arr) / sizeof(arr[0]);
    int ass = sizeof(arr_sort) / sizeof(arr_sort[0]);

//    selection_sort(arr, as);
//    bubble_sort(arr_sort, ass);
    insertion_sort(arr, as);

    // printing the array after sorting;
    for (int j = 0; j <= as-1; j++) {
        cout << arr[j] << " ";
    }
    return 0;
}