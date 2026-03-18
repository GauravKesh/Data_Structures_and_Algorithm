//
// Created by Gaurav Kesh Roushan on 18/03/26.
//
/*
🧠 PATTERN: Counting with Independent Positions (Combinatorics + Fast Power)

Problem Type:
- Digits / strings of length n
- Each position has fixed allowed choices
- Positions are independent

Key Observation:
- Even indices (0-based): 5 choices → {0,2,4,6,8}
- Odd indices: 4 choices → {2,3,5,7}

Count positions:
- even = (n + 1) / 2
- odd  = n / 2

Core Idea:
- Total ways = product of choices at each position
- => 5 * 4 * 5 * 4 ... = 5^even * 4^odd

Why NOT brute force?
- Total numbers = 10^n → impossible for large n
- Always think: "choices per position" instead of "generate numbers"

Optimization:
- Use Fast Exponentiation (Binary Exponentiation)
- Time: O(log n)

Formula:
    ans = (5^even * 4^odd) % MOD

Recognition Checklist:
✔ Positions are independent
✔ Fixed number of choices per position
✔ Large n (forces O(log n))
✔ Multiplication of possibilities → exponentiation

Template Thought:
    for each type of position:
        count = choices ^ frequency

⚡ This pattern appears in:
- Digit DP (simplified cases)
- Counting strings
- Combinatorics (independent slots)
*/

class Solution {
public:
	const long long MOD = 1e9 + 7;

	long long power(long long base, long long exp) {
		long long res = 1;
		base %= MOD;

		while (exp > 0) {
			if (exp & 1)
				res = (res * base) % MOD;
			base = (base * base) % MOD;
			exp >>= 1;
		}
		return res;
	}

	int countGoodNumbers(long long n) {
		long long even = (n + 1) / 2;
		long long odd = n / 2;
		long long ans = (power(5, even) * power(4, odd)) % MOD;
		return ans;
	}
