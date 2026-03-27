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
==================== CYCLIC SHIFT / ROTATION ====================

1) Always reduce k:
   k %= n;
   // After n shifts → array remains same

----------------------------------------------------------------

2) NEVER simulate shifts (no loop over k)
   // Use index mapping instead

----------------------------------------------------------------

3) CORE IDEA:
   For each index j,
   find from which index the value came

----------------------------------------------------------------

4) INDEX MAPPING (MOST IMPORTANT)

   RIGHT SHIFT by k:
   new[j] = old[(j - k + n) % n]

   LEFT SHIFT by k:
   new[j] = old[(j + k) % n]

----------------------------------------------------------------

5) WHY +n ?
   // To avoid negative index
   // Example: j=1, k=2 → j-k = -1 → invalid
   // (-1 + n) % n → valid index

----------------------------------------------------------------

6) DO NOT CONFUSE (VERY IMPORTANT)

   Finding source index (USED IN COMPARISON):
   RIGHT → (j - k + n) % n
   LEFT  → (j + k) % n

   Finding destination index:
   RIGHT → (j + k) % n
   LEFT  → (j - k + n) % n

----------------------------------------------------------------

7) PROBLEM-SPECIFIC LOGIC

   if (i % 2 == 0)
       // even row → RIGHT shift
   else
       // odd row → LEFT shift

----------------------------------------------------------------

8) COMPARISON (NO ACTUAL SHIFT)

   if (i % 2 == 0)
       mat[i][j] == mat[i][(j - k + n) % n];
   else
       mat[i][j] == mat[i][(j + k) % n];

----------------------------------------------------------------

9) EARLY EXIT

   if (k % n == 0) return true;

----------------------------------------------------------------

10) COMPLEXITY

   Time  : O(m * n)
   Space : O(1)

----------------------------------------------------------------

11) PATTERN RECOGNITION

   If you see:
   - rotation
   - circular array
   - wrap-around

   → Think: (index ± k + n) % n

----------------------------------------------------------------

/*
==================== REAL-WORLD APPLICATIONS ====================

1) Circular Buffers (Queues / Streaming Systems)
   // Used in OS, networking, audio/video streaming
   // Instead of shifting data → move head pointer
   // head = (head + k) % n;

----------------------------------------------------------------

2) Load Balancing (Round Robin)
   // Distribute requests across servers
   // next_server = (current + k) % n;

----------------------------------------------------------------

3) CPU Scheduling (Round Robin Scheduling)
   // Processes get CPU in cyclic order
   // next_process = (i + 1) % n;

----------------------------------------------------------------

4) Networking (Token Ring)
   // Token/data passed in circular fashion
   // next_node = (current + 1) % n;

----------------------------------------------------------------

5) Hashing (Open Addressing / Linear Probing)
   // Resolve collisions using cyclic probing
   // index = (hash + i) % table_size;

----------------------------------------------------------------

6) Sliding Window on Circular Arrays
   // Used in problems like max sum in circular array
   // wrap around using modulo

----------------------------------------------------------------

7) Game Development (Turn Rotation)
   // Players take turns in circular order
   // next_player = (current + 1) % n;

----------------------------------------------------------------

8) Memory Optimization
   // Avoid shifting large arrays
   // Just remap indices instead of moving data

----------------------------------------------------------------

9) Ring Buffers in Embedded Systems
   // Used in sensors, IoT devices for continuous data
   // Efficient and low memory usage

----------------------------------------------------------------

10) Media Processing Pipelines
   // Frames/audio samples rotate in buffers
   // Avoid copying → use cyclic indexing

================================================================
*/

===============================================================
*/
// 1 2 3 4
// 2 3 4 1 -> 3 4 1 2-> 4 1 2 3 -> 1 2 3 4

// 1 2 3
// 2 3 1 -> 3 1 2 -> 1 2 3 -> 2 3 1
