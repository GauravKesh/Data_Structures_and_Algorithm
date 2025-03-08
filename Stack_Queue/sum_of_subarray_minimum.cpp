//
// Created by Gaurav Kesh Roushan on 10/02/25.
//

/*
				Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr.
				 Since the answer may be large, return the answer modulo 109 + 7.

				Example 1:

				Input: arr = [3,1,2,4]
				Output: 17
				Explanation:
				Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
				Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
				Sum is 17.
				Example 2:

				Input: arr = [11,81,94,43,3]
				Output: 444


				Constraints:

				1 <= arr.length <= 3 * 104
				1 <= arr[i] <= 3 *

*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class  Solution{
public:
	int sumOfSubarrayMinBrute(vector<int> &arr){
		int sum=0;
		int mod = (int)(1e9 +7);
		int n = arr.size();
		for(int i=0;i<n;i++){
			int minn  =  arr[i];
			for(int j=i;j<n;j++){
				minn =min(minn,arr[j]);
				sum = (sum+minn)%mod;
			}
		}
		return sum;

	}
	 /*Need to revise once more*/
	int sumOfSubarrayMinBest(vector<int> &arr ){
		int sum=0;
		int mod = (int)(1e9 +7);
		int n = arr.size();

		vector<int> left(n),right(n);
		stack<pair<int,int>> s1,s2;
		for (int i = 0; i < n; i++) {
			int count = 1;
			while (!s1.empty() && s1.top().first > arr[i]) {
				count += s1.top().second;
				s1.pop();
			}
			left[i] = count;
			s1.push({arr[i], count});
		}
		for (int i = n - 1; i >= 0; i--) {
			int count = 1;
			while (!s2.empty() && s2.top().first >= arr[i]) {
				count += s2.top().second;
				s2.pop();
			}
			right[i] = count;
			s2.push({arr[i], count});
		}
		long long result = 0;
		for (int i = 0; i < n; i++) {
			result = (result + (long long)arr[i] * left[i] * right[i]) % mod;
		}

		return result;


	}
};



int main(){
	vector<int> arr = {1,2,3};
	Solution sol;
	int s = sol.sumOfSubarrayMinBrute(arr);
	cout<<s;
}