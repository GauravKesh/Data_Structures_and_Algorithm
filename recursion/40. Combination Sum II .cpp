//
// Created by Gaurav Kesh Roushan on 03/04/26.
//
class Solution {
	vector<vector<int>> res;

private:
	void func(int i, int sum, vector<int>& arr, vector<int>& temp) {
		if (sum == 0) {
			res.push_back(temp);
			return;
		}

		for (int j = i; j < arr.size(); j++) {
			// skip duplicates
			if (j > i && arr[j] == arr[j - 1]) continue;

			if (arr[j] > sum) break; // pruning

			temp.push_back(arr[j]);
			func(j + 1, sum - arr[j], arr, temp);
			temp.pop_back();
		}
	}

public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<int> temp;
		func(0, target, candidates, temp);
		return res;
	}
};