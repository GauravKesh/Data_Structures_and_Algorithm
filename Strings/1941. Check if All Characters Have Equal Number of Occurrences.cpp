//
// Created by Gaurav Kesh Roushan on 24/12/24.
//

class Solution {
public:
	bool areOccurrencesEqual(string s) {
		map<char, int> mp;
		for (char c : s) {
			mp[c]++;
		}
		int firstCount = mp.begin()->second;
		for (auto& entry : mp) {
			if (entry.second != firstCount) {
				return false;
			}
		}
		return true;
	}
};
