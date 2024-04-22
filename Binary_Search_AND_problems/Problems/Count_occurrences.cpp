//
// Created by Gaurav Kesh Roushan on 22/04/24.
//
#include <iostream>
#include <vector>

using  namespace std;

int start(vector<int> &arr, int n, int key) {
	int low = 0, high = n - 1;
	int start = -1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] == key) {
			start = mid;
			high = mid - 1;
		} else if (arr[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return start;
}

int end(vector<int> &arr, int n, int key) {
	int low = 0, high = n - 1;
	int last = -1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] == key) {
			last = mid;
			low = mid + 1;
		} else if (arr[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return last;
}

int searchRange(vector<int> &v, int key) {
	int n = v.size();
	if (n == 0) return 0; // If the array is empty, return 0.
	int start_index = start(v, n, key);
	if (start_index == -1) return 0; // If key is not found, return 0.
	int end_index = end(v, n, key);
	return end_index - start_index + 1;
}

int cont(vector<int> &v, int key) {
	int cnt = searchRange(v, key);
	return cnt;
}

int main() {
	vector<int> v = {1, 2, 2, 2, 3, 4, 5};
	int key = 2;
	cout << "Count of " << key << " is " << cont(v, key)<< endl;
	return 0;
}
