//
// Created by Gaurav Kesh Roushan on 26/03/26.
//
class Solution {
private:
	void genstr(int n, string curr, vector<string>& res) {
		if (curr.size() == n) {
			res.push_back(curr);
			return;
		}

		genstr(n, curr + '0', res);

		if (curr.empty() || curr.back() == '0') {
			genstr(n, curr + '1', res);
		}
	}

public:
	vector<string> generateBinaryStrings(int n) {

		vector<string> arr;
		if(n==0) return arr;
		genstr(n, "", arr);
		return arr;
	}
};

/*
 * QUICK REVISION: Generate Binary Strings (No consecutive 1s)
 *
 * CORE RULE:
 * - Always add '0'
 * - Add '1' only if previous char != '1'
 *
 * PATTERN:
 * - Backtracking (DFS)
 * - Decision tree with pruning
 *
 * KEY CONDITION:
 * if (curr.empty() || curr.back() == '0')
 *
 * COMPLEXITY:
 * - Time: O(F(n))  (Fibonacci growth)
 * - Space: O(n)    (recursion stack)
 *
 * OPTIMAL IDEA:
 * - Don't generate all 2^n strings
 * - Prune invalid cases early
 *
 * PITFALLS:
 * - Missing base case return
 * - Wrong condition for '1'
 * - Forgetting pop_back() (if using reference)
 *
 * MEMORY HOOK:
 * "Place '1' only after '0' → Fibonacci pattern"
 */

/*
 * REVISION NOTES: BACKTRACKING & GENERATION
 *
 * 1. THE CORE PATTERN (DFS)
 *    Backtracking is essentially a Depth-First Search (DFS) on a decision tree.
 *    - Base Case: Defines when a valid solution is completed.
 *    - Recursive Step: Explores all valid choices ('0' or '1').
 *    - Pruning: Stops exploring branches that violate problem rules (e.g., "11").
 *
 * 2. COMPLEXITY ANALYSIS
 *    - Time: O(F_n), where F_n is the Fibonacci sequence. Since we must
 *      generate every valid string, we cannot be faster than the output size.
 *    - Space: O(n) due to the recursion stack depth.
 *
 * 3. BACKTRACKING VS BRUTE FORCE
 *    - Brute Force: Generates 2^n strings, then validates them.
 *    - Backtracking (Our approach): Only generates valid strings. This is
 *      "Pruning" the search space, making it significantly more efficient.
 *
 * 4. LEXICOGRAPHICAL ORDER
 *    - To ensure results are sorted, always explore the '0' branch before
 *      the '1' branch. This keeps "0..." strings before "1..." strings.
 *
 * 5. MEMORY OPTIMIZATION TIP
 *    - Using `string& curr` with `push_back` and `pop_back` is more memory
 *      efficient than passing `curr + '0'` (which creates a new string object
 *      in every recursive call).
 *
 * 6. COMMON MISTAKES
 *    - Forgetting the `return` after the base case (causes infinite recursion).
 *    - Modifying the state (e.g., `curr`) without undoing it (if not using
 *      the pass-by-value string copy method).
 *    - Neglecting the empty string case when checking `curr.back()`.
 */

]
