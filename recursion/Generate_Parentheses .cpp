//
// Created by Gaurav Kesh Roushan on 27/03/26.
//
class Solution {
private:
	void gp(int open,int close,int n,string p,vector<string>&arr){
		if(p.size()==2*n){
			arr.push_back(p);
			return;
		}
		if (open < n) {
			gp(open + 1, close, n, p + '(', arr);
		}

		if (close < open) {
			gp(open, close + 1, n, p + ')', arr);
		}
	}
public:
	vector<string> generateParenthesis(int n) {
		vector<string>arr;
		gp(0,0,n,"",arr);
		return arr;
	}
};

// 🔥 PROBLEM: Generate all valid parentheses combinations of size n

// 🧠 CORE IDEA:
// Build string step-by-step using BACKTRACKING
// Do NOT generate all and validate → directly build ONLY valid sequences

// ❌ WRONG APPROACH:
// Generate all 2^(2n) strings and check validity → inefficient

// ✅ OPTIMAL APPROACH:
// Use constraints while building the string (pruning invalid states early)


// 📌 STATE VARIABLES:
// open  → number of '(' used so far
// close → number of ')' used so far


// 📌 RULES (VERY IMPORTANT):
// 1. We can add '(' only if open < n
//    → because total '(' allowed = n

// 2. We can add ')' only if close < open
//    → ensures we never close more than we opened
//    → prevents invalid sequences like ")("


// 📌 BASE CASE:
// When current string length == 2 * n
// → we have used all brackets → valid answer


// 💡 KEY INSIGHT:
// At any prefix:
// close should NEVER exceed open
// → guarantees validity at every step
// → so no need for stack / validator


// ⚡ WHY THIS WORKS:
// We prune invalid states EARLY
// → reduces exponential search space drastically
// → only valid combinations are generated


// ⏱ TIME COMPLEXITY:
// O(Catalan(n)) ≈ O(4^n / sqrt(n))

// 📦 SPACE COMPLEXITY:
// O(n) recursion stack


// 🔁 PATTERN:
// Backtracking with constraints
// Similar problems:
// - N Queens
// - Sudoku Solver
// - Combination Sum


// 🚫 COMMON MISTAKES:
// - Using validator function (unnecessary)
// - Generating all strings first (brute force)
// - Allowing close > open (invalid states)


// 🧪 EDGE CASES:
// n = 1 → ["()"]
// n = 0 → (depending on problem) could be [""]


// 🎯 REAL-WORLD THINKING:
// This is like building a valid expression step-by-step
// ensuring correctness at each step instead of fixing later