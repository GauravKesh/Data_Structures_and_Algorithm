//
// Created by Gaurav Kesh Roushan on 04/05/24.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	static string removeOuterParentheses(string s) {
		string r;
		int open = 0;
		for (char c: s) {
			if (c == '(') {
				if (open >= 1) {
					r += c;
				}
				open++;
			} else {
				if (open >= 2) {
					r += c;
				}
				open--;
			}
		}
		return r;
	}

};

int main() {
	string s = "(()())(())";
	int n = 3, m = 3;
	cout <<Solution::removeOuterParentheses(s) << '\n';
}

