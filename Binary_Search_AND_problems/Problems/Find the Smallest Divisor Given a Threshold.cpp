//
// Created by Gaurav Kesh Roushan on 26/04/24.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	static int summ(vector<int>& arr, int mid) {
		int n = arr.size();
		int sumr =0;
		for (int i = 0; i < n; i++) {
			sumr += ceil((double)arr[i] /(double) mid);
		}
		return sumr;
	}

	static int smallestDivisor(vector<int>& arr, int threshold) {
		int low = 1;
		int high = *max_element(arr.begin(), arr.end());
		int n = arr.size();
		while (low <= high) {
			int mid = (low + high) / 2;
			int som = summ(arr,mid);

			if (som <= threshold) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		return low;
	}
};

int main() {
	vector<int> a = {1,2,5,9};
	int thresold = 6;
	int ans = Solution::smallestDivisor(a,thresold);
	cout << "The min divisor is: - " << ans << "\n";
	return 0;
}