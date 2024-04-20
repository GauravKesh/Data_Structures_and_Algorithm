//
// Created by Gaurav Kesh Roushan on 20/04/24.
//

#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
	static int findCeil(vector<int> &arr, int n, int x) {
		int low = 0, high = n - 1;
		int ans = -1;
		while (low <= high) {
			int mid = (low + high) / 2;
			// maybe an answer
			if (arr[mid] >= x) {
				ans = arr[mid];
				//look for smaller index on the left
				high = mid - 1;
			} else {
				low = mid + 1; // look on the right
			}
		}
		return ans;
	}

	static int findFloor(vector<int> &arr, int n, int x) {
		int low = 0, high = n - 1;
		int ans = -1;

		while (low <= high) {
			int mid = (low + high) / 2;
			// maybe an answer
			if (arr[mid] <= x) {
				ans = arr[mid];
				//look for smaller index on the left
				low = mid + 1;
			} else {
				high = mid - 1; // look on the right
			}
		}
		return ans;
	}

	static pair<int, int> answer(vector<int> &arr, int target) {
		pair<int, int> arrr;
		int n = arr.size();
		int x = target;
		int f = findFloor(arr, n, x);
		int c = findCeil(arr, n, x);
		return make_pair(f, c);
	}
};


int main() {
	vector<int> arr = {0, 12, 58, 1, 8,};
	int target = 9;
	pair<int, int> val = Solution::answer(arr, target);
	cout<<val.first<<","<<val.second;

}