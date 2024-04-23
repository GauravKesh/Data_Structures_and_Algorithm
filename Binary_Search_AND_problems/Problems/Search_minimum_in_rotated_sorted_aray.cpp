//
// Created by Gaurav Kesh Roushan on 23/04/24.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public :
	static int findKRotation(vector<int> &arr) {
		int low = 0, high = arr.size() - 1;
		int ans = INT_MAX;
		int index = -1;
		while (low <= high) {
			int mid = (low + high) / 2;
			//search space is already sorted
			//then arr[low] will always be
			//the minimum in that search space:
			if (arr[low] <= arr[high]) {
				if (arr[low] < ans) {
					index = low;
					ans = arr[low];
				}
				break;
			}

			//if left part is sorted:
			if (arr[low] <= arr[mid]) {
				// keep the minimum:
				if (arr[low] < ans) {
					index = low;
					ans = arr[low];
				}

				// Eliminate left half:
				low = mid + 1;
			} else { //if right part is sorted:

				// keep the minimum:
				if (arr[mid] < ans) {
					index = mid;
					ans = arr[mid];
				}

				// Eliminate right half:
				high = mid - 1;
			}
		}

		return index;
	}
};

int main() {
	vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
	int ans = Solution::findKRotation(arr);
	cout << "The array is rotated " << ans << " times.\n";
	return 0;
}