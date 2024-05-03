//
// Created by Gaurav Kesh Roushan on 30/04/24.
//

//Partially understood but it's similar to median in two array you just need to modify some of the logic

#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
	static int kthElement(vector<int> &a, vector<int>& b, int n1, int n2, int k){
		//if n1 is bigger swap the arrays:
		if (n1 > n2) return kthElement(b, a,n2,n1,k);

		int n = n1 + n2; //total length
		//apply binary search:
		int low = max(k-n2,0), high = min(k,n1);
		int left =k; //length of left half
		while (low <= high) {
			int mid1 = (low + high) >> 1;
			int mid2 = left - mid1;
			//calculate l1, l2, r1 and r2;
			int l1 = INT_MIN, l2 = INT_MIN;
			int r1 = INT_MAX, r2 = INT_MAX;
			if (mid1 < n1) r1 = a[mid1];
			if (mid2 < n2) r2 = b[mid2];
			if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
			if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

			if (l1 <= r2 && l2 <= r1) {
				return max(l1, l2);
			}
				//eliminate the halves:
			else if (l1 > r2) high = mid1 - 1;
			else low = mid1 + 1;
		}
		return 0; //dummy statement
	}


};

int main(){
	vector<int> arr1 = {2, 3, 45};
	vector<int> arr2 = {4, 6, 7, 8};
	int n1 = arr1.size(), n2 = arr2.size();
	int k = 2;
	double ans =Solution::kthElement(arr1,arr2,n1,n2,k);
	cout << "The answer is: " << ans << "\n";
	return 0;

}
