//
// Created by Gaurav Kesh Roushan on 05/04/26.
//
class Solution {
private:
	void generateUniquePowerSetBrute(int index, const vector<int>& nums,
								vector<int>& temp,
								vector<vector<int>>& result) {
		if (index == nums.size()) {
			sort(temp.begin(), temp.end());
			if (find(result.begin(), result.end(), temp) == result.end()) {
				result.push_back(temp);
			}

			return;
		}
		// include
		generateUniquePowerSetBrute(index + 1, nums, temp, result);
		temp.push_back(nums[index]);
		// exclude
		generateUniquePowerSetBrute(index + 1, nums, temp, result);
		temp.pop_back();
	}


public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		vector<int> temp;
		generateUniquePowerSetBrute(0, nums, temp, result);
		return result;
	}
};


class Solution {
private:

	void func(int ind, vector<int> &arr, vector<int> &nums, vector<vector<int>> &ans) {

		if(ind == nums.size()) {

			ans.push_back(arr);
			return;
		}


		arr.push_back(nums[ind]);

		func(ind+1, arr, nums, ans);

		arr.pop_back();


		for(int j = ind + 1; j < nums.size(); j++) {
			if(nums[j] != nums[ind]) {
				func(j, arr, nums, ans);
				return;
			}
		}


		func(nums.size(), arr, nums, ans);
	}

public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> arr;
		sort(nums.begin(), nums.end());
		func(0, arr, nums, ans);
		return ans;
	}
};



// Sort the array to bring duplicates together
// Required for skipping duplicates efficiently

// Backtracking function:
// start → controls current recursion level (IMPORTANT for duplicate handling)
// temp → current subset being built
// ans → stores all unique subsets

// Add current subset to answer at every call (not just base case)

// Loop from 'start' to end → allows picking next elements

// Skip duplicates at SAME recursion level
// i > start ensures we only skip duplicates in same level, not across levels
// nums[i] == nums[i-1] means duplicate element → skip this branch

// Choose current element
// Move forward (i+1) since each element can be used once

// Backtrack → remove last element to explore other possibilities