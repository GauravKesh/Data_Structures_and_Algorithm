//
// Created by Gaurav Kesh Roushan on 06/02/25.
//
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums) {
		int n = nums.size();
		vector<int> result(n, -1);
		stack<int> stk;
		for (int i = 2 * n - 1; i >= 0; i--) {
			while (!stk.empty() && stk.top() <= nums[i % n]) {
				stk.pop();
			}
			if (i < n) {
				if (!stk.empty()) {
					result[i] = stk.top();
				}
			}

			stk.push(nums[i % n]);
		}

		return result;
	}
};


int main(){
	vector<int> nums1 = {2,1,2};
	Solution sol;
	vector<int> ans = sol.nextGreaterElement(nums1);
	for(int num : ans){
		cout<<num<<" ";
	}
}