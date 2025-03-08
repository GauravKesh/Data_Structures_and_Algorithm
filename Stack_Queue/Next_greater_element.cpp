//
// Created by Gaurav Kesh Roushan on 06/02/25.
//
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int,int> mpp;
		stack<int> stk;
		for(int num:nums2){
			while(!stk.empty() && stk.top()<num){
				mpp[stk.top()] = num;
				stk.pop();
			}
			stk.push(num);
		}
		while(!stk.empty()){
			mpp[stk.top()] = -1;
			stk.pop();
		}
		vector<int> finalAnswer;
		for(int n: nums1){
			finalAnswer.push_back(mpp[n]);
		}
		return finalAnswer;
	}
};


int main(){
	vector<int> nums1 = {4,1,2};
	vector<int> nums2 = {1,3,4,2};
	Solution sol;
	vector<int> ans = sol.nextGreaterElement(nums1,nums2);
	for(int num : ans){
		cout<<num<<" ";
	}
}