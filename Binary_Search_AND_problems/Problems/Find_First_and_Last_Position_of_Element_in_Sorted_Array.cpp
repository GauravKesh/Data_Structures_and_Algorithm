//
// Created by Gaurav Kesh Roushan on 21/04/24.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution_One {
public:
	static int start(vector<int>& arr, int n, int key) {
		// int n = arr.size();
		int low = 0, high = n - 1;
		int start = -1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (arr[mid] >= key) {
				if (mid >= n) {
					start = mid;
				}
				start = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}

		return start;
	}
	static int end(vector<int>& arr, int n, int key) {
		int low = 0, high = n - 1;
		int end = -1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (arr[mid] > key) {
				end = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}

		return end;
	}

	static vector<int> searchRange(vector<int> &v, int key) {
		int n = v.size();
		vector<int> arr;
		int low = 0;
		int high = n - 1;
		int start = -1, end = -1;
		start = Solution_One::start(v, n, key);
		if (start == n || v[start] != key) return {-1, -1};
		//  end = upper_bound_fn(v, n, key);
		return {start, Solution_One::end(v, n, key) - 1};
	}
};

class Solution_Two {
public:
	static int start(vector<int> &arr, int n, int key) {
		int low = 0, high = n - 1;
		int start = -1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (arr[mid] == key) {
				start = mid;
				high = mid -1 ;
			} else if (arr[mid < key]) low = mid + 1;
			else high = mid - 1;
		}
		return start;
	}

	static int end(vector<int> &arr, int n, int key) {
		int low = 0, high = n - 1;
		int last = -1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (arr[mid] == key) {
				last = mid;
				low = mid + 1;
			} else if(arr[mid]<key) low = mid+1;
			else {
				high = mid - 1;
			}
		}
		return last;
	}

	static vector<int> searchRange(vector<int> &v, int key) {
		int n = v.size();
		vector<int> arr;
		int start = Solution_Two::start(v, n, key);
		if (start == -1) return {-1, -1};
		int last = Solution_Two::end(v, n, key);
		return {start, last};
	}

};

int main() {
	vector<int> arr = {0, 8,12, 58, 1, 8,8};
	sort(arr.begin(),arr.end());
	int target = 8;
	vector<int> index = Solution_One::searchRange(arr, target);
	vector<int> index2 = Solution_Two::searchRange(arr, target);
	cout << "Range of " << target << " is [" << index[0]<< ", " << index[1] << "]" << endl;
	cout << endl<<"Range of " << target << " is [" << index2[0] << ", " << index2[1]<< "]" << endl;
	cout << endl<<"Occurrence of number "<<target<<" is:-"<<index[1]-index[0]+1;
	return 0;
}