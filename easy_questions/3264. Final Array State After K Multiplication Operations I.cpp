//
// Created by Gaurav Kesh Roushan on 16/12/24.
//
class Solution {
private:
	int IndexPos(vector<int>& nums){
		int n =0;
		int min = INT_MAX;
		for (int i=0;i<nums.size();i++){
			if(nums[i]<min && nums[i]!=min){
				n = i;
				min = nums[i];
			}
		}
		return n;
	}
public:
	vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
		while (k != 0) {
			int n = IndexPos(nums);
			long long int l = nums[n]*multiplier;
			nums[n] = (int) l;
			k--;
		}
		return nums;
	}
};