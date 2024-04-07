//
// Created by Gaurav Kesh Roushan on 16/02/24.
//
#include <iostream>
#include <vector>

using namespace std;

void markZeroRow(vector<vector<int>> &matrix, int i) {
    int n = matrix[0].size(); // row
    for (int l = 0; l < n; l++) {
        if (matrix[i][l] != 0) {
            matrix[i][l] = -99999;
        }
    }
}

void markZeroColumn(vector<vector<int>> &matrix, int j) {
    int m = matrix.size(); // column
    for (int l = 0; l < m; l++) {
        if (matrix[l][j] != 0) {
            matrix[l][j] = -99999;
        }
    }
}

void setZeroMatrix(vector<vector<int>> &matrix) {
    int n = matrix.size(); // row
    int m = matrix[0].size(); // column
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                markZeroRow(matrix, i);
                markZeroColumn(matrix, j);
            }
        }
    }

    for (int a = 0; a < n; a++) {
        for (int b = 0; b < m; b++) {
            if (matrix[a][b] == -99999) {
                matrix[a][b] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void setZeroMatrix_better(vector<vector<int>> &matrix) {
    int n = matrix.size(); // row
    int m = matrix[0].size(); // column
    vector<int> column;
    vector<int> row;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                row[i] = 1;
                column[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (column[j] == 1 || row[i] == 1) {
                matrix[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}

void setZeroMatrixOptimal(vector<vector<int>> &matrix) {
    int n = matrix.size(); // row
    int m = matrix[0].size(); // column
    int col0;
//    int column[m]={0}; //  column -> matrix[0][...]
//    int  row[n]={0}; // row -> matrix[..][0]

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // marks the i th row
                matrix[i][0] = 0;
                // marks the j-th row
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) {
                // check for column
                if (matrix[0][j] == 0 || matrix[i][0]) {
                    matrix[i][j] = 0;
                }
            }

        }
    }
    if (matrix[0][0] == 0)
        for (int i = 1; i < m; i++) {
            matrix[0][i] = 0;
        }
    if (col0 == 0) {
        for (int i = 1; i < n; i++) {
            matrix[i][0] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


}


int main() {

    vector<vector<int>> arr = {{1, 1, 1},
                               {1, 0, 1},
                               {1, 1, 1}};

    vector<vector<int>> arr1 = {{2, 4, 3},
                                {1, 0, 0}};
    vector<vector<int>> arr2 = {{2, 4, 3},
                                {1, 0, 0},
                                {1, 0, 0}};


//    setZeroMatrix_better(arr1);
    setZeroMatrixOptimal(arr);

}