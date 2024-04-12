//
// Created by Gaurav Kesh Roushan on 11/04/24.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Brute {
public:
	static vector<int> brute(vector<int> &arr, int sizeArr) {
		vector<int> list;
		int minRepeat = (sizeArr / 3 +1);
		for (int i = 0; i < sizeArr; i++) {
			if (list.empty() || list[i] != arr[i]) {
				int count = 0;
				for (int j = 0; j < sizeArr; j++) {
					if (arr[i] == arr[j]) {
						count++;
					}
				}
				if (count >= minRepeat) {
					list.push_back(arr[i]);
				}
			}
			if (list.size() == minRepeat - 1) break;
		}
		return list;
	}
};

class Better {
public:
	static vector<int> better(vector<int> &arr, int sizeArr) {
		vector<int> list;
		int minRepeat = (sizeArr / 3 + 1);
		map<int, int> mpp;
		for (int i = 0; i < sizeArr; i++) {
			mpp[arr[i]]++;
			if (mpp[arr[i]] == minRepeat) {
				list.push_back(arr[i]);
			}
		}
		return list;
	}
};

class Optimal {
public:
	static vector<int> optimal(vector<int> &arr, int sizeArr) {
		int ele1 = INT_MIN;
		int ele2 = INT_MIN;
		int count1 = 0;
		int count2 = 0;
		for (int i = 0; i < sizeArr; i++) {
			if (count1 == 0 && ele2 != arr[i]) {
				count1 = 1;
				ele1 = arr[i];
			} else if (count2 == 0 && ele1 != arr[i]) {
				count2 = 1;
				ele2 = arr[i];
			}
			else if(ele1 == arr[i]) count1++;
			else if(ele2 == arr[i]) count2++;
			else{
				count1--,count2--;

			}

		}
		// manual check...
		vector<int> ls;
		count1 =0 ,count2=0;
		for(int i=0;i<sizeArr;i++){
			if(arr[i] == ele1) count1++;
			if(arr[i] == ele2) count2++;
		}

		int mini =( sizeArr/3)+1;
		if(count1>=mini) ls.push_back(ele1);
		if(count2>=mini) ls.push_back(ele2);
		sort(ls.begin(),ls.end());

		return ls;

	}
};


int main() {
	vector<int> arr = {2,2};
	int arrSize = arr.size();
//	Brute brute
//	vector<int> listBrute = Brute::brute(arr, arrSize);
//	vector<int> listBetter = Better::better(arr, arrSize);
	vector<int> listOptimal = Optimal::optimal(arr, arrSize);

	for (auto it: listOptimal) {
		cout << it;
		cout << endl;
	}

}
