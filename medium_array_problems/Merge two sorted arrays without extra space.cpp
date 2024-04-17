//
// Created by Gaurav Kesh Roushan on 17/04/24.
//

#include <iostream>
#include <vector>
using  namespace std;

class Brute{
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		nums1.erase(nums1.begin()+m,nums1.end());
		for(auto it:nums2){
			nums1.push_back(it);
		}
		sort(nums1.begin(),nums1.end());


	}
};