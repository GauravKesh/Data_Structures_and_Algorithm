//
// Created by Gaurav Kesh Roushan on 10/02/25.
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*Need tp revisit and revise it again*/

class SolutionBruteForce{
private:
	vector<int> sufixMax(vector<int> &arr){

	}
	vector<int> prefixMax(vector<int> &arr){

	}
public:
	int totalTappedWater(vector<int> &arr){


	}
};

class SolutionOptimal{

public:
	int totalTappedWater(vector<int> &arr){
		int lMax,rMax,total,l,r,n;
		n = arr.size();
		lMax=rMax=total=l=0;
		r = n-1;

		while(l<r){
			if(arr[l]<=arr[r]){
				if(lMax>arr[l]){
					total+=lMax-arr[l];
				}else{
					lMax = arr[l];
				}
				l=l+1;
			}else{
				if(rMax>arr[r]){
					total+=rMax - arr[r];
				}else{
					rMax = arr[r];
				}
				r = r-1;
			}
		}
		return total;

	}
};