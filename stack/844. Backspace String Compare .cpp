//
// Created by Gaurav Kesh Roushan on 01/04/26.
//
class Solution {
private:
	string process(string s) {
		string res = "";
		int n = s.size();
		for (char c : s) {
			if (c == '#') {
				if (!res.empty()) res.pop_back();
			} else {
				res.push_back(c);
			}
		}
		return res;
	}

public:
	bool backspaceCompare(string s, string t) {
		return process(s) == process(t);
	}
};