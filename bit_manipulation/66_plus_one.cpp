//
// Created by Gaurav Kesh Roushan on 24/03/26.
//
class Solution1{
public:
	vector<int> plusOne(vector<int>& d) {
		int n = d.size();
		int c = 1;

		for (int i = n - 1; i >= 0; i--) {
			int t = d[i] + c;
			d[i] = t % 10;
			c = t / 10;

			if (c == 0) return d;
		}

		if (c) d.insert(d.begin(), c);
		return d;
	}
};



class Solution2 {
public:
	vector<int> plusOne(vector<int>& d) {
		int c = 0;
		int n = d.size();
		vector<int> k;
		int m = d[n - 1] + 1; // intial sum;

		if (m <= 9 && n>=1) {
			d[n - 1] = m;
			return d;
		}

		if ( m > 9 && n == 1) {
			return {1,0};
		}


		k.push_back(m % 10); // push 1st digit
		c = m / 10;          // carry forward

		for (int i = n - 2; i >= 0; i--) {
			int t = d[i] + c;
			if (t <= 9) {
				k.push_back(t);
				c = 0;
			} else {
				k.push_back(t % 10);
				c = t / 10;
			}
		}

		if (c != 0) {
			k.push_back(c);
		}
		reverse(k.begin(), k.end());
		return k;
	}
};