//
// Created by Gaurav Kesh Roushan on 07/02/24.
//
#include <iostream>
#include <vector>

using namespace std;

void missingElement_BruteForce(vector<int> &arr, int n) {
    for (int i = 1; i <= n; i++) {
        int temp = 0;
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] == i) {
                temp = i;
                break;
            }
        }
        if (temp == 0) {
            cout << i << " ";
        }
    }
}

// using hashing
void missingElement_Best(vector<int> &arr, int n) {
    vector<int> hashed = {0};
    for (int i = 0; i < n; i++) {
        hashed[arr[i]] = 1;
    }
    for (int i = 0; i < n + 1; i++) {
        if (hashed[i] == 0) {
            cout << i;
        }
    }
}

void missingElementOptimal_Sum(vector<int> &arr, int n) {
    int sum = ((n * (n + 1)) / 2);
    int s1 = 0;
    for (int i = 0; i < n; i++) {
        s1 += arr[i];
    }
    cout << sum - s1 << " ";
}

int missingElementOptimal_XOR(vector<int> &arr, int N) {
    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < N-1; i++) {
        xor2 = xor2 ^ arr[i]; // XOR of array elements
        xor1 = xor1 ^ (i + 1); // XOR up to [1...N]
    }
    xor1 = xor1 ^ (N + 1); // XOR up to [1...N+1]
    return xor1 ^ xor2;

}


int main() {
    vector<int> arr = {0, 1, 2, 4};
    int n = arr.size();
//    missingElement_BruteForce(arr, n);
//    missingElement_Best(arr, n);
//    missingElementOptimal_Sum(arr, n);
   int ans = missingElementOptimal_XOR(arr, n);
   cout<<ans;
}