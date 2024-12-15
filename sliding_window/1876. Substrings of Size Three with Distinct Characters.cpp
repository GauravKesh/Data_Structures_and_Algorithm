//
// Created by Gaurav Kesh Roushan on 15/12/24.
//


class Solution {
public:
	int countGoodSubstrings(string s) {
		int c = 0;
		int n = s.size();
		for(int i=0;i<=n-3;i++){
			if (s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i] != s[i + 2]) {
				c++;
			}
		}
		return c;
	}
};