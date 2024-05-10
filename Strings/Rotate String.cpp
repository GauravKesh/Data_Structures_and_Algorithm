//
// Created by Gaurav Kesh Roushan on 10/05/24.
//
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	static bool rotateString(string s, string goal) {
		int j = 0;
		int n = s.length();
		if (n > goal.length()) return false;
		for (int i = 0; i < n; i++) {
			s.push_back(s[i]);
			if (s.substr(i + 1) == goal) return true;
		}
		return s.substr(j) == goal;
	}
};


int main() {
	string s = "abcde";
	string goal = "cdeab";
	bool k = Solution::rotateString(s, goal);
	cout << k;
}