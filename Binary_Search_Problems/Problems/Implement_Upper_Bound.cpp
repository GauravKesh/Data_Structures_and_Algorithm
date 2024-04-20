//
// Created by Gaurav Kesh Roushan on 20/04/24.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	static int answer(vector<int>&arr,int target){
		int n =  arr.size();
		int low =0,high =n-1;
		int ans = n;
		while(low<=high){
			int mid =(low+high)/2;
			if(arr[mid]>target){
				ans = mid;
				high = mid-1;
			}
			else{
				low = mid+1;
			}
		}

		return ans;
	}
};

// using Stl...
class STL{
public:
	static int val(vector<int>&arr,int target){
		int value = upper_bound(arr.begin(),arr.end(),target)-arr.begin();
		return value;
	}
};


int main(){
	vector<int> arr = {0,12,58,1,8,};
	int target = 9;
	int val =  Solution::answer(arr,target);
	int val1 =  STL::val(arr,target);
	cout<<val<<endl;
	cout<<val1;
}