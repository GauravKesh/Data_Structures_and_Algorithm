//
// Created by Gaurav Kesh Roushan on 25/04/24.
//


#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	static int func(int num, int k, int m) {
		long long ans = 1;
		int i;
		for (i = 1; i <= k; i++) {
			ans *= num;
			if (ans > m)
				return 2;
		}
		if (ans == m)
			return 1;
		return 0;
	}
	static int findPeakElement(int n,int m) {
		//Use Binary search on the answer space:
		int low = 1, high = m;
		while (low <= high) {
			int mid = (low + high) / 2;
			int midN = func(mid, n, m);
			if (midN == 1) {
				return mid;
			}
			else if (midN == 0) low = mid + 1;
			else high = mid - 1;
		}
		return -1;
	}
};


int main() {
	int a = 3;
	int b = 27;
	int ans = Solution::findPeakElement(a,b);
	cout << "The root is: - " << ans << "\n";
	return 0;
}