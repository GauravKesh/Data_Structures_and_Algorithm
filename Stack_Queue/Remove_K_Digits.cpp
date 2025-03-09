//
// Created by Gaurav Kesh Roushan on 09/03/25.
//
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	string removeKdigits(string num, int k) {
		string stk = "";
		int n = num.size();
		for (char digit : num) {
			while (!stk.empty() && k > 0 && stk.back() > digit) {
				stk.pop_back();
				k--;
			}
			stk.push_back(digit);
		}
		while (k > 0 && !stk.empty()) {
			stk.pop_back();
			k--;
		}
		int i = 0;
		while (i < stk.size() && stk[i] == '0') {
			i++;
		}
		stk = stk.substr(i);

		return stk.empty() ? "0" : stk;
	}
};