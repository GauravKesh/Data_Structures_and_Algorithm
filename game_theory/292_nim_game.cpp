//
// Created by Gaurav Kesh Roushan on 09/03/26.
//
class Solution {
public:
	bool canWinNim(int n) {
		return n % 4 != 0;
	}
};


class Solution {
private:
	bool isPrime(int n) {
		if (n < 2)
			return false;

		for (long long int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				return false;
			}
		}
		return true;
	}

public:
	bool canWinNim(int n) {
		if (n <= 3) {
			return true;
		}
		if (n % 4 == 0)
			return false;
		if (isPrime(n))
			return true;

		if (n % 3 == 0)
			return true;
		if(n%7==0){
			return true;
		}
		if (n % 2 == 0)
			return true;
		if (n % 5 == 0)
			return true;

		return false;
	}
};

// 1,2,3
// 1 2 3 4 5
// 1 2 3 4 5 6
// 1 2 3 4 5 6 7
