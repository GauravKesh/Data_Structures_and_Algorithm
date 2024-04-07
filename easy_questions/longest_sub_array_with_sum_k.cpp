//
// Created by Gaurav Kesh Roushan on 08/02/24.
//
#include<iostream>
#include <vector>
using namespace std;

void subarray_Brute(vector<int> &arr, int n,int k){
    int len = 0;
    for(int i = 0;i<n;i++){
        int sum =0;
        for(int j =i;j<n;j++){
            sum+=arr[j];
            if(sum == k){
                len = max(len,j-i+1);
            }

        }
    }
    cout<<len;
}
void longestSubarrayWithSumK_optimal(vector<int> a, long long k,int n) {
    int right = 0, left = 0;
    long long sum = a[0];
    int maxLen = 0;
//    int n = a.size();
    while (right < n) {
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }
        if (sum == k) {
            maxLen = max(maxLen, right - left+1);
        }
        right++;
        if (right < n) {
            sum += a[right];
        }
    }
    cout<<maxLen;
}

int main(){
    vector<int> arr  = {1,2,3,1,1,1,1,4,2,3};
    int n  = arr.size();
    long long  k  = 3;
//    subarray_Brute(arr,n,k);
    longestSubarrayWithSumK_optimal(arr,k,n);
}