//
// Created by Gaurav Kesh Roushan on 22/11/24.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
	static bool bs(vector<int>& arr, int num) {
		int l = 0;
		int r = arr.size() - 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (arr[mid] == num) {
				return true;
			} else if (arr[mid] > num) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		return false;
	}

public:
	static int getCommon(vector<int>& nums1, vector<int>& nums2) {
		int k = INT_MAX;
		int i, j;
		int n = max(nums1.size(), nums2.size());
		int m = min(nums1.size(), nums2.size());
		for (i = 0; i < n; i++) {
			if (nums1.size() == n) {
				if (Solution::bs(nums2, nums1[i])) {
					k = min(k, nums1[i]);
				}
			} else {
				if (Solution::bs(nums1, nums2[i])) {
					k = min(k, nums2[i]);
				}
			}
		}
		return (k==INT_MAX)? -1:k;
	}
};


int main(){
	vector<int>n =  {1,2,3,6};
	vector<int>m =  {2,3,4,5};
	cout<<Solution::getCommon(n,m);
}