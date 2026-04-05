//
// Created by Gaurav Kesh Roushan on 05/04/26.
//
//
// Power Set (All Subsequences)
// Pattern: Pick / Not Pick (Include / Exclude)
// Time: O(2^n * n), Space: O(n) recursion + output
//

class Solution {
private:
	void generateSubsets(int index,
						 const vector<int>& nums,
						 vector<int>& currentSubset,
						 vector<vector<int>>& result) {

		// Base case: all elements processed
		if (index == nums.size()) {
			result.push_back(currentSubset);
			return;
		}

		// ❌ Choice 1: Do NOT include current element
		generateSubsets(index + 1, nums, currentSubset, result);

		// ✅ Choice 2: Include current element
		currentSubset.push_back(nums[index]);
		generateSubsets(index + 1, nums, currentSubset, result);

		// 🔁 Backtrack: undo the choice
		currentSubset.pop_back();
	}

public:
	vector<vector<int>> powerSet(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> currentSubset;

		generateSubsets(0, nums, currentSubset, result);
		return result;
	}
};

			/*
			POWER SET (All Subsets)

			Idea:
			At every index, we decide whether to include the current element or not.
			So each element has 2 choices → total subsets = 2^n.

			Flow (DFS):
			- Move index from 0 → n
			- At each step:
				1. Skip current element
				2. Include current element
			- When index == n → we formed one valid subset → store it

			Backtracking:
			- When we include an element, we must remove it after recursion
			  so that next decisions are not affected

			Mental Model:
			Think of a binary tree where:
				left = not take
				right = take

			Example:
			nums = [1,2]
			→ [], [1], [2], [1,2]

			Complexity:
			Time = O(2^n * n)   // n to copy each subset
			Space = O(n)        // recursion stack
			*/

			/*
			POWER SET / SUBSETS

			👉 Core Idea:
			For every element → 2 choices:
				1. Exclude it
				2. Include it

			👉 This forms a binary recursion tree → total subsets = 2^n

			👉 Template:
			void solve(i):
				if i == n:
					store answer
					return

				// not pick
				solve(i+1)

				// pick
				pick element
				solve(i+1)
				undo pick (backtrack)

			👉 Key Insight:
			Backtracking = choose → explore → undo

			👉 Complexity:
			Time = O(2^n * n)
			Space = O(n) recursion stack
			*/






