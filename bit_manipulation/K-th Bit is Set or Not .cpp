//
// Created by Gaurav Kesh Roushan on 28/01/25.
//
#include <iostream>

using namespace std;


class Solution {
public:
	static bool
	checkKthBitSet(int n,
				   int k) {
//		13
// 1101
		if (n & (1 << k)) {
			return true;
		}
		return false;
	}
};

int main() {
	Solution obj;
	bool val = Solution::checkKthBitSet(
			13, 3);
	cout<<val;


}