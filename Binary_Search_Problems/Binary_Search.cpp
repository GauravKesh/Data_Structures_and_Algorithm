//
// Created by Gaurav Kesh Roushan on 20/04/24.
//

#include <iostream>
#include <vector>

using namespace std;

class BinarySearch {
public:
	static int search(vector<int> &arr, int target) {
		int n = arr.size();
		int low = 0, high = n - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (arr[mid] == target) {
				return mid;
				high = mid - 1;
			} else if (arr[mid] > target) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		return -1;
	}
};

int main() {
	vector<int> arr = {0, 12, 58, 1, 8,};
	int target = INT_MAX;
	int val = BinarySearch::search(arr, target);

	if (val != 1) cout << "Value not found";
	else
		cout << "Found at position " << val;


}