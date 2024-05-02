//
// Created by Gaurav Kesh Roushan on 02/05/24.
//


#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	static int findMaxK(vector<int>& arr) {
		sort(arr.begin(),arr.end());
		int n = arr.size();
		int temp = arr[n-1];
		for(int i=n-1;i>=0;i--){
			for(int j =0;j<i;j++){
				if(arr[i]>0 && arr[i] == -arr[j] ){
					return arr[i];
				}
			}
		}
		return -1;
	}
};


int main()
{
	vector<int> matrix = {-1,2,-3,3};
	int n = 3, m = 3;
	cout << "Maximum number in thee array:- " <<
		 Solution::findMaxK(matrix) << '\n';
}
