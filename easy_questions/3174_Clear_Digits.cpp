//
// Created by Gaurav Kesh Roushan on 28/11/24.
//
#include <cctype>
#include <stack>

class Solution {
public:
	string clearDigits(string s) {
		stack<char> stack;
		for (char c : s) {
			if (isdigit(c)) {
				if (!stack.empty()) {
					stack.pop();
				}
			} else {
				stack.push(c);
			}
		}
		std::string result;
		while (!stack.empty()) {
			result = stack.top() + result;
			stack.pop();
		}

		return result;


	}
};
