//
// Created by Gaurav Kesh Roushan on 03/02/24.
//
#include<iostream>
#include <vector>

using namespace std;
// brute force approach

void SecondSmallestLargest(vector<int> &arr, int n) {
    vector<int> tempa;
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
    for (int j = 0; j <= n - 1; j++) {
        if (j == 1 || j == n - 2) {
            tempa.push_back(arr[j]);
        }
    }
    int small=arr[1];
    int large=arr[n-2];
    cout<<"Second smallest is "<<small<<endl;
    cout<<"Second largest is "<<large<<endl;
}

// brute force Approach 2
void SecondSmallestLargest_2(vector<int> &arr, int n) {
    if(n==1 ||n== 2)
        cout<<-1<<" "<<-1<<endl;
    sort(arr.begin(),arr.end());
    int small=arr[1];
    int large=arr[n-2];
    cout<<"Second smallest is "<<small<<endl;
    cout<<"Second largest is "<<large<<endl;
}

//best approach


int main() {
    vector<int> arr = {4, 6, 2, 5, 7, 9, 10, 1, 3};
    int n = arr.size();
    SecondSmallestLargest_2(arr, n);
    SecondSmallestLargest(arr, n);
//    cout<<el;
    return 0;
}
