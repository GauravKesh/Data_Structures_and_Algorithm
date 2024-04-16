//
// Created by Gaurav Kesh Roushan on 16/04/24.
//
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
	static std::vector<std::vector<int>> brute(std::vector<std::vector<int>> &arr) {
		int n = arr.size();
		std::vector<std::vector<int>> ar;
		for (int i = 0; i < n; i++) {
			int start = arr[i][0];
			int end = arr[i][1];
			if(!ar.empty() && arr.back()[1]>=end) continue;
			for(int j = i+1;j<n;j++){
				if(arr[j][0]<=end){
					end = std::max(arr[j][1],end);
				}
				else{
					break;
				}
			}
			ar.push_back({start,end});
		}
		return ar;

	}
};


class Optimal {
public:
	static std::vector<std::vector<int>> optimal(std::vector<std::vector<int>> &arr) {
		int n = arr.size();
		sort(arr.begin(),arr.end());
		std::vector<std::vector<int>> ar;
		for (int i = 0; i < n; i++) {
			if(!ar.empty()|| arr[i][0] >ar.back()[1]){
				ar.push_back(arr[i]);
			}
			else{
				ar.back()[1] = max(ar.back()[1],arr[i][1]);
			}
		}
		return ar;
	}
};



int main() {
	std::vector<std::vector<int>> arr = {{1,  3},
										 {2,  6},
										 {8,  10},
										 {15, 18}};
	int b = 6;
	std::vector<std::vector<int>> brute = Solution::brute(arr);
	std::vector<std::vector<int>> optimal = Solution::brute(arr);
	for(auto it:optimal){
		for (int i = 0; i < 2; i++) {
			std::cout<<it[i]<<" ";
		}std::cout<<std::endl;

	}
}