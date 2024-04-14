//
// Created by Gaurav Kesh Roushan on 14/04/24.
//

#include <iostream>
#include<vector>
#include <unordered_map>

using namespace std;

class Optimal{
public:
	static int  optimal(vector<int>&arr){
		int n = arr.size();
		int size = 0;
		int preSum =  0;
		unordered_map<int,int> mpp;
		for (int i = 0; i < n; i++) {
			preSum +=arr[i];
			if(preSum==0){
				size = i+1;

			} else{
				if(mpp.find(preSum)!=mpp.end()){
					size = max(size,i-mpp[preSum]);
				} else{
					mpp[preSum] = i;
				}
			}
		}
		return size;
	}
};


int main(){
	vector<int> arr ={-1, -1, 2, 0, 1};

	int num =  Optimal::optimal(arr);
	cout<<num;
}