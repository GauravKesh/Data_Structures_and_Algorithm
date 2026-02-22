//
// Created by Gaurav Kesh Roushan on 22/02/26.
//

class Solution {
public:
	int scoreDifference(vector<int>& nums) {
		int s[2] = {0,0};
		int n = nums.size();
		int a = 0;
		for(int i =0;i<n;i++ ){
			if(nums[i]%2==1) a^=1;
			if(i%6==5) a ^= 1;
			s[a] += nums[i];
		}
		return s[0]-s[1];
	}
};