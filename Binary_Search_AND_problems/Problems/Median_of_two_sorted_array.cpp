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

int main() {
	vector<int> arr1 = {1,3};
	vector<int> arr2 = {2};
	double ans =Solution::findMedianSortedArrays(arr1,arr2);
	cout << "The answer is: " << ans << "\n";
	return 0;
}