//
// Created by Gaurav Kesh Roushan on 06/05/24.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string largestOddNumber(string& num) {
		// to check string is empty !!
		if (num.empty())
			return num;
		string nu = num;
		int k = stoi(nu);  /// string to int ....
		// to check the number is odd !!
		if (k % 2 != 0)
			return num;
		if(k==0){
			return "";
		}
		int od;
		// checking each  digit of number to be odd if given digit is a even.....
		while (k != 0) {
			int m = k % 10; // to get each digit....
//			cout<<endl<<m<<endl;
			k = k / 10;     // to remove last element...
			if (m!=0 && m % 2 !=0 ) {
				od = max(od, m);
			}
		}
		return to_string(od);
	}
};




int main() {
	string s = "4206";
	Solution ob1;
	cout << ob1.largestOddNumber(s) << '\n';
//	cout << "HELLO";
}

