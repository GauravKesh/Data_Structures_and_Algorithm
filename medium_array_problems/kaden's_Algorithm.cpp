//
// Created by Gaurav Kesh Roushan on 13/02/24.
//
#include <iostream>
#include <vector>

using namespace std;

void max_subarray_brute(vector<int> &arr, int k) {
    int maxi = INT_MIN;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <=j; k++) {
                sum += arr[k];
                maxi = max(sum, maxi);

            }

        }
    }
    cout << maxi;

}

void max_subarray_better(vector<int> &arr, int k) {
    int maxi = INT_MIN;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum +=arr[j];
            maxi=max(sum,maxi);
        }
    }
    cout << maxi;

}

void max_subarray_optimal(vector<int> &arr, int k) {

}

int main() {
    vector<int> nums = {3, 2, 3};
    int sum = 7;
    max_subarray_brute(nums, sum);
//    max_subarray_better(nums, sum);
    max_subarray_optimal(nums, sum);

}
