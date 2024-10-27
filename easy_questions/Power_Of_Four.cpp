//
// Created by Gaurav Kesh Roushan on 27/10/24.
//
#include <iostream>
using  namespace std;
class Solution {
private:
	static int isPower(int n){
		if(n==1){
			return 1;
		}
		if (n < 1 || n % 4 != 0) {
			return 0;
		}
		return isPower(n/4);

	}

public:
	static bool isPowerOfFour(int n) {
		if(n<=0){
			return false;
		}else if(n==1){
			return true;
		}
		int l = isPower(n);
		if(l==1){
			return true;
		}
		return false;
	}
};


int main(){
	int n = 16;
	std::cout<<Solution::isPowerOfFour(n);
}