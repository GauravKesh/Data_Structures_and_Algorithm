//
// Created by Gaurav Kesh Roushan on 02/05/24.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	 static int lowerBound(vector<int>&arr, int target){
		int n =  arr.size();
		int low =0,high =n-1;
		int ans = n;
		while(low<=high){
			int mid =(low+high)/2;
			if(arr[mid]>=target){
				ans = mid;
				high = mid-1;
			}
			else{
				low = mid+1;
			}
		}

		return ans;
	}

};
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
	int cnt_max = 0;
	int index = -1;

	//traverse the rows:
	for (int i = 0; i < n; i++) {
		// get the number of 1's:
		int cnt_ones = m - Solution::lowerBound(matrix[i], m, 1);
		if (cnt_ones > cnt_max) {
			cnt_max = cnt_ones;
			index = i;
		}
	}
	return index;
}

int main()
{
	vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
	int n = 3, m = 3;
	cout << "The row with maximum no. of 1's is: " <<
		 rowWithMax1s(matrix, n, m) << '\n';
}
