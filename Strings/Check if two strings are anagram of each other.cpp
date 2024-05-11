//
// Created by Gaurav Kesh Roushan on 11/05/24.
//
#include<iostream>
#include<string>

using namespace std;



class Solution {
public:
	static bool isAnagram(string s, string t) {
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		if (s == t) return true;
		return false;

	}
};


int main() {
	string s = "anagram";
	string t = "nagaram";
	bool k = Solution::isAnagram(s, t);
	cout << k;
}

