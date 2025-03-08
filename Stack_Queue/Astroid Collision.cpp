//
// Created by Gaurav Kesh Roushan on 24/02/25.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> asteroidCo`llision(vector<int>& a) {
		vector<int> arr;
		int n = a.size();
		stack<int> stk;

		for (int i = 0; i < n; i++) {
			bool destroyed = false;
			while (!stk.empty() && stk.top() > 0 && a[i] < 0) {
				if (stk.top() < -a[i]) {
					stk.pop();
					continue;
				} else if (stk.top() == -a[i]) {
					stk.pop();
				}
				destroyed = true;
				break;
			}
			if (!destroyed) {
				stk.push(a[i]);
			}
		}

		while (!stk.empty()) {
			arr.insert(arr.begin(), stk.top());
			stk.pop();
		}

		return arr;
	}
};
