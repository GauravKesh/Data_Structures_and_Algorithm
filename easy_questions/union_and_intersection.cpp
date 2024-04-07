//
// Created by Gaurav Kesh Roushan on 07/02/24.
//
#include<iostream>
#include <set>
#include <vector>

using namespace std;

void sortedArrayUnion(vector<int> &a, vector<int> &b) {
    // Write your code here
    int an = a.size();
    int bn = b.size();
    set<int> temp;
    vector<int> ar;
    for (int i = 0; i < an; i++) {
        temp.insert(a[i]);
    }
    for (int i = 0; i < bn; i++) {
        temp.insert(b[i]);
    }
    for (auto it: temp) {
        ar.push_back(it);
    }
    for (int i = 0; i < ar.size(); i++) {
        cout << ar[i] << " ";
    }
}


void sortedArrayIntersection(vector<int> &a, vector<int> &b) {
    // Write your code here
    int an = a.size();
    int bn = b.size();
    vector<int> temp = {0};
    vector<int> ans;
    for (int i = 0; i < an; i++) {
        for (int j = 0; j < bn; j++) {
            if (a[i] == b[j] && temp[j] == 0) {
                ans.push_back(a[i]);
                temp[j] = 1;
                break;
            }
            if (b[j] > a[i]) {
                break;
            }
        }
    }
    for (int an: ans) {
        cout << an << " ";

    }
}

void sortedArrayIntersectionOptimal(vector<int> &a, vector<int> &b) {
    int an = a.size();
    int bn = b.size();
    vector<int> arr;
    int i = 0;
    int j = 0;
    while (i<an && j < bn) {
        if (a[i] < b[j]) {
            i++;
        }
        else if(b[j]<a[i]){
            j++;
        } else{
            arr.push_back(a[i]);
            i++;
        }

    }
    for(int i : arr){
        cout<<i<<" ";
    }
}


int main() {
    vector<int> a = {2, 1, 5, 6, 7};
    vector<int> b = {1, 4, 2, 6, 6, 7};
//    sortedArrayUnion(a,b);
//    sortedArrayIntersection(a, b);
    sortedArrayIntersectionOptimal(a, b);

}