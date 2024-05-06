//
// Created by Gaurav Kesh Roushan on 06/05/24.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string largestOddNumber(string num) {
		int end = num.size() - 1;
		while (end >= 0 && !(num[end] & 1)) {
			end--;
		}
		return num.substr(0, end + 1);
	}
};


int main() {
	string s = "4206";
	Solution ob1;
	cout << ob1.largestOddNumber(s) << '\n';
//	cout << "HELLO";
}

