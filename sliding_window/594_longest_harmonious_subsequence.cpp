//
// Created by Gaurav Kesh Roushan on 03/03/26.
//

// class Solution {
// public:
//     int findLHS(vector<int>& nums) {
//         sort(nums.begin(), nums.end());

//         int n = nums.size();
//         int i = 0;
//         int ans = 0;

//         for(int j = 0; j < n; j++) {

//             while(nums[j] - nums[i] > 1) {
//                 i++;
//             }

//             if(nums[j] - nums[i] == 1) {
//                 ans = max(ans, j - i + 1);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
	int findLHS(vector<int>& nums) {
		unordered_map<int,int> freq;

		// Count frequency
		for(int x : nums){
			freq[x]++;
		}

		int ans = 0;

		for(auto &p : freq){
			int key = p.first;

			if(freq.count(key + 1)){
				ans = max(ans, p.second + freq[key + 1]);
			}
		}

		return ans;
	}
};
