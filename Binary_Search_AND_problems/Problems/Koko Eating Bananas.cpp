//
// Created by Gaurav Kesh Roushan on 25/04/24.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	static int maxx(vector<int> &v) {
		int maxx = INT_MIN;
		for (int i = 0; i < v.size(); i++) {
			maxx = max(v[i], maxx);
		}
		return maxx;
	}
	static int findHour(vector<int> &v, int hour) {
		int total = 0;
		for (int i = 0; i < v.size(); i++) {
			total += ceil((double)v[i] / (double)hour);
		}
		return total;
	}

	static int minimumRateToEatBananas(vector<int> piles, int h) {
		int low = 1, high = maxx(piles);
		while (low <= high) {
			int mid = (low + high) / 2;
			int total = findHour(piles, mid);
			if (total <= h) {
				high = mid - 1;
			} else if (total > h) {
				low = mid + 1;
			}
		}
		return low;
	}
};


int main() {
	vector<int> a = {30,11,23,4,20};
	int hour = 5;
	int ans = Solution::minimumRateToEatBananas(a,hour);
	cout << "The min banana he can eat in 1 hr is: - " << ans << "\n";
	return 0;
}