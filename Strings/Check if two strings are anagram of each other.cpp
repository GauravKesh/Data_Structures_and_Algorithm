//
// Created by Gaurav Kesh Roushan on 11/05/24.
//
#include<iostream>
#include<string>
#include <vector>

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
/*Sorting both strings has a time complexity of O((n+m)log(n+m)),
 which could be inefficient for large strings.*/

/*to optimise this we'll be using hashmap method*/

class SolutionOptimal {
public:
	static bool isAnagram(string &s, string &t) {
		if (s.length() != t.length()) {
			return false;
		}
		vector<int> cnt(26, 0);
		for (char c: s) {
			cnt[c - 'a']++;

		}
		for (char c: t) {
			cnt[c - 'a']--;
		}
		for (int c: cnt) {
			if (c != 0)
				return false;
		}
		return true;
	}
};


int main() {
	string s = "anagram";
	string t = "nagaram";
	bool k = SolutionOptimal::isAnagram(s, t);

	cout << k;
}

