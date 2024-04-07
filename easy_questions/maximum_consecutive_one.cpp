//
// Created by Gaurav Kesh Roushan on 07/02/24.
//
#include <iostream>
#include <vector>
using namespace std;

int maximumConsecutive(vector<int> &arr,int n){
    int count =0;
    int maxi =0;
    int temp =arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            count++;
            maxi =  max(maxi,count);
        }
        else{
            count =0;
        }
    }
    return maxi;
}

int main() {
    vector<int> arr = {1,1,0,1,1,1,1,0,0,0,0,1,1,2,2,2};
    int n = arr.size();
    int ans = maximumConsecutive(arr, n);
    cout << ans;
}