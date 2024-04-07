//
// Created by Gaurav Kesh Roushan on 03/02/24.
//

// I did with no help

#include <iostream>
#include<vector>
using namespace std;
int isSorted(int n, vector<int> a) {
    int initial = a[0];
    bool value = true;
    for(int i =1 ;i<n;i++){
        if(a[i]>initial){
            initial = a[i];
            value = true;
        }
        else if(a[i]<initial){
            value =false;
        }
    }
    return value;
}
void findProductSumDifference(int n){
    int sum = 0;
    int product =1;
    int num = n;
    int count = 0;
    while(num!=0){
        int rem =num%10;
        sum =  sum+rem;
        product = product*rem;
        int q = num /10;
        num = q;

    }
    cout<< sum<<" "<<product;
}
int main(){
    int N = 125;
    vector<int> arr = {1, 2, 3, 4, 5};
    int n  =arr.size();
//    int  sorted = isSorted(n,arr);
    findProductSumDifference(N);
//    cout<<sorted;
    return 0;
}