//
// Created by Gaurav Kesh Roushan on 25/03/26.
//
class Solution {
public:
	string convert(string s, int numRows) {
		int n = s.size();
		if(numRows==1 && n>numRows){
			return s;
		}
		vector<string> a(numRows);
		int curr=0;
		int dir =1;
		for(char c:s){
			if(curr==0) dir=1;
			a[curr]+=c;
			if(curr==numRows-1) dir=-1;
			curr+=dir;
		}
		string res = "";
		for (auto &r : a) res += r;
		return res;
	}
};