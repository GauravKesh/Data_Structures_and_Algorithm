//
// Created by Gaurav Kesh Roushan on 13/04/24.
//
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Brute {
public:
	static vector<vector<int>> brute(vector<int> &arr, int arrSize, int target) {
		int n = arr.size();
		set<vector<int>> st;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					for (int l = k + 1; l < n; l++) {
						long long sum = arr[i] + arr[j];
						sum += arr[k];
						sum += arr[l];
						if (sum == target) {
							vector<int> newArr = {arr[i], arr[j], arr[k], arr[l]};
							sort(newArr.begin(), newArr.end());
							st.insert(newArr);
						}
					}
				}
			}
		}
		vector<vector<int>> outArr(st.begin(), st.end());
		return outArr;
	}
};

class Better {
public:
	static vector<vector<int>> better(vector<int> &arr, int arrSize, int target) {
		int n = arr.size();
		set<vector<int>> st;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				set<long long> hashSet;
				for (int k = j + 1; k < n; k++) {
					long long sum = arr[i] + arr[j];
					sum += arr[k];
					long long fourth = target - sum;
					if (hashSet.find(fourth) != hashSet.end()) {
						vector<int> temp = {arr[i], arr[j], arr[k], (int) fourth};
						sort(temp.begin(), temp.end());
						st.insert(temp);
					}
					hashSet.insert(arr[k]);

				}

			}
		}
		vector<vector<int>> outArr(st.begin(), st.end());


		return outArr;
	}
};

class Optimal {
public:
	static vector<vector<int>> optimal(vector<int> &arr, int n, int target) {
		sort(arr.begin(), arr.end());
//		int n =  arr.size();
		vector<vector<int>> vt;
		for (int i = 0; i < n; i++) {
			if (i > 0 && arr[i] == arr[i - 1]) continue;
			for (int j = i + 1; j < n; j++) {
				if (j > (i + 1) && arr[j] == arr[j - 1]) continue;
				int k = j + 1;
				int l = n - 1;
				while (k < l) {
					long long sum = arr[i];
					sum += arr[j];
					sum += arr[k];
					sum += arr[l];
					if (sum == target) {
						vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
						vt.push_back(temp);
						k++, l--;
						while(k<l && arr[k]==arr[k-1]) k++;
						while(k<l && arr[l]==arr[l+1]) l--;
					}
					else if (sum < target) {
						k++;
					}
					else {
						l--;
					}
				}
			}
		}
		return vt;
	}

};


int main() {
	vector<int> arr = {1, 0, -1, 0, -2, 2};
	int arrSize = arr.size();
	int target = 0;
	vector<vector<int>> bruteList = Brute::brute(arr, arrSize, target);
	vector<vector<int>> betterList = Better::better(arr, arrSize, target);
	vector<vector<int>> optimalList = Optimal::optimal(arr, arrSize, target);
	for (auto it: optimalList) {
		for (int i = 0; i < 4; i++) {
			cout << it[i] << " ";
		}
		cout << endl;
	}
}