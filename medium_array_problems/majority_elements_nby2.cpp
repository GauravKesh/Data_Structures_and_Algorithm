//
// Created by Gaurav Kesh Roushan on 10/02/24.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;

// searching each element in the array;
void majorityElements_brute(vector<int> &nums) {
    int n = nums.size();
    int x;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int tempn = nums[i];
        for (int j = 1; j < n; j++) {
            if (tempn == nums[j]) {
                count++;
            }
        }
        if (count > n / 2) {
            x = tempn;
        }
    }
    cout << x;
}


// using hashing
void majorityElements_better(vector<int> &nums) {
    map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++) {
        mpp[nums[i]]++;
    }
    for (auto it: mpp) {
        if (it.second > (nums.size() / 2)) {
            cout << it.first << " ";
        }
    }
}

// using more's voting algorithm
int majorityElements_optimal(vector<int> &nums) {
    int ele = nums[0];
    int count = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            ele = nums[i];
            count++;
        } else if ( ele == nums[i]) {
            count++;
        } else {
            count--;
        }
    }
    int cnt =0;
    for(int i =0;i<n;i++){
        if(nums[i]==ele){
            cnt++;}
    }
    if(cnt>n/2){
        return ele;
    }
    return -1;


}

int main() {
    vector<int> nums = {3,2,3};
//    majorityElements_brute(nums);
//    majorityElements_better(nums);
    int num =majorityElements_optimal(nums);
    cout<<num;


}
