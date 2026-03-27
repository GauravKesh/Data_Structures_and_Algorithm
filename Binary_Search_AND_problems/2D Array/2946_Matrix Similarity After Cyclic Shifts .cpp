//
// Created by Gaurav Kesh Roushan on 27/03/26.
//
class Solution {
public:
	bool areSimilar(vector<vector<int>>& mat, int k) {
		int m = mat.size();
		int n = mat[0].size();
		k = k % n;
		if (k == 0)
			return true;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {

				if (i % 2 == 0) {
					// even row → right shift
					if (mat[i][j] != mat[i][(j - k + n) % n])
						return false;
				} else {
					// odd row → left shift
					if (mat[i][j] != mat[i][(j + k) % n])
						return false;
				}
			}
		}
		return true;
	}
};


/*
==================== CYCLIC SHIFT / ROTATION NOTES ====================

1) Always reduce k:
   k = k % n;
   // because after n shifts → array becomes same

-----------------------------------------------------------------------

2) DO NOT simulate shifts (no loops for k times)
   // Instead, compare using index mapping

-----------------------------------------------------------------------

3) KEY IDEA:
   For each position j,
   find from which index the value came after k shifts

-----------------------------------------------------------------------

4) INDEX MAPPING (MOST IMPORTANT)

   Case 1: RIGHT SHIFT by k
   --------------------------------
   new[j] = old[(j - k + n) % n]

   // Why?
   // element at index j came from left side (j - k)

   Example:
   [1 2 3 4], k=1 → [4 1 2 3]
   j=0 → comes from index 3 → (0-1+4)%4 = 3

-----------------------------------------------------------------------

   Case 2: LEFT SHIFT by k
   --------------------------------
   new[j] = old[(j + k) % n]

   // Why?
   // element at index j came from right side (j + k)

   Example:
   [1 2 3 4], k=1 → [2 3 4 1]
   j=0 → comes from index 1 → (0+1)%4 = 1

-----------------------------------------------------------------------

5) In this problem:
   --------------------------------
   if (i % 2 == 0) → RIGHT shift
   if (i % 2 == 1) → LEFT shift

-----------------------------------------------------------------------

6) COMPARISON (no actual shifting needed)

   if (i % 2 == 0) {
       // RIGHT shift
       mat[i][j] == mat[i][(j - k + n) % n]
   } else {
       // LEFT shift
       mat[i][j] == mat[i][(j + k) % n]
   }

-----------------------------------------------------------------------

7) WHY +n in (j - k + n) % n ?

   // to avoid negative index
   // example: j=1, k=2 → j-k = -1
   // (-1 + n) % n → valid index

-----------------------------------------------------------------------

8) TIME & SPACE

   Time  : O(m * n)
   Space : O(1)

=======================================================================
*/

// 1 2 3 4
// 2 3 4 1 -> 3 4 1 2-> 4 1 2 3 -> 1 2 3 4

// 1 2 3
// 2 3 1 -> 3 1 2 -> 1 2 3 -> 2 3 1
