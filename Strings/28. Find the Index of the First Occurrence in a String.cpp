//
// Created by Gaurav Kesh Roushan on 09/12/24.
//

/*using builtin methods*/
class Solution1 {
public:
	int strStr(string haystack, string needle) {
		int ind =-1; // index of first occurance
		return haystack.find(needle);
	}
};

/*Making own function to check*/
class Solution2 {
public:
	int strStr(string haystack, string needle) {
		if (haystack.length() < needle.length()) {
			return -1;
		}

		for (int i = 0; i <= haystack.length() - needle.length(); i++) {
			if (haystack.substr(i, needle.length()) == needle) {
				return i;
			}
		}

		return -1;
	}
};