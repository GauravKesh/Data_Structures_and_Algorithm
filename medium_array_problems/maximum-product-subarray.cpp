//
// Created by Gaurav Kesh Roushan on 18/04/24.
//
#include <iostream>
#include <vector>

using namespace std;

class Brute {
public:
	static int brute(vector<int>& arr) {
		int n = arr.size();
		int prd=INT_MIN;
		for(int i=0;i<n;i++){
			int p =1;
			for(int j = i;j<n;j++){
				p *= arr[j] ;
				prd = max(p,prd);
			}
		}
		return prd;
	}
};


class Optimal{
public:
	static int optimal(vector<int> &arr){
		int prd = INT_MIN;
		int n = arr.size();
		int pre = 1, suf = 1;
		for (int i = 0; i < n; i++) {
			if (pre== 0)
				pre = 1;
			if (suf == 0)
				suf = 1;
			pre *= arr[i];
			suf *= arr[n - i - 1];
			prd = max(prd, max(suf, pre));
		}

		return prd;
	}
};

int main(){
	vector<int> arr = {1,1,11,1,1,11,1,1,};
//	 int brute = Brute::brute(arr);
	 int optimal = Optimal::optimal(arr);
	 cout<<optimal;
}