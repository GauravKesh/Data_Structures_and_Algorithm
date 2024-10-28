//
// Created by Gaurav Kesh Roushan on 28/10/24.
//
#include <iostream>
using namespace std;
class Solution {
public:
	int static arrangeCoins(int n) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (n >= i) {
				cnt++;
				n -= i;
//				k
			}
		}
		return cnt;
	}
};

int main(){
	int n = 11;
	cout<<Solution::arrangeCoins(n);
}