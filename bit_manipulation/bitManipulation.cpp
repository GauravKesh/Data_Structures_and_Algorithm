//
// Created by Gaurav Kesh Roushan on 24/12/24.
//
#include <iostream>
#include <string>
#include <algorithm>
using  namespace std;

class BitManipulation{
public:
	/* Decimal To Binary Conversion*/
	 static string convertToBinary(int num) {
		if (num == 0) {
			return "0";
		}

		string res;
		while (num > 0) {
			if (num % 2 == 0) {
				res += "0";
			} else {
				res += "1";
			}
			num /= 2;
		}

		// Reverse the string to get the correct binary representation
		reverse(res.begin(), res.end());

		return res;
	}

	/* Decimal from Binary Conversion*/

	void static convertToDecimal(string s){
		int len = s.size();
		int p2=1;
		int num = 0;
		for(int i = len-1;i>=0;i--){
			  if(s[i]=='1'){
				  num+=p2;
			  }
			p2 = p2*2;
		}
		cout<<num;
	}

};


int main(){

	BitManipulation::convertToDecimal(BitManipulation::convertToBinary(200));
}