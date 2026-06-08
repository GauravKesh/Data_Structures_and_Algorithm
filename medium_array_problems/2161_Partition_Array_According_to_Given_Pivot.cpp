//
// Created by Gaurav Kesh Roushan on 08/06/26.
//

// brute force
class Solution {
public:
	vector<int> pivotArray(vector<int>& nums, int pivot) {
		int n = nums.size();
		vector<int> arr;
		vector<int> arr2;
		vector<int> arr3;
		for(int i=0;i<n;i++){
			if(nums[i]<pivot){
				arr.push_back(nums[i]);
			}else if(nums[i]>pivot){
				arr2.push_back(nums[i]);
			}else{
				arr3.push_back(nums[i]);
			}
		}
		arr.insert(arr.end(),arr3.begin(),arr3.end());
		arr.insert(arr.end(),arr2.begin(),arr2.end());
		return arr;

	}
};

//optimal
