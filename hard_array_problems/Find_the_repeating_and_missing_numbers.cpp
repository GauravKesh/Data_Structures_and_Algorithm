
//
// Created by Gaurav Kesh Roushan on 17/04/24.
//

#include <vector>
#include <iostream>
using namespace std;


class Brute{
public:
	static vector<int> brute(vector<int> &a){
		int n = a.size(); // size of the array
		int repeating = -1, missing = -1;

		//Find the repeating and missing number:
		for (int i = 1; i <= n; i++) {
			//Count the occurrences:
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (a[j] == i) cnt++;
			}

			if (cnt == 2) repeating = i;
			else if (cnt == 0) missing = i;

			if (repeating != -1 && missing != -1)
				break;
		}
		return {repeating, missing};
	}
};

class Better{
public:
	static vector<int> better(){

		vector<int> arr = {1,2,2,3,4,5};
		int n=  arr.size();
		int  hash[7] = {0}; // hash array
		for(int i = 0;i<n;i++){
			hash[arr[i]]++; //  to increment occurrence;
		}
		int repeat =  -1 ,miss = -1;
		for(int j = 1;j<=n;j++){
			if(hash[j] ==2){
				repeat = j;
			}
			else if(hash[j]==0 ){
				miss = j;
			}
			if (repeat != -1 && miss != -1)
				break;
		}

		return {miss,repeat};
	}
};


class Optimal1{
public:
	static vector<int> optimal1(vector<int> &arr){
		int n =  arr.size();
		long long Sn = (n*(n+1))/2;
		long long S2n  = (n*(n+1)*(2*n+1))/6;
		long long S = 0 , S2 =0;
		for(int i =0 ;i<n;i++){
			S += arr[i];
			S2 += (long long)arr[i]*(long long)arr[i];
		}
		long long val1 = S - Sn; // x-y;
		long long val2 = S2 - S2n;
		val2 = val2/val1 ;// x+y
		long long  x= (val1 + val2)/2;
		long long   y = x -  val1;
		return{(int)x,(int)y};
	}

};


int main(){
	vector<int> arr = {1,2,2,3,4,5};
	int n =  6;
	vector<int> better =  Better::better();
	vector<int> brute =  Brute::brute(arr);
	vector<int> optimal1 =  Optimal1::optimal1(arr);

	for(const auto &it:optimal1){
		cout<<it<<" ";
	}
}