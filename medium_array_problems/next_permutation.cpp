//
// Created by Gaurav Kesh Roushan on 15/02/24.
//
#include <iostream>
#include <vector>
using namespace std;

void nextPermutation(vector<int> &arr){
    int n = arr.size();
    // break point
    int ind =-1;
    // Step 1: Find the break point:
    for(int i =n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            // index i is the break point
            ind = i;
            break;
        }
    }
    // If break point does not exist:
//    if(ind==-1){
//        // reverse the whole array:
//        reverse(arr.begin(),arr.end());
//    }
    // Step 2: Find the next greater element
    //       and swap it with arr[ind]:
    for(int j =n-1;j>ind;j--){
        if(arr[j]>arr[ind]){
            swap(arr[j],arr[ind]);
            break;
        }
    }
    // Step 3: reverse the right half:
    reverse(arr.begin()+ind+1,arr.end());
    for(auto it: arr){
        cout<<it<<" ";
    }
}

int main(){
//    vector<int> arr ={2,1,5,4,3,0,0};
//    vector<int> arr ={3,1,2};
    vector<int> arr ={3,2,1,0};
    nextPermutation(arr);

}