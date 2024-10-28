//
// Created by Gaurav Kesh Roushan on 28/10/24.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool static
	containsDuplicate(
			vector<int> &nums) {
		int n = nums.size();
		int cnt = 1;
		for (int i = 0;
			 i < n; i++) {
			for (int j =
					i + 1;
				 j < n; j++) {
				cout
						<< nums[j]
						<< endl;
				if (nums[i] ==
					nums[j]) {
					cnt++;
				}
			}
			cout << endl
				 << "count:-"
				 << cnt
				 << endl;

		}
		if (cnt > 1) {
			return true;
		}
		return false;
	}
};


int main() {
	vector<int> arr = {1,
					   2,
					   3,
					   1};
	cout
			<< Solution::containsDuplicate(
					arr);

}