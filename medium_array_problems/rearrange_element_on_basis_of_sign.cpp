//
// Created by Gaurav Kesh Roushan on 14/02/24.
//
#include<iostream>
#include <vector>

using namespace std;

void rearrangeBrute(vector<int> &arr) {
    int n = arr.size();
    vector<int> pe;
    vector<int> ne;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            pe.push_back(arr[i]);
        } else {
            ne.push_back(arr[i]);
        }
    }
    for (int i = 0; i < 3; i++) {
        arr[2 * i] = pe[i];
        arr[2 * i + 1] = ne[i];
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

void rearrangeOptimal(vector<int> &arr) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

}

int main() {
    vector<int> arr = {3, 1, -2, -5, 2, -4};
//    rearrangeBrute(arr);
    rearrangeOptimal(arr);
}
