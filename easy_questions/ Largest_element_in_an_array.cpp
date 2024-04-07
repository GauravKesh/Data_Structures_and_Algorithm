//
// Created by Gaurav Kesh Roushan on 03/02/24.
//

// used selection sort

#include <iostream>
#include <vector>
using namespace std;

// bruteforce approach
int largestElement(vector<int> &arr, int n) {
    for(int i=0;i<=n-1;i++){
        int mini =i;
        for(int j=i;j<=n-1;j++ ){
            if (arr[j] < arr[mini]) {
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
    return arr[n-1];

}
// optimal
int largestElementOptimal(vector<int> &arr, int n){
    int max=0;
    for (int i = 0; i < n;i++) {
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return  max;
}
int main(){
    vector<int> arr = {4, 6, 2, 5, 7, 9,10, 1, 3};
    int n =arr.size();
    int el = largestElement(arr,n);
    cout<<el;
    for (int j = 0; j <= n - 1; j++) {
        cout<<arr[j]<<" ,";}
    return 0;
}