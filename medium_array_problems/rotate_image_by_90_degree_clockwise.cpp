//
// Created by Gaurav Kesh Roushan on 17/02/24.
//
#include <iostream>
#include <vector>

using namespace std;
void rotateImageOptimal(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(),matrix[i].end());
    }

}
void rotateImage(vector<vector<int>> &matrix) {
    vector<vector<int>> mat = {{1, 1, 1},
                               {1, 0, 1},
                               {1, 1, 1}};;
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
//                    mat[i][j] = matrix[j][n - 1 - i];
                    mat[j][n - 1 - i] = matrix[i][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout<<endl;
    }

}

int main() {


    vector<vector<int>> arr = {{1, 1, 1},
                               {1, 0, 1},
                               {1, 1, 1}};
    vector<vector<int>> arrw = {{1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9}};

    vector<vector<int>> arr1 = {{2, 4, 3},
                                {1, 0, 0}};

    vector<vector<int>> arr2 = {{2, 4, 3},
                                {1, 0, 0},
                                {1, 0, 0}};
    rotateImageOptimal(arrw);
    for (int i = 0; i < arrw.size(); i++) {
        for (int j = 0; j < arrw.size(); j++) {
            cout << arrw[i][j] << " ";
        }
        cout<<endl;
    }
}