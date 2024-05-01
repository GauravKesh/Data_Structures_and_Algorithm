//
// Created by Gaurav Kesh Roushan on 30/04/24.
//


#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
	double static findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
		int i = 0, j = 0;
		int n1, n2, n;
		n1 = arr1.size();
		n2 = arr2.size();
		n = n1 + n2;
		int ele1 = -1, ele2 = -1;
		int ind2 = n / 2;
		int ind1 = ind2 - 1;
		int cnt = 0;
		while (i < n1 && j < n2) {
			if (arr1[i] < arr2[j]) {
				if (cnt == ind1)
					ele1 = arr1[i];
				if (cnt == ind2)
					ele2 = arr1[i];
				// break;
				cnt++;
				i++;
			} else {
				if (cnt == ind1)
					ele1 = arr2[j];
				if (cnt == ind2)
					ele2 = arr2[j];
				// break;
				cnt++;
				j++;
			}
		}
		while (i < n1) {
			if (cnt == ind1)
				ele1 = arr1[i];
			if (cnt == ind2)
				ele2 = arr1[i];
			// break;
			cnt++;
			i++;
		}
		while (j < n2) {
			if (cnt == ind1)
				ele1 = arr2[j];
			if (cnt == ind2)
				ele2 = arr2[j];
			// break;
			cnt++;
			j++;
		}
		if (n % 2 == 1) {
			return ele2;
		}
		return (double)((double)(ele1 + ele2)) / 2.0;
	}
};
class SolutionOptimal{
public:
	double static kthElement(vector<int> &a, vector<int> &b) {
		int n1 = a.size(), n2 = b.size();
		//if n1 is bigger swap the arrays:
		if (n1 > n2) return kthElement(b, a);

		int n = n1 + n2; //total length
		int left = (n1 + n2 + 1) / 2; //length of left half
		//apply binary search:
		int low = 0, high = n1;
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
				if (n % 2 == 1) return max(l1, l2);
				else return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
			}

				//eliminate the halves:
			else if (l1 > r2) high = mid1 - 1;
			else low = mid1 + 1;
		}
		return 0; //dummy statement
	}

};

int main() {
	vector<int> arr1 = {2, 3, 45};
	vector<int> arr2 = {4, 6, 7, 8};
	double ans1 =Solution::findMedianSortedArrays(arr1,arr2);
	double ans2 =SolutionOptimal::kthElement(arr1,arr2);
	cout << "The answer is: " << ans << "\n";
	return 0;
}