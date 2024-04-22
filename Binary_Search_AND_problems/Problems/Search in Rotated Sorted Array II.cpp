//
// Created by Gaurav Kesh Roushan on 22/04/24.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	static bool search(vector<int>&arr,int target){
		int n =  arr.size();
		int low = 0,high = n-1;
		while(low<=high){
			int mid = (low+high)/2;
			if(arr[mid] == target) return true;
			if(arr[low]==arr[mid] &&arr[mid] == arr[high]){
				low++,high--;
				continue;
			}


			// to check if left half is sorted;
			if(arr[low]<=arr[mid]){
				// to check iff target lies in left half;
				if(target>=arr[low]&& target<=arr[mid] ){
					high = mid-1;
				}else{
					low = mid+1;
				}
			}
				// if right half is sorted
			else{
				// it'll check if the target lies between right half
				if(target>=arr[mid]&& target<=arr[high] ){
					low = mid+1;
				}else{
					high= mid-1;
				}
			}
		}
		return false;
	}
};

int main(){
	vector<int> arr = {7,8,9,1,2,2,3,4,5,6};
	int target = ;
	bool val =  Solution::search(arr,target);
	cout<<val<<endl;
}