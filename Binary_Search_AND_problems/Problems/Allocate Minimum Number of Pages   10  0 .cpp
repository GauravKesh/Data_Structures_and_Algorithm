//
// Created by Gaurav Kesh Roushan on 28/04/24.
//
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
	static int countStudents(vector<int> &arr, int pages) {
		int n = arr.size(); //size of array.
		int students = 1;
		int ans =2;
		long long pagesStudent = 0;
		for (int i = 0; i < n; i++) {
			if (pagesStudent + arr[i] <= pages) {
				//add pages to current student
				pagesStudent += arr[i];
			} else {
				//add pages to next student
				students++;
				pagesStudent = arr[i];
			}
		}
		return students;
	}

	static int findPages(vector<int> &arr, int n, int m) {
		//book allocation impossible:
		if (m > n) return -1;

		int low = *max_element(arr.begin(), arr.end());
		int high = accumulate(arr.begin(), arr.end(), 0);
		while (low <= high) {
			int mid = (low + high) / 2;
			int students = countStudents(arr, mid);
			if (students > m) {
				low = mid + 1;
			} else {

				high = mid - 1;
			}
		}
		return low;
	}
};

int main() {
	vector<int> arr = {25, 46, 28, 49, 24};
	int n = 5;
	int m = 4;
	int ans =Solution::findPages(arr, n, m);
	cout << "The answer is: " << ans << "\n";
	return 0;
}