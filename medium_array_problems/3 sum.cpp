//
// Created by Gaurav Kesh Roushan on 10/04/24.
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;

///brute Force....

class ThreeSum {
public:
	 static vector<vector<int>> threeSum(vector<int> &arr ,int n) {
		set<vector<int>> st;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					if (arr[i] + arr[j] + arr[k] == 0) {
						vector<int> pair = {arr[i], arr[j], arr[k]};
						sort(pair.begin(), pair.end());
						st.insert(pair);
					}
				}
			}
		}
		 vector<vector<int>> threePairSum(st.begin(),st.end());
		 return threePairSum;
	}
};


class ThreeSumBetter{
public:
	static vector<vector<int>> threeSum(vector<int> &arr,int n){
		set<vector<int>> pair;
		for(int i=0;i<n;i++){
			set<int> hashSet;
			for(int j = i+1;j<n;j++){
				int  num =  -(arr[i]+arr[j]);
				if(hashSet.find(num)!=hashSet.end()){
					vector<int> finalPair={arr[i],arr[j],num};
					sort(finalPair.begin(),finalPair.end());
					pair.insert(finalPair);
				}
				hashSet.insert(arr[j]);
			}
		}
		vector<vector<int>> threePairSum(pair.begin(),pair.end());
		return threePairSum;
	}
};

class ThreeSumOptimal{
public:
	static vector <vector<int>> threeSum( vector<int> &arr,int n) {
		vector <vector<int>> ans;
		sort(arr.begin(), arr.end());
		for (int i = 0; i < n; i++) {
			if (i != 0 && arr[i] == arr[i - 1]) continue;
			int j = i + 1;
			int k = n - 1;
			while (j < k) {
				int sum = arr[i] + arr[j] + arr[k];
				if (sum < 0) {
					j++;
				} else if (sum > 0) {
					k--;
				} else {
					vector<int> temp = {arr[i], arr[j], arr[k]};
					ans.push_back(temp);
					j++;
					k--;
					while (j < k && arr[j] == arr[j + 1])
						j++;
					while (j < k && arr[k] == arr[k + 1])
						k--;
				}
			}
		}
		return ans;
	}
};

	int main() {
		vector<int> arr ={-1, -1, 2, 0, 1};
		int arrSize = arr.size();

//		ThreeSum sum;
		vector<vector<int>> threeSumPair = ThreeSum::threeSum(arr ,arrSize );
		vector<vector<int>> threeSumPairBetter = ThreeSumBetter::threeSum(arr ,arrSize );
		vector<vector<int>> ThreeSumOptimal = ThreeSumOptimal::threeSum(arr ,arrSize );
		for(auto & i : ThreeSumOptimal){
			for(int j=0;j<3;j++){
				cout<<i[j]<<" ";
			}
			cout<<endl;
		}

	}