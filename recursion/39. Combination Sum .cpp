//
// Created by Gaurav Kesh Roushan on 03/04/26.
//
class Solution {
	vector <vector<int>> res;

private:
	void func(int i, int sum,
			  vector<int> &arr,
			  vector<int> &temp) {
		if (i == arr.size()) {
			if (sum == 0) {
				res.push_back(
						temp);
			}
			return;
		}
		if (arr[i] <= sum) {
			temp.push_back(
					arr[i]);
			func(i,
				 sum - arr[i],
				 arr, temp);
			temp.pop_back();
		}

		func(i + 1, sum, arr,
			 temp);
	}

public:
	vector <vector<int>>
	combinationSum(
			vector<int> &candidates,
			int target) {
		vector<int> ds;
		func(0, target,
			 candidates, ds);
		return res;
	}
};