//
// Created by Gaurav Kesh Roushan on 28/10/24.
//
class Solution {
public:
	void reverseString(vector<char>& s) {
		int i = 0;
		int j = s.size()-1;
		while (i <= j) {
			if (i != j) {
				swap(s[i], s[j]);
				i++;
				j--;
			}else{
				break;
			}
		}
	}
};