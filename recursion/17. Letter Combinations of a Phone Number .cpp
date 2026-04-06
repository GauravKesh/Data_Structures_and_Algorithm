//
// Created by Gaurav Kesh Roushan on 06/04/26.
//
class Solution {
	vector<string> data = {"",    "",    "abc",  "def", "ghi",
						   "jkl", "mno", "pqrs", "tuv", "wxyz"};

private:
	void combinations(int idx, string digits, string temp,
					  vector<string> &combs) {
		if (idx == digits.size()) {
			combs.push_back(temp);
			return;
		}

		int digit = digits[idx] - '0';
		for (int i = 0; i<data[digit].size(); i++) {
			combinations(idx + 1, digits, temp + data[digit][i], combs);
		}

	}

public:
	vector<string> letterCombinations(string digits) {
		if (digits.size()==0) return {};
		vector<string> combi;
		string comb = "";
		combinations(0, digits, comb, combi);
		return combi;
	}
};


			// 🔁 PATTERN: Backtracking (Pick one option at each level)
			//
			// IDEA:
			// - Each digit maps to multiple characters (like a tree)
			// - For every digit → try all possible characters
			// - Move to next digit (idx + 1)
			// - Build string step-by-step (temp)
			//
			// TREE THINKING:
			// digits = "23"
			// → 2 → a,b,c
			// → 3 → d,e,f
			// → combinations: ad, ae, af, bd, be, bf, cd, ce, cf
			//
			// BASE CASE:
			// - When idx == digits.size()
			// → one full combination is formed → push to result
			//
			// CHOICE:
			// - Loop over all chars mapped to current digit
			// - Append char → recurse → auto backtrack (since temp is passed by value)
			//
			// IMPORTANT:
			// - temp is passed by value → no need to manually pop_back()
			// - digits[idx] - '0' converts char → integer index
			//
			// TIME COMPLEXITY:
			// - O(4^N * N)
			//   (max 4 choices per digit, N digits, string copy cost)
			//
			// SPACE COMPLEXITY:
			// - O(N) recursion stack
			// - O(output size) for storing results
			//
			// EDGE CASE:
			// - If digits is empty → return empty vector (handle explicitly if needed)
			//
			// PATTERN RECOGNITION:
			// - "Generate all combinations" → Backtracking
			// - "Each step has multiple choices" → Tree/DFS
			//
			// OPTIMIZATION NOTE:
			// - Using temp + char creates new string every time
			// - Can optimize using push_back + pop_back (pass by reference)