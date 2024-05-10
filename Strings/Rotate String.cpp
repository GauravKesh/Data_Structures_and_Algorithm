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
		// if len !=  then return false;
		if (n > goal.length()) return false;

		// iterate through each char
		for (int i = 0; i < n; i++) {
			//push first in last
			s.push_back(s[i]);
			// check from ith+1 position to end it giving string or not
			if (s.substr(i + 1) == goal) return true;
		}
		// check from begining...
		return s.substr(j) == goal;
	}
};


int main() {
	string s = "abcde";
	string goal = "cdeab";
	bool k = Solution::rotateString(s, goal);
	cout << k;
}