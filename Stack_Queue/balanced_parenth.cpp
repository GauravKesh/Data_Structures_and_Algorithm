//
// Created by Gaurav Kesh Roushan on 06/02/25.
//
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {

public:
	stack<char> stk;
	bool balanced(string s) {

		int n = s.size();
		for (int i = 0; i < n; i++) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[') {  // Fix: '[' instead of ']'
				stk.push(s[i]);
			} else {
				if (stk.empty()) {
					return false;
				}
				char ch = stk.top();
				stk.pop();
				if ((s[i] == ')' && ch == '(') ||
					(s[i] == '}' && ch == '{') ||
					(s[i] == ']' && ch == '[')) {
					continue;
				} else {
					return false;
				}
			}
		}
		return stk.empty();
	}
};

/* Main Function */
int main() {
	string p;
	cin >> p;
	Solution sol;  // Create an object
	bool status = sol.balanced(p);  // Call the method on the object
	cout << (status ? "true" : "false") << endl;
	return 0;
}
