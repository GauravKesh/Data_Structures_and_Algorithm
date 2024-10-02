//
// Created by Gaurav Kesh Roushan on 16/05/24.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>




int main() {
	std::string s = "III";
	std::string s1 = "LVIII";
	std::string s2 = "MCMXCIV";

	int n = Solution::romanToInt(
			s2);
//	int n1 = SolutionOptimal::romanToInt(
//			s2);
	std::cout << n<<std::endl;
//	std::cout << n1<<std::endl;
