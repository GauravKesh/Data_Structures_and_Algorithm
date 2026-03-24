//
// Created by Gaurav Kesh Roushan on 24/03/26.
//
class Solution {
public:
	string addBinary(string a, string b) {
		int i = a.size() - 1;
		int j = b.size() - 1;
		int c = 0;

		string sum = "";

		while (i >= 0 || j >= 0 || c) {
			int s = c;

			if (i >= 0) s += (a[i--] - '0');
			if (j >= 0) s += (b[j--] - '0');

			sum.push_back((s % 2) + '0');
			c = s / 2;
		}

		reverse(sum.begin(), sum.end());
		return sum;
	}
};


//
// 🔁 BINARY ADDITION — QUICK REVISION
//
// Core idea:
//   s = bitA + bitB + carry
//   result_bit = s % 2
//   carry = s / 2
//
// Steps:
// 1. Start from rightmost index of both strings
// 2. Loop while (i >= 0 || j >= 0 || carry)
// 3. Convert char → int using (a[i] - '0')
// 4. Add bits + carry → s
// 5. Push (s % 2) + '0' into result
// 6. Update carry = s / 2
// 7. Reverse result at end
//
// Key points:
// - Build result in reverse → then reverse()
// - Always check remaining carry
// - Treat like normal addition (base 2)
//
// Common mistakes:
// - Using '0' as int → ❌ (use 0)
// - Comparing with 1 instead of '1'
// - Decrementing index inside conditions
// - Writing multiple if-else instead of formula
//
// Complexity:
// - Time: O(max(n, m))
// - Space: O(max(n, m))
//