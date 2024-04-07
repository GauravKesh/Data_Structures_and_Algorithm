//
// Created by Gaurav Kesh Roushan on 05/02/24.
//
#include <iostream>
#include <vector>
using namespace std;
void rotateArray(vector<int> &arr, int n) {
    vector<int> temp(n);
    for (int i = 0; i < n-1; i++) {
        temp[i]=arr[i+1];
//        cout<<temp[i];
    }
    temp[n-1]=arr[0];
    for (int i = 0; i < n; i++) {
        cout<<temp[i]<<" ";
    }
}

void rotateArrayOptimal(vector<int> &arr, int n){
    int temp =arr[0];
    for(int i = 0;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]=temp;
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
};
void rotateArrayCustom(vector<int>arr, int k) {
    int n = arr.size();
    while(k>0){
        int temp = arr[0];
        for (int i = 0; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[n-1]=temp;
        k--;
    }
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    vector<int> arr = {1,2,3,4,5};
    int n=5;
    int k =2;
//    rotateArray(arr,n);
//    rotateArrayOptimal(arr,n);
    rotateArrayCustom(arr,k);
}

