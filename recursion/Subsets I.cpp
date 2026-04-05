//
// Created by Gaurav Kesh Roushan on 05/04/26.
//
class Solution {
private:
	void generateSubsetSums(int index, int current_sum, const vector<int>& nums,
							vector<int>& result) {
		if (index == nums.size()) {
			result.push_back(current_sum);
			return;
		}
		//include
		generateSubsetSums(index + 1, current_sum + nums[index], nums, result);
		//exclude
		generateSubsetSums(index + 1, current_sum, nums, result);
	}

public:
	vector<int> subsetSums(vector<int>& nums) {
		vector<int> result;
		generateSubsetSums(0, 0, nums, result);
		sort(result.begin(), result.end());
		return result;
	}
};


/*
    PROBLEM: Generate all subset sums

    APPROACH:
    - Use DFS recursion with include/exclude pattern
    - At each index, we have 2 choices:
        1. Include nums[index] in current sum
        2. Exclude nums[index]
    - This forms a binary recursion tree of size 2^n

    STATE:
    - index       → current position in array
    - current_sum → sum accumulated so far

    BASE CASE:
    - When index == nums.size():
        → One subset is formed, store current_sum

    OPTIMIZATION:
    - Use running sum instead of recomputing sum of subset
    - Avoids O(n) work per subset

    COMPLEXITY:
    - Time  : O(2^n)
    - Space : O(n) (recursion stack)

    NOTES:
    - Result contains sums of all subsets (size = 2^n)
    - Sorting is optional (depends on problem requirement)
    - Works with negative numbers and duplicates

    PATTERN:
    - Classic "include/exclude" recursion
    - Used in subsets, subsequences, combinations problems
*/



/*
    SUBSET SUMS (DFS - Include/Exclude)

    Idea:
    - At each index → 2 choices:
        include → sum + nums[i]
        exclude → sum

    State:
    - (index, current_sum)

    Base:
    - index == n → store current_sum

    Complexity:
    - Time  : O(2^n)
    - Space : O(n)

    Key:
    - Use running sum (avoid O(n) recomputation)
    - Forms binary recursion tree (2^n subsets)

    Pattern:
    - Classic backtracking / subsequence generation
*/