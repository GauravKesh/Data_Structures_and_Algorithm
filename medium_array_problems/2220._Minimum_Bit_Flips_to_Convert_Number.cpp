//
// Created by Gaurav Kesh Roushan on 08/06/26.
//

class Solution {
public:
	int minBitFlips(int start, int goal) {
		int cnt = 0;
		while (start > 0 || goal > 0) {
			if ((start & 1) != (goal & 1)) {
				cnt++;
			}
			start >>= 1;
			goal >>= 1;
		}
		return cnt;
	}
};

//recursive

class Solution {
public:
	int minBitFlips(int start, int goal) {
		if(start==goal) return 0;
		int flip = (start&1)!=(goal&1);
		return flip + minBitFlips(start>>1,goal>>1);

	}
};