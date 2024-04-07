//
// Created by Gaurav Kesh Roushan on 05/02/24.
//
#include <iostream>
#include <vector>
using namespace std;
void rotateArrayCustomByLeft(vector<int> &arr, int k) {
    int n = arr.size();
    k = k%n;
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
void rotateArrayCustomByRight(vector<int> &arr, int k){
    int n = arr.size();
    k = k%n;
    if (n == k) {
        return;
    } else {
        while (k > 0) {
            int temp = arr[n - 1];
            for (int i = n - 1; i > 0; i--) {
                arr[i] = arr[i - 1];
            }
            arr[0] = temp;
            k--;
        }
    }
    cout<<endl;
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}
/// optimal approach
void rotateArrayRightOptimal(vector<int> &v,int k,n){
    reverse(arr.begin()+n-k,arr.end());
    reverse(arr.begin(),arr.end()-k);
    reverse(arr.begin(),arr.end());
}

int main(){
    vector<int> arr ={1,2,3,4,5,6,7};
    int n =  arr.size();
    int k = 4;
    k = k%n;
    rotateArrayCustomByLeft(arr,k);
    rotateArrayCustomByRight(arr,k);
    rotateArrayRightOptimal(arr,k,n)
}
