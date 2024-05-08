//
// Created by Gaurav Kesh Roushan on 09/05/24.
//
#include <iostream>
#include <vector>
#include<string>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		std::sort(strs.begin(), strs.end());
		if (strs.size() == 1) {
			return strs[0];
		}
		if (strs[0] == strs[strs.size() - 1]) {
			return strs[0];
		}
		for (int i = 0; i < strs[0].length(); i++) {
			if (strs[strs.size() - 1][i] != strs[0][i]) {
				return strs[0].substr(0, i);
			}
		}
		return strs[0];
	}
};


int main() {
	vector<string> s = {"flower","flow","flight"};
	Solution ob1;
	cout << ob1.longestCommonPrefix(s) << '\n';
//	cout << "HELLO";
}

