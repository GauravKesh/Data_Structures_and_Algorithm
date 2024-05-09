//
// Created by Gaurav Kesh Roushan on 09/05/24.
//



#include <iostream>
#include <unordered_map>

bool isIsomorphic(std::string s, std::string t) {
	if (s.size() != t.size())
		return false;

	std::unordered_map<char, char> s_to_t_mapping;
	std::unordered_map<char, char> t_to_s_mapping;

	for (size_t i = 0; i < s.size(); ++i) {
		char char_s = s[i];
		char char_t = t[i];

		if (s_to_t_mapping.find(char_s) == s_to_t_mapping.end() && t_to_s_mapping.find(char_t) == t_to_s_mapping.end()) {
			s_to_t_mapping[char_s] = char_t;
			t_to_s_mapping[char_t] = char_s;
		} else {
			if (s_to_t_mapping[char_s] != char_t || t_to_s_mapping[char_t] != char_s)
				return false;
		}
	}

	return true;
}

int main() {
	std::cout << std::boolalpha;
	std::cout << isIsomorphic("egg", "add") << std::endl;   // true
	std::cout << isIsomorphic("foo", "bar") << std::endl;   // false
	std::cout << isIsomorphic("paper", "title") << std::endl;  // true
	return 0;
}
