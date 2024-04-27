//
// Created by Gaurav Kesh Roushan on 27/04/24.
//
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
	static int findKthPositive(vector<int>& arr, int k) {
		int n = arr.size();
		int low = 0, high = n - 1;
		while(low<=high){
			int mid = (low+high)/2;
			int miss = arr[mid]-(mid+1);
			if(miss<k){
				low =mid+1;
			}else{
				high =mid-1;
			}
		}
		return high+k+1;
	}
};








int main() {
	vector<int> arr = {2,3,4,7,11};
	int nMiss = 5;
	int ans = Solution::findKthPositive(arr,nMiss);
	cout << "The missing   number  is: - " << ans << "\n";
	return 0;
}