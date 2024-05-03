//
// Created by Gaurav Kesh Roushan on 03/05/24.
//
#include <iostream>
#include <vector>
using namespace std;

/* we can solve this problem ny traversing each row and
 column and searching the number
 it'll take a lot of time
*/

/*
 also we can solve it using this by checking first and last
 element of each row if the number falls in that row we'll do a
 binary search and will get the number.
 it'll take  time O(N + logM)

*/



class SolutionOptimal {
public:
	static bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int n = matrix.size();
		int m = matrix[0].size();
		int low = 0, high = n * m - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			int r = mid / m;
			int c = mid % m;
			if (matrix[r][c] == target) {
				return true;
			} else if (matrix[r][c] < target) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		return false;
	}
};



int main()
{
	vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
	int target = 3;
	bool k = SolutionOptimal::searchMatrix(matrix,target);
	if(k){
		cout<<"The element is present in the array";
	}else
		cout<<"Element can't found";
}
