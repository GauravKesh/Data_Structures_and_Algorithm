//
// Created by Gaurav Kesh Roushan on 24/04/24.
//
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	static int findPeakElement(vector<int>& arr) {
		int n = arr.size();
		// MANUAL CHECK
		if(n==1) return 0;
		if(arr[0]>arr[1]) return 0;
		if(arr[n-1]>arr[n-2]) return n-1;
		int low = 1 ,high = n-2;
		//BINARY SEARCH
		while(low<=high){
			int mid  = (low+high)/2;
			if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
			else if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1]){
				low = mid+1;
			}
			else if(arr[mid]>arr[mid+1] && arr[mid]<arr[mid-1]){
				high = mid-1;
			}
			else{
				low = mid+1;
			}
		}
		return -1;
	}
};


int main() {
	vector<int> arr = {1,2,3,5,4};
	int ans = Solution::findPeakElement(arr);
	cout << "The single element is: - " << ans << "\n";
	return 0;
}