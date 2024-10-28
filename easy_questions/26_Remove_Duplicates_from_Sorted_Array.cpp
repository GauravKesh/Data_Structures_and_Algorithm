//
// Created by Gaurav Kesh Roushan on 28/10/24.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int uniqueIndex = 0;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] != nums[uniqueIndex]) {
				uniqueIndex++;
				nums[uniqueIndex] = nums[i];
			}
		}
		return uniqueIndex + 1;
	}
};
