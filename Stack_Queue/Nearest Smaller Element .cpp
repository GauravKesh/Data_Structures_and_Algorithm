//
// Created by Gaurav Kesh Roushan on 09/02/25.
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
	vector<int>
	nextSmallerElement(
			vector<int> &A) {
		stack<int> stk;
		int n = A.size();
		vector<int> res(n,
						-1);
		//{34, 35, 27, 42, 5, 28, 39, 20, 28};
		for (int i=0;i<n;i++) {
			while (!stk.empty() &&
				   stk.top() >=
				   A[i]) {

				stk.pop();
			}
			if (!stk.empty()) {
				res[i] = stk.top();
			}
			stk.push(A[i]);
		}

		return res;
	}



};



int main() {
	vector<int> n = {34, 35,
					 27, 42,
					 5, 28,
					 39, 20,
					 28};
	Solution obj;
	vector<int> ans = obj.nextSmallerElement(
			n);
	for (int n: ans) {
		cout << n << ",";
	}
}