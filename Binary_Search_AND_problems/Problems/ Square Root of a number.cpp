//
// Created by Gaurav Kesh Roushan on 24/04/24.
//

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	static int findPeakElement(int& n) {
		long long low =1,high =n;
		int ans =1;
		while(low<=high){
			long long mid = (low+high)/2;
			long long val = mid*mid;
			if(val<=n){
				low = mid+1;
			}
			else{
				high = mid-1;
			}
		}
		return (int)high;
	}
};


int main() {
	int a = 2;
	int ans = Solution::findPeakElement(a);
	cout << "The single element is: - " << ans << "\n";
	return 0;
}