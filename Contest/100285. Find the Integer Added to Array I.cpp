//
// Created by Gaurav Kesh Roushan on 28/04/24.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	static int addedInteger(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int a = nums2.size();
		int ad =INT_MAX;
		sort(nums2.begin(),nums2.end());
		if(n ==1){
			ad=nums2[0]-nums1[0];
			return ad;
		}
		return ad;
	}
};


int main() {
	vector<int> a = {2, 6, 4};
	vector<int> b = {9, 7, 5};

	int val = Solution::addedInteger(a, b);
	cout << val;
}