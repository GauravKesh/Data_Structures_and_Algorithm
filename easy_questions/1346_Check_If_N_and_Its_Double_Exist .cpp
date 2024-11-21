//
// Created by Gaurav Kesh Roushan on 21/11/24.
//
#include <iostream>
#include <vector>
using  namespace std;
class Solution {
public:
	static bool checkIfExist(vector<int>& arr) {
		int n = arr.size();
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(arr[i]==2*arr[j] || (arr[i]!=0 && arr[j]/arr[i]==2 && arr[j]%arr[i]==0)){
					return true;
				}
			}
		}
		return false;
	}
};

int main(){
	vector<int> arr = {0,2,5,3};
	cout<<Solution::checkIfExist(arr);
}