//
// Created by Gaurav Kesh Roushan on 07/04/24.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

void subArrayBrute(vector<int> &arr, int target) {
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k < j; k++) {
                sum += arr[k];
            }
            if (sum == target) {
                count++;
            }
        }

    }
    cout << count << endl << " .....";
}

void subArrayBetter(vector<int> &arr, int target) {
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            sum += arr[j];
            cout << sum << " ";
            if (sum == target) {
                cout << endl << sum << endl;
                count++;
            }
        }

    }
    cout << endl << count;
}

void subArrayOptimal(vector<int> &arr, int k) {
    // Create a map to store prefix sum frequencies
    map<int, int> mpp;
    // Get the size of the input array
    int n = arr.size();
    // Initialize prefix sum as 0 and its count as 0
    mpp[0] = 1;
    int preSum = 0, cnt = 0;
    // Iterate through each element of the array
    for (int i = 0; i < n; i++) {
        // Calculate prefix sum by adding the current element to previous prefix sum
        preSum += arr[i];
        // Calculate the value to be removed to achieve the desired sum
        int remove = preSum - k;
        // Increment the count by the frequency of the 'remove' value in the map
        cnt += mpp[remove];
        // Increment the frequency of the current prefix sum in the map
        mpp[preSum] += 1;

    }
    // Return the count of subarrays with the given sum
    cout << cnt;
}


int main() {


    int target = 3;
    vector<int> arr3 = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};

//    setZeroMatrix_better(arr1);
//    subArrayBrute(arr3, target);
//    subArrayBetter(arr3, target);
    subArrayOptimal(arr3, target);

}