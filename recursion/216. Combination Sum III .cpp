//
// Created by Gaurav Kesh Roushan on 05/04/26.
//
class Solution {
	vector<vector<int>> res;

private:
	void func(int i, int sum, vector<int>& arr, vector<int>& temp,int k) {
		if (temp.size() == k) {
			if (sum == 0) res.push_back(temp);
			return;
		}

		for (int j = i; j < arr.size(); j++) {
			// skip duplicates
			if (j > i && arr[j] == arr[j - 1]) continue;

			if (arr[j] > sum) break; // pruning

			temp.push_back(arr[j]);
			func(j + 1, sum - arr[j], arr, temp,k);
			temp.pop_back();
		}
	}

public:
	vector<vector<int>> combinationSum3(int k, int target) {
		vector<int> candidates = {1,2,3,4,5,6,7,8,9};
		sort(candidates.begin(), candidates.end());
		vector<int> temp;
		func(0, target, candidates, temp,k);
		return res;
	}
};



/*
BACKTRACKING: Combination Sum III

Goal:
- Pick exactly k numbers from [1..9]
- Each number used once
- Sum must be equal to target

Approach:
- Try all combinations using backtracking
- At each step, choose a number and move forward (no reuse → j+1)
- Maintain:
    temp → current combination
    sum  → remaining sum

Base Case:
- If temp.size() == k:
    - If sum == 0 → valid combination → store
    - Else → discard
    - Stop further exploration (pruning)

Pruning:
- If arr[j] > sum → break (since array is sorted)
- Avoid unnecessary exploration when sum can't be achieved

Backtracking:
- Choose → temp.push_back()
- Explore → recursive call
- Undo → temp.pop_back()

Key Points:
- Ensures unique combinations (no duplicates, no reuse)
- Efficient due to early pruning
- Time ≈ O(2^9) (constant), Space ≈ O(k)

Note:
- Duplicate check not needed since array has unique elements (1–9)
*/