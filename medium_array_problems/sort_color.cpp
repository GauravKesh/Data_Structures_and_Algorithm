//
// Created by Gaurav Kesh Roushan on 10/02/24.
//
#include <iostream>
#include <vector>

using namespace std;

void sortColors_bruteforce(vector<int> &nums) {
    int n = nums.size();
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
}

void sortColors_better(vector<int> &nums) {
    int n = nums.size();
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            count0++;
        } else if (nums[i] == 1) {
            count1++;
        } else if (nums[i] == 2) {
            count2++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i >= 0 && i < count0) {
            nums[i] = 0;
        } else if (i >= count0 && i < count0 + count1) {
            nums[i] = 1;
        } else if (i >= count0 + count1 && i < n) {
            nums[i] = 2;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
}

/// using DUTCH NATIONAL FLAG ALGORITHM
void sortColors_optimal(vector<int> &nums) {
    int n = nums.size();
    int i = 0, j = 0, k = n - 1;
    int low = 0, mid = 1, high = 2;
    while (j < k) {
        if (nums[j] == high) {
            swap(nums[j], nums[k]);
            k--;
        } else if (nums[j] == mid) {
            j++;
        } else if (nums[j] == low) {
            swap(nums[j], nums[i]);
            j++;
            i++;
        }
    }
    for (int l = 0; l < n; l++) {
        cout << nums[l] << " ";
    }
}
int main() {
    vector<int> nums = {2, 2, 1, 0, 0, 0, 0, 0, 1, 2, 1, 0};
    sortColors_optimal(nums);

}


