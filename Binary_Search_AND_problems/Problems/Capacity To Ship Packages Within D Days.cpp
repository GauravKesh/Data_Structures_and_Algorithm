//
// Created by Gaurav Kesh Roushan on 26/04/24.
//
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
	static int numDays(vector<int>& weights, int mid) {
		int days = 1;
		int load = 0;
		for (int i = 0; i < weights.size(); i++) {
			if (load + weights[i] > mid) {
				days += 1;
				load = weights[i];
			} else {
				load += weights[i];
			}
		}
		return days;
	}
	static int shipWithinDays(vector<int>& weights, int days) {
		int n = weights.size();
		int low = *max_element(weights.begin(), weights.end());
		int high = accumulate(weights.begin(), weights.end(), 0);
		while (low <= high) {
			int mid = (low + high) / 2;
			int nDays = numDays(weights, mid);
			if (nDays <= days) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		return low;
	}
};

int main() {
	vector<int> weight = {1,2,3,4,5,6,7,8,9,10};
	int days = 5;
	int ans = Solution::shipWithinDays(weight,days);
	cout << "The least  weight capacity of ship is: - " << ans << "\n";
	return 0;
}