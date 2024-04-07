//
// Created by Gaurav Kesh Roushan on 07/04/24.
//
#include <iostream>
#include <vector>

using namespace std;

void spiralOrder(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();

    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = m - 1;

    vector<int> ans;
    while (top <= bottom && left <= right) {
        // top
        for (int i = left; i <= right; i++) {
            ans.push_back(mat[top][i]);
        };
        top++;

        // for right
        for (int i = top; i <= bottom; i++) {
            ans.push_back(mat[i][right]);
        };
        right--;

        // for bottom
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(mat[bottom][i]);
            };
            bottom--;
        }
        // for left
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(mat[i][left]);
            };
            left++;
        }
    };

    for(auto i : ans){
        cout<<i<<" ";
    };

}

int main() {
    vector<vector<int>> array = {{1, 2, 3},
                                 {4, 5, 6},
                                 {7, 8, 9}};
    spiralOrder(array);
}
