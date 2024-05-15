//
// Created by Gaurav Kesh Roushan on 12/05/24.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
	static string
	frequencySort(string s) {
		std::unordered_map<char, int> frq;
		for (char c: s) {
			frq[c]++;
		}
		// unordered map converted to a vector...
		std::vector<std::pair<char, int>> sorted_chars(
				frq.begin(),
				frq.end());
		// to sort frequency in descending order...
		// used lambda function ...
		std::sort(
				sorted_chars.begin(),
				sorted_chars.end(),
				[](const std::pair<char, int> &a,
				   const std::pair<char, int> &b) {
					return a.second >
						   b.second;
				});
		std::string result;
		for (const auto &p: sorted_chars) {
			result.append(
					p.second,
					p.first);
		}
		return result;


	}
};


int main() {
	std::string s = "cCKAAbbbb";
	std::string k = Solution::frequencySort(
			s);
	std::cout << k;
}


/// EXPLANATION : --

/*Counting Frequencies:

We use an unordered_map to count the frequency of each character in the string. The key is the character, and the value is the count of how many times it appears.
cpp

std::unordered_map<char, int> freq;
for (char c : s) {
    freq[c]++;
}
Storing Frequencies in a Vector of Pairs:

We convert the unordered_map to a std::vector of std::pair<char, int>. Each pair contains a character and its frequency.
cpp

std::vector<std::pair<char, int>> sorted_chars(freq.begin(), freq.end());
Sorting by Frequency:

We use std::sort with a custom comparator function to sort the vector of pairs. The lambda function provided as the comparator ensures the pairs are sorted by their second element (frequency) in descending order.
cpp

std::sort(sorted_chars.begin(), sorted_chars.end(), [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
    return a.second > b.second;
});
std::sort(sorted_chars.begin(), sorted_chars.end(), ...); calls the sort function on the vector.
		The lambda function [](const std::pair<char, int>& a, const std::pair<char, int>& b) { return a.second > b.second; }
 		compares two pairs a and b and returns true if a should come before b (i.e., if a's frequency is greater than b's frequency).

Constructing the Result String:

We iterate over the sorted vector and build the result string by repeating each character according to its frequency.
cpp

std::string result;
for (const auto& p : sorted_chars) {
    result.append(p.second, p.first);  // Append 'p.first' character 'p.second' times
}
result.append(p.second, p.first); appends the character p.first p.second times to the result string.
Summary:
By using these steps, the code efficiently counts, sorts, and constructs the final string based on character frequencies using C++ data structures like unordered_map, vector, and string. The std::sort function with a custom comparator allows sorting the characters by frequency in descending order effectively.*/