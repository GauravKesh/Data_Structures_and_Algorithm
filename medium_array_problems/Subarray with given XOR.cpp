//
// Created by Gaurav Kesh Roushan on 16/04/24.
//
#include <iostream>
#include <map>

class Solution {
public:
	static int optimal(std::vector<int> &arr, int b) {
		int xr = 0;
		std::map<int, int> mpp;
		int count = 0;
		mpp[xr]++;
		for (int i : arr) {
			xr = xr ^ i;
			int x = xr ^ b;
			mpp[xr]++;
			count += mpp[x];
		}
		return count;
	}
};


int main() {
	std::vector<int> arr = {4, 2, 2, 6, 4};
	int b = 6;
	int val = Solution::optimal(arr, b);
	std::cout << val;

}