//
// Created by Gaurav Kesh Roushan on 07/02/24.
//
#include <iostream>
#include <vector>
using namespace std;

int apperarOnce(vector<int> &arr,int n){

    int maxi =0;
    for(int i = 0;i<n;i++){
        maxi= max(maxi,arr[i]);
    }
    vector<int> heaps[maxi] = {0};
    for (int i = 0; i < n; i++) {
        heaps(arr[i]) = heaps(arr[i])+1;
    }
    for(int i=1;i<n;i++){
        if(heaps[i]==1){
            return i;
        }
    }

}

int main(){
    vector<int> arr = {1,2,2,2,4,4,6,6,6};
    int n = arr.size();
    int  ans = apperarOnce(arr,n);
    return ans;
}