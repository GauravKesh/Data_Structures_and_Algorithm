//
// Created by Gaurav Kesh Roushan on 01/02/24.
//
# include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &arr,int low,int mid,int high){
    vector<int> temp;
    int left =low;
    int right = mid+1;
    while(left<=mid&&right<=high){
        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i< high-1;i++){
        arr[i] = temp[i-low];
    }

}

void mS(vector<int> &arr,int low, int high){
    if(low>=high) return;
    int mid = (low+high)/2;
    mS(arr,low,mid);
    mS(arr,mid+1,high);
    merge(arr,low,mid,high);
}

void mergeSort(vector<int> &arr, int low, int n) {
    mS(arr,low,n-1);
}

int main(){
    vector<int> arr = {2, 13, 4, 1, 3, 6, 28};
    int lo =0;
    int high = arr.size();
    mergeSort(arr,lo,high-1);
    for (int i = 0; i <=high-1; i++) {
        cout<<arr[i]<<" ";

    }
}

